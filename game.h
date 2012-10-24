#ifndef __GAME_H__
#define __GAME_H__

#include "card.h"

class	Game : public Lib2D::Container
{
	private:
	Lib2D::Context*		__context;
	Lib2D::Label*		__playerone;
	Lib2D::Label*		__playertow;
	Lib2D::Label_link*	__pvp;
	Lib2D::Label_link*	__pvc;

	public:
	Game(void);
	~Game(void);
	void	init_menu(void);
};

#endif
