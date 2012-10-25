#include "menu.h"

Menu::Menu()
{
}

bool
Menu::Init()
{
	try
	{
		this->__game = new Game;
		this->__context = new Lib2D::Context;
		this->__context_play = new Lib2D::Context;
		this->__context_card = new Lib2D::Context;
		this->__context_rule = new Lib2D::Context;
		this->__title = new Lib2D::Label;
		this->__title_card = new Lib2D::Label;
		this->__play = new Lib2D::Label_link;
		this->__card = new Lib2D::Label_link;
		this->__rule = new Lib2D::Label_link;
		this->__return = new Lib2D::Label_link;
//----->RULE
		this->__title_rule = new Lib2D::Label;
		this->__check_identical = new Lib2D::Button_check;
		this->__check_plus = new Lib2D::Button_check;
		this->__check_combo = new Lib2D::Button_check;
		this->__check_same_wall = new Lib2D::Button_check;
		this->__check_elementary = new Lib2D::Button_check;
		this->__check_open = new Lib2D::Button_check;
		this->__info_open = new Lib2D::Label;
		this->__check_random = new Lib2D::Button_check;
		this->__check_sudden_death = new Lib2D::Button_check;
		this->__check_victory_rule = new Lib2D::Button_check;
		this->__identical = new Lib2D::Label;
		this->__info_identical = new Lib2D::Label;
		this->__info_identical1 = new Lib2D::Label;
		this->__plus = new Lib2D::Label;
		this->__info_plus = new Lib2D::Label;
		this->__info_plus1 = new Lib2D::Label;
		this->__combo = new Lib2D::Label;
		this->__info_combo = new Lib2D::Label;
		this->__info_combo1 = new Lib2D::Label;
		this->__same_wall = new Lib2D::Label;
		this->__info_same_wall = new Lib2D::Label;
		this->__info_same_wall1 = new Lib2D::Label;
		this->__elementary = new Lib2D::Label;
		this->__info_elementary = new Lib2D::Label;
		this->__info_elementary1 = new Lib2D::Label;
		this->__info_elementary2 = new Lib2D::Label;
		this->__open = new Lib2D::Label;
		this->__random = new Lib2D::Label;
		this->__info_random = new Lib2D::Label;
		this->__sudden_death = new Lib2D::Label;
		this->__info_sudden_death = new Lib2D::Label;
		this->__info_sudden_death1 = new Lib2D::Label;
		this->__victory_rule = new Lib2D::Label;
		this->__info_victory_rule = new Lib2D::Label;
	}
	catch(...)
	{
		return false;
	}
	return true;
}
bool
Menu::Create_Menu(void)
{
	Lib2D::Window*		window;
	window = Lib2D::Window::get_instance();

	if (Init() == false)
		return false;
	if (Main_Menu() == false)
		return false;
	if(this->__game->init_board() == false)
		return false;
	if (Menu_Card() == false)
		return false;
	if (Menu_Rule() == false)
		return false;
	window->add_context(this->__context);
	window->add_context(this->__game->Get_Context());
	window->add_context(this->__context_card);
	window->add_context(this->__context_rule);
	return true;
}

bool
Menu::Main_Menu(void)
{
	this->__title->move(233, 50);
	this->__title->init("TRIPLE TRIAD", "res/finalf.ttf", 90, 0XFFFFFFFF, false);
	this->__play->move(365, 250);
	this->__play->init("PLAY", "res/finalf.ttf", 50, 1, 0XFFFFFFFF, false);
	this->__card->move(360, 325);
	this->__card->init("CARDS", "res/finalf.ttf", 50, 2, 0XFFFFFFFF, false);	
	this->__rule->move(360, 400);
	this->__rule->init("RULES", "res/finalf.ttf", 50, 3, 0XFFFFFFFF, false);	
	this->__return->move(360, 700);
	this->__return->init("RETURN", "res/finalf.ttf", 32, 0, 0XFFFFFFFF, false);
	this->__context->add_child(this->__title);
	this->__context->add_child(this->__play);
	this->__context->add_child(this->__card);
	this->__context->add_child(this->__rule);
	return true;
	
}
/*
Lib2D::Context*
Menu::Menu_Play(void)
{

	Game	game;
	if (game.init_board() == false)
		return false;
//	this->__context_play->add_child(this->__return);
	return game.Get_Context();
}
*/
bool
Menu::Menu_Card(void)
{
	this->__title_card->move(328, 50);
	this->__title_card->init("CARDS", "res/finalf.ttf", 90, 0XFFFFFFFF, false);

	this->__context_card->add_child(this->__title_card);
	this->__context_card->add_child(this->__return);
	return true;
}

bool
Menu::Menu_Rule(void)
{
	this->__title_rule->move(328, 50);
	this->__title_rule->init("RULES", "res/finalf.ttf", 90, 0XFFFFFFFF, false);

	this->__identical->move(75, 200);
	this->__identical->init("IDENTICAL: ", "res/finalf.ttf", 40, 0XFFFFFFFF, false);
	this->__check_identical->resize(40, 40);
	this->__check_identical->move(250, 200);
	this->__check_identical->init(true, false);
	this->__info_identical->move(300, 210);
	this->__info_identical->init("the identical rules return the cards with the same values on at", "res/origin.ttf", 11, 0XFFFFFFFF, false);
	this->__info_identical1->move(300, 225);
	this->__info_identical1->init("least two sides. Cards that have numbers in common are returned. ", "res/origin.ttf", 11, 0XFFFFFFFF, false);

	this->__plus->move(75, 250);
	this->__plus->init("PLUS: ", "res/finalf.ttf", 40, 0XFFFFFFFF, false);
	this->__check_plus->resize(40, 40);
	this->__check_plus->move(250, 250);
	this->__check_plus->init(true, false);
	this->__info_plus->move(300, 260);
	this->__info_plus->init("The plus rule returns cards with the addition of adjacent digits form", "res/origin.ttf", 11, 0XFFFFFFFF, false);
	this->__info_plus1->move(300, 275);
	this->__info_plus1->init("the same total at least 2 sides.", "res/origin.ttf", 11, 0XFFFFFFFF, false);

	this->__combo->move(75, 300);
	this->__combo->init("COMBO: ", "res/finalf.ttf", 40, 0XFFFFFFFF, false);
	this->__check_combo->resize(40, 40);
	this->__check_combo->move(250, 300);
	this->__check_combo->init(true, false);
	this->__info_combo->move(300, 310);
	this->__info_combo->init("Use rule Identical and Plus. This combination of rules can run", "res/origin.ttf", 11, 0XFFFFFFFF, false);
	this->__info_combo1->move(300, 325);
	this->__info_combo1->init("many cards (chain reaction) because it uses two ways to win.", "res/origin.ttf", 11, 0XFFFFFFFF, false);

	this->__same_wall->move(75, 350);
	this->__same_wall->init("SAME WALL: ", "res/finalf.ttf", 40, 0XFFFFFFFF, false);
	this->__check_same_wall->resize(40, 40);
	this->__check_same_wall->move(250, 350);
	this->__check_same_wall->init(true, false);
	this->__info_same_wall->move(300, 360);
	this->__info_same_wall->init("This rule uses the edges of the mat as a value card As.", "res/origin.ttf", 11, 0XFFFFFFFF, false);
	this->__info_same_wall1->move(300, 375);
	this->__info_same_wall1->init("It is very convenient with Identical and Plus.", "res/origin.ttf", 11, 0XFFFFFFFF, false);

	this->__elementary->move(75, 400);
	this->__elementary->init("ELEMENTARY: ", "res/finalf.ttf", 40, 0XFFFFFFFF, false);
	this->__check_elementary->resize(40, 40);
	this->__check_elementary->move(250, 400);
	this->__check_elementary->init(true, false);
	this->__info_elementary->move(300, 400);
	this->__info_elementary->init("Some cards have an elementary. This rule allows you to increase", "res/origin.ttf", 11, 0XFFFFFFFF, false);
	this->__info_elementary1->move(300, 415);
	this->__info_elementary1->init("your card 1 point if you put the card in his element.", "res/origin.ttf", 11, 0XFFFFFFFF, false);
	this->__info_elementary2->move(300, 430);
	this->__info_elementary2->init("By against, you lose a point if you put on another element.", "res/origin.ttf", 11, 0XFFFFFFFF, false);

	this->__open->move(75, 450);
	this->__open->init("OPEN: ", "res/finalf.ttf", 40, 0XFFFFFFFF, false);
	this->__check_open->resize(40, 40);
	this->__check_open->move(250, 450);
	this->__check_open->init(true, false);
	this->__info_open->move(300, 465);
	this->__info_open->init("During the game, you see all cards that your opponent uses.", "res/origin.ttf", 11, 0XFFFFFFFF, false);

	this->__random->move(75, 500);
	this->__random->init("RANDOM: ", "res/finalf.ttf", 40, 0XFFFFFFFF, false);
	this->__check_random->resize(40, 40);
	this->__check_random->move(250, 500);
	this->__check_random->init(true, false);
	this->__info_random->move(300, 515);
	this->__info_random->init("Cards you play during the game are randomly selected.", "res/origin.ttf", 11, 0XFFFFFFFF, false);

	this->__sudden_death->move(75, 550);
	this->__sudden_death->init("SUDDEN DEATH: ", "res/finalf.ttf", 40, 0XFFFFFFFF, false);
	this->__check_sudden_death->resize(40, 40);
	this->__check_sudden_death->move(250, 550);
	this->__check_sudden_death->init(true, false);
	this->__info_sudden_death->move(300, 560);
	this->__info_sudden_death->init("In case of a tie, you have to start the game.", "res/origin.ttf", 11, 0XFFFFFFFF, false);
	this->__info_sudden_death1->move(300, 575);
	this->__info_sudden_death1->init("The game stops when one of the two player loses the game.", "res/origin.ttf", 11, 0XFFFFFFFF, false);

	this->__victory_rule->move(75, 600);
	this->__victory_rule->init("VICTORY RULE: ", "res/finalf.ttf", 40, 0XFFFFFFFF, false);
	this->__check_victory_rule->resize(40, 40);
	this->__check_victory_rule->move(250, 600);
	this->__check_victory_rule->init(true, false);
	this->__info_victory_rule->move(300, 615);
	this->__info_victory_rule->init("At the end of a game, the winner gets a card.", "res/origin.ttf", 11, 0XFFFFFFFF, false);

	this->__context_rule->add_child(this->__title_rule);
	this->__context_rule->add_child(this->__identical);
	this->__context_rule->add_child(this->__check_identical);
	this->__context_rule->add_child(this->__info_identical);
	this->__context_rule->add_child(this->__info_identical1);
	this->__context_rule->add_child(this->__plus);
	this->__context_rule->add_child(this->__info_plus);
	this->__context_rule->add_child(this->__info_plus1);
	this->__context_rule->add_child(this->__check_plus);
	this->__context_rule->add_child(this->__combo);
	this->__context_rule->add_child(this->__info_combo);
	this->__context_rule->add_child(this->__info_combo1);
	this->__context_rule->add_child(this->__check_combo);
	this->__context_rule->add_child(this->__same_wall);
	this->__context_rule->add_child(this->__info_same_wall);
	this->__context_rule->add_child(this->__info_same_wall1);
	this->__context_rule->add_child(this->__check_same_wall);
	this->__context_rule->add_child(this->__elementary);
	this->__context_rule->add_child(this->__info_elementary);
	this->__context_rule->add_child(this->__info_elementary1);
	this->__context_rule->add_child(this->__info_elementary2);
	this->__context_rule->add_child(this->__check_elementary);
	this->__context_rule->add_child(this->__open);
	this->__context_rule->add_child(this->__check_open);
	this->__context_rule->add_child(this->__info_open);
	this->__context_rule->add_child(this->__random);
	this->__context_rule->add_child(this->__info_random);
	this->__context_rule->add_child(this->__check_random);
	this->__context_rule->add_child(this->__sudden_death);
	this->__context_rule->add_child(this->__info_sudden_death);
	this->__context_rule->add_child(this->__info_sudden_death1);
	this->__context_rule->add_child(this->__check_sudden_death);
	this->__context_rule->add_child(this->__victory_rule);
	this->__context_rule->add_child(this->__info_victory_rule);
	this->__context_rule->add_child(this->__check_victory_rule);
	this->__context_rule->add_child(this->__return);

	return true;
}
