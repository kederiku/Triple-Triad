#ifndef __CARD_H__
#define __CARD_H__

#include "include/Lib2D.h"

struct	t_pos
{
	int	x;
	int	y;
};

struct	t_value
{
	unsigned int	up;
	unsigned int	down;
	unsigned int	left;
	unsigned int	right;
};

class	Card
{
	private:
	t_pos*		__pos;
	t_value*	__value;
	Lib2D::Image*	__card;

	public:
			Card(void);
			~Card(void);
	Lib2D::Image*	get_card(void);
	bool		init_card(t_pos pos, t_value value, t_pos pos_image);
};

#endif
