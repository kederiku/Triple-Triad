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

struct	t_info
{
	t_pos	pos;
	t_value	value;
	int	num;
	bool	is_clickable;
};

class	Card
{
	private:
	Lib2D::Image*	__card;
	t_value		__valadj;
	t_info		__info;

	public:
			Card(void);
			~Card(void);
	Lib2D::Image*	get_card(void);
	bool		init_card(t_pos pos, t_value value, t_pos pos_image, int num);
	t_pos*		get_pos(void);
	t_value*	get_value(void);
	void		set_pos(t_pos);
	int		get_num(void);
	t_info*		get_info(void);
	t_value*	get_valadj(void);
};

#endif
