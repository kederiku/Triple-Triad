#ifndef __MENU_H__
#define __MENU_H__

#include "include/Lib2D.h"

class Menu
{
private:
	Lib2D::Label*		__title;
	Lib2D::Label_link*	__play;
	Lib2D::Label_link*	__rule;
	Lib2D::Label_link*	__card;
	Lib2D::Label_link*	__return;
	Lib2D::Context*		__context;
	Lib2D::Context*		__context_play;
	Lib2D::Context*		__context_card;
	Lib2D::Context*		__context_rule;

public:
		Menu();
	bool	Init();
};

#endif
