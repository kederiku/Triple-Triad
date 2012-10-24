#include <iostream>
#include <SDL/SDL.h>
#include "include/Lib2D.h"
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
	uint			flags;
	Lib2D::Engine		engine;
	Menu			menu;

	flags = Lib2D::E_HARDWARE;
	if (engine.init() == false)
		return error("could not init Lib2D", engine);
	if (engine.init_main_window(800, 800, 32, flags) == false)
		return error("could not init main window", engine);
	try
	{
		menu.Init();
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
