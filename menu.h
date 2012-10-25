#ifndef __MENU_H__
#define __MENU_H__

#include "include/Lib2D.h"
#include "game.h"

class Game;
class Menu
{
private:
	Game*			__game;

// -----> Main Menu
	Lib2D::Label*		__title;
	Lib2D::Label_link*	__play;
	Lib2D::Label_link*	__rule;
	Lib2D::Label_link*	__card;
	Lib2D::Label_link*	__return;
	Lib2D::Context*		__context;
	Lib2D::Context*		__context_play;
	Lib2D::Context*		__context_card;
	Lib2D::Context*		__context_rule;
// -----> Play Menu

// -----> Card Menu
	Lib2D::Label*		__title_card;
// -----> Rule Menu
	Lib2D::Label*		__title_rule;
	Lib2D::Label*		__identical;
	Lib2D::Label*		__info_identical;
	Lib2D::Label*		__info_identical1;
	Lib2D::Label*		__plus;
	Lib2D::Label*		__info_plus;
	Lib2D::Label*		__info_plus1;
	Lib2D::Label*		__combo;
	Lib2D::Label*		__info_combo;
	Lib2D::Label*		__info_combo1;
	Lib2D::Label*		__same_wall;
	Lib2D::Label*		__info_same_wall;
	Lib2D::Label*		__info_same_wall1;
	Lib2D::Label*		__elementary;
	Lib2D::Label*		__info_elementary;
	Lib2D::Label*		__info_elementary1;
	Lib2D::Label*		__info_elementary2;
	Lib2D::Label*		__open;
	Lib2D::Label*		__info_open;
	Lib2D::Label*		__random;
	Lib2D::Label*		__info_random;
	Lib2D::Label*		__sudden_death;
	Lib2D::Label*		__info_sudden_death;
	Lib2D::Label*		__info_sudden_death1;
	Lib2D::Label*		__victory_rule;
	Lib2D::Label*		__info_victory_rule;
	Lib2D::Button_check*	__check_identical;
	Lib2D::Button_check*	__check_plus;
	Lib2D::Button_check*	__check_combo;
	Lib2D::Button_check*	__check_same_wall;
	Lib2D::Button_check*	__check_elementary;
	Lib2D::Button_check*	__check_open;
	Lib2D::Button_check*	__check_random;
	Lib2D::Button_check*	__check_sudden_death;
	Lib2D::Button_check*	__check_victory_rule;



	bool	Init(void);
	bool	Main_Menu(void);
	Lib2D::Context*	Menu_Play(void);
	bool	Menu_Card(void);
	bool	Menu_Rule(void);
public:
		Menu();
	bool	Create_Menu(void);
};

#endif
