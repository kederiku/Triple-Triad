#include "menu.h"

Menu::Menu()
{

}

bool
Menu::Init()
{
	Lib2D::Window*		window;
	window = Lib2D::Window::get_instance();

	try
	{
		this->__context = new Lib2D::Context;
		this->__context_play = new Lib2D::Context;
		this->__context_card = new Lib2D::Context;
		this->__context_rule = new Lib2D::Context;
		this->__title = new Lib2D::Label;
		this->__play = new Lib2D::Label_link;
		this->__card = new Lib2D::Label_link;
		this->__rule = new Lib2D::Label_link;
		this->__return = new Lib2D::Label_link;
	}
	catch(...)
	{
		return false;
	}

	this->__title->move(233, 50);
	this->__title->init("TRIPLE TRIAD", "finalf.ttf", 90, 0XFFFFFFFF, false);
	this->__play->move(365, 250);
	this->__play->init("PLAY", "finalf.ttf", 50, 1, 0XFFFFFFFF, false);	
	this->__card->move(360, 325);
	this->__card->init("CARDS", "finalf.ttf", 50, 2, 0XFFFFFFFF, false);	
	this->__rule->move(360, 400);
	this->__rule->init("RULES", "finalf.ttf", 50, 3, 0XFFFFFFFF, false);	
	this->__return->move(360, 700);
	this->__return->init("RETURN", "finalf.ttf", 50, 0, 0XFFFFFFFF, false);	

	this->__context->add_child(this->__title);
	this->__context->add_child(this->__play);
	this->__context->add_child(this->__card);
	this->__context->add_child(this->__rule);

	this->__context_play->add_child(this->__return);
	this->__context_card->add_child(this->__return);
	this->__context_rule->add_child(this->__return);

	window->add_context(this->__context);
	window->add_context(this->__context_play);
	window->add_context(this->__context_card);
	window->add_context(this->__context_rule);
	return true;
}
