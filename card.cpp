#include "card.h"

Card::Card(void)
{
	this->__valadj.up = 0;
	this->__valadj.down = 0;
	this->__valadj.left = 0;
	this->__valadj.right = 0;
	this->__info.pos.x = 0;
	this->__info.pos.y = 0;
	this->__info.value.up = 0;
	this->__info.value.down = 0;
	this->__info.value.left = 0;
	this->__info.value.right = 0;
	this->__info.num = 0;
	this->__info.is_clickable = true;
	this->__card = 0;
}

Card::~Card(void)
{
	if (this->__card)
		delete this->__card;
}

bool	Card::init_card(t_pos pos, t_value value, t_pos pos_image, int num)
{
	Lib2D::Image	image;

	try
	{
		this->__card = new Lib2D::Image;
	}
	catch(...)
	{
		return false;
	}
	this->__info.pos = pos;
	this->__info.value = value;
	this->__info.num = num;
	image.load_bmp("res/tripletriadcards.bmp");
	this->__card = image.get_image_part(pos_image.x, pos_image.y, 75, 100);
	if (this->__card == 0)
		return false;
	this->__card->resize(75, 100);
	this->__card->move(this->__info.pos.x, this->__info.pos.y);
	return true;
}

Lib2D::Image*	Card::get_card(void)
{
	return this->__card;
}

t_pos*		Card::get_pos(void)
{
	return &this->__info.pos;
}

t_value*	Card::get_value(void)
{
	return &this->__info.value;
}

void		Card::set_pos(t_pos pos)
{
	this->__info.pos = pos;
}

int		Card::get_num(void)
{
	return this->__info.num;
}

t_info*		Card::get_info(void)
{
	return &this->__info;
}

t_value*	Card::get_valadj()
{
	return &this->__valadj;
}
