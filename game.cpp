#include "game.h"
//#include "menu.h"
Game::Game(void)
{
	this->__context = 0;
	this->__board = 0;
	this->__turnplayer = 0;
	this->__actualpos.x = 0;
	this->__actualpos.y = 0;
	this->__save_num_card = -1;
}

bool	Game::Run(void)
{
	if (init_board() == false)
		return false;
	return true;
}

Lib2D::Context*
Game::Get_Context(void)
{
	return this->__context;
}

bool	Game::init_board(void)
{
	Lib2D::Window*		window = Lib2D::Window::get_instance();
	if (window == NULL)
		return false;
	try
	{
		this->__context = new Lib2D::Context;
		this->__board = new Lib2D::Image;
	}
	catch(...)
	{
		return false;
	}
	this->__board->resize(650, 453);
	this->__board->move(76, 150);
	this->__board->load_bmp("res/board.bmp");
	this->resize(800, 800);
	this->move(0, 0);
	if (this->__board == 0)
		return false;
	std::cout << "B\n";
	this->add_child(this->__board);
	this->__context->add_child(this);
	std::cout << "C\n";
	std::cout << "D\n";
	this->make_cards();
	std::cout << "E\n";
	return true;
}

void	Game::set_values(t_pos* pos, t_value* value, t_pos* pos_image, int x, int y, int up, int down, int left, int right, int ximage, int yimage)
{
	pos->x = x;
	pos->y = y;
	value->up = up;
	value->down = down;
	value->left = left;
	value->right = right;
	pos_image->x = ximage;
	pos_image->y = yimage;
}

bool	Game::make_cards()
{
	int	i;
	t_pos	pos;
	t_value	value;
	t_pos	pos_image;

	i = 0;
	while (i < 10)
	{
		if (i == 0)
			this->set_values(&pos, &value, &pos_image, 0, 150, 8, 4, 4, 8, 75, 600);
		else if (i == 1)
			this->set_values(&pos, &value, &pos_image, 0, 250, 2, 9, 4, 9, 375, 700);
		else if (i == 2)
			this->set_values(&pos, &value, &pos_image, 0, 350, 8, 10, 4, 4, 0, 800);
		else if (i == 3)
			this->set_values(&pos, &value, &pos_image, 0, 450, 5, 3, 3, 6, 375, 200);
		else if (i == 4)
			this->set_values(&pos, &value, &pos_image, 0, 550, 6, 4, 7, 8, 600, 600);
		else if (i == 5)
			this->set_values(&pos, &value, &pos_image, 725, 150, 1, 8, 3, 8, 300, 500);
		else if (i == 6)
			this->set_values(&pos, &value, &pos_image, 725, 250, 8, 5, 8, 3, 375, 600);
		else if (i == 7)
			this->set_values(&pos, &value, &pos_image, 725, 350, 9, 4, 2, 10, 450, 800);
		else if (i == 8)
			this->set_values(&pos, &value, &pos_image, 725, 450, 1, 4, 8, 8, 600, 500);
		else if (i == 9)
			this->set_values(&pos, &value, &pos_image, 725, 550, 4, 7, 3, 8, 150, 500);
		this->__cards[i].init_card(pos, value, pos_image, i);
		this->add_child(this->__cards[i].get_card());
		this->__cards[i].get_card()->signals.add(Lib2D::make_func(this, &Game::move_card), 0, this->__cards[i].get_info());
		i++;
	}
	this->__board->signals.add(Lib2D::make_func(this, &Game::move_card), 0, 0);
	return true;
}

bool	Game::move_card(Lib2D::Control* control, void* data)
{
	t_pos	pos;
	t_info*	info;
	(void)control;

	info = (t_info*)data;
	if (info != 0)
	{
		if (this->__cards[info->num].get_info()->is_clickable == false)
			return false;
	}
	if (this->__save_num_card == -1)
	{
		if (info == 0)
			return false;
		if (info->pos.x != 0 && info->pos.x != 725)
			return false;
		this->__cards[info->num].get_info()->is_clickable = false;
		this->__save_num_card = info->num;
	}
	else
	{
		if (info != 0)
			return false;
		pos.x = 270;
		pos.y = 165;
		if (this->check_move(&pos) == false)
			return false;
		this->__cards[this->__save_num_card].get_card()->move(pos.x, pos.y);
		this->__cards[this->__save_num_card].set_pos(pos);
		if (this->check_coin() == false)
			return false;
		this->__save_num_card = -1;
	}
	return true;
}

bool	Game::check_move(t_pos* pos)
{
	int	i;

	i = 0;
	while (i < 9)
	{
		if (i != 0 && i % 3 == 0)
		{
			pos->x = 270;
			pos->y += 131;
		}
		if (this->__actualpos.x >= pos->x && this->__actualpos.x < pos->x + 86 &&
		    this->__actualpos.y >= pos->y && this->__actualpos.y < pos->y + 131)
			break;
		pos->x += 86;
		i++;
	}
	if (i == 9)
		return false;
	i = 0;
	while (i < 10)
	{
		if (pos->x == this->__cards[i].get_pos()->x && pos->y == this->__cards[i].get_pos()->y)
			return false;
		i++;
	}
	return true;
}

bool	Game::check_coin()
{
	t_pos	pos;
	int	i;

	pos = *this->__cards[this->__save_num_card].get_pos();
	pos.y -= 131;
	if (pos.y >= 165)
	{
		i = 0;
		while (i < 10)
		{
			if (pos.x == this->__cards[i].get_pos()->x && pos.y == this->__cards[i].get_pos()->y)
				break;
			i++;
		}
		if (i != 10)
			this->__cards[this->__save_num_card].get_valadj()->up = this->__cards[i].get_value()->down;
	}
	pos.y += 262;
	if (pos.y <= 427)
	{
		i = 0;
		while (i < 10)
		{
			if (pos.x == this->__cards[i].get_pos()->x && pos.y == this->__cards[i].get_pos()->y)
				break;
			i++;
		}
		if (i != 10)
			this->__cards[this->__save_num_card].get_valadj()->down = this->__cards[i].get_value()->up;
	}
	pos = *this->__cards[this->__save_num_card].get_pos();
	pos.x -= 86;
	if (pos.x >= 270)
	{
		i = 0;
		while (i < 10)
		{
			if (pos.x == this->__cards[i].get_pos()->x && pos.y == this->__cards[i].get_pos()->y)
				break;
			i++;
		}
		if (i != 10)
			this->__cards[this->__save_num_card].get_valadj()->left = this->__cards[i].get_value()->right;
	}
	pos.x += 86 * 2;
	if (pos.x <= 442)
	{
		i = 0;
		while (i < 10)
		{
			if (pos.x == this->__cards[i].get_pos()->x && pos.y == this->__cards[i].get_pos()->y)
				break;
			i++;
		}
		if (i != 10)
			this->__cards[this->__save_num_card].get_valadj()->right = this->__cards[i].get_value()->left;
	}
	return true;
}

bool	Game::derived_treat_event(Lib2D::Event* event)
{
	const Lib2D::s_mouse_event*	mouse;

	mouse = event->get_mouse_event();
	switch (event->get_type())
	{
		case Lib2D::E_CONTEXT_SWITCH_EVENT:
			break;
		case Lib2D::E_MOUSEDOWN_EVENT:
			this->__actualpos.x = mouse->x;
			this->__actualpos.y = mouse->y;
			std::cout << "actual: " << this->__actualpos.x << " " << this->__actualpos.y << std::endl;
			break;
		case Lib2D::E_MOUSEUP_EVENT:
			break;
		case Lib2D::E_MOUSEMOTION_EVENT:
			break;
		default:
			break;
	}
	return true;
}

