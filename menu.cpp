#include "menu.h"

Menu::Menu()
{

}

bool
Menu::Init()
{
	Lib2D::Label*		titre;
	Lib2D::Window*		window;
//	Lib2D::Label_link*	regle;
//	Lib2D::Label_link*	card;
	window = Lib2D::Window::get_instance();

	try
	{
		this->__context = new Lib2D::Context;
		titre = new Lib2D::Label;
//		regle = new Lib2D::Label_link;
//		card = new Lib2D::Label_link;
	}
	catch(...)
	{
		return false;
	}
	
	titre->move(250, 50);
	titre->init("Triple Triad", "optimus.ttf", 75, 0XFFFFFFFF, false);

	this->__context->add_child(titre);

	window->add_context(this->__context);
	return true;
}
