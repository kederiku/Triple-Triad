#ifndef __GAME_H__
#define __GAME_H__

#include "card.h"
#include "menu.h"

class	Game : public Lib2D::Container
{
	private:
	Lib2D::Context*		__context;
	t_pos			__actualpos;
	Card			__cards[10];
	int			__save_num_card;
	Lib2D::Label_link*	__turnplayer;
	Lib2D::Image*		__board;

	public:
	Game(void);
	bool	Run(void);
	Lib2D::Context*	Get_Context(void);
	bool	init_board();
	void	set_values(t_pos* pos, t_value* value, t_pos* pos_image, int x, int y, int up, int down, int left, int right, int ximage, int yimage);
	bool	make_cards();
	bool	derived_treat_event(Lib2D::Event* event);
	bool	move_card(Lib2D::Control* control, void* data);
	bool	check_move(t_pos* pos);
	bool	check_coin(void);
};

#endif
