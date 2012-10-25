#include <iostream>
#include <SDL/SDL.h>
#include "include/Lib2D.h"
//#include "game.h"
#include "menu.h"

int
error(const char* err, Lib2D::Engine& engine)
{
	m_error(err);
	engine.cleaner();
	return -1;
}

int
main(void)
{
	Lib2D::Engine		engine;
	Menu			menu;
//	Game			game;

	try
	{
		if (engine.init() == false)
			return error("could not init Lib2D", engine);
		if (engine.init_main_window(800, 800, 32, Lib2D::E_HARDWARE) == false)
			return error("could not init main window", engine);
		if(menu.Create_Menu() == false)
			return -1;
//		if (game.init_board() == false)
//			return error("game no init", engine);
		if (engine.run() == false)
			return error("program terminated unexpectedly", engine);
		engine.cleaner();
	}
	catch (...)
	{
		m_error("uber crash");
		return -1;
	}
	return 0;
}
