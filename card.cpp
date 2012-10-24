#include "card.h"

Card::Card(void)
{
	this->__pos = 0;
	this->__value = 0;
	this->__card = 0;
}

Card::~Card(void)
{
	if (this->__card)
		delete this->__card;
	if (this->__pos)
		delete this->__pos;
	if (this->__value)
		delete this->__value;
}

bool	Card::init_card(t_pos pos, t_value value, t_pos pos_image)
{
	Lib2D::Image	image;

	try
	{
		this->__pos = new t_pos;
		this->__value = new t_value;
		this->__card = new Lib2D::Image;
	}
	catch(...)
	{
		return false;
	}
	this->__pos->x = pos.x;
	this->__pos->y = pos.y;
	this->__value->up = value.up;
	this->__value->down = value.down;
	this->__value->left = value.left;
	this->__value->right = value.right;
	image.load_bmp("pictures/all.bmp");
	this->__card = image.get_image_part(pos_image.x, pos_image.y, 75, 100);
	if (this->__card == 0)
		return false;
	this->__card->resize(75, 100);
	this->__card->move(this->__pos->x, this->__pos->y);
	return true;
}

Lib2D::Image*	Card::get_card(void)
{
	return this->__card;
}
