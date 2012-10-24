#ifndef __LIB2D_TABLE_H__
#define __LIB2D_TABLE_H__

#include "../multi.h"
#include "container.h"

namespace	Lib2D
{
	class	Table: public Lib2D::Multi
	{
		protected:
			unsigned int		_row;
			unsigned int		_col;
			unsigned int		_container_w;
			unsigned int		_container_h;
			unsigned int		_spacing;

		public:
						Table(void);
						Table(const Table& right);
			virtual			~Table(void);
			Table&			operator=(const Table& right);
			virtual bool		init(unsigned int row, unsigned int col, unsigned int spacing = 0);
			virtual bool		add_child(Lib2D::Control* child, unsigned int row, unsigned int col);
			virtual	bool		del_child(unsigned int row, unsigned int col, unsigned int index);
			virtual bool		move_child(unsigned int old_row, unsigned int old_col, unsigned int old_index, unsigned int new_row, unsigned int new_col, unsigned int new_index);
			virtual bool		move_childs(unsigned int old_row, unsigned int old_col, unsigned int new_row, unsigned int new_col);
			virtual	bool		switch_child(unsigned int first_row, unsigned int first_col, unsigned int first_index, unsigned int second_row, unsigned int second_col, unsigned int second_index);
			virtual bool		treat_event(Lib2D::Event* event);
			virtual bool		treat_render(void);
			virtual unsigned int	get_child_requested_w(void) const;
			virtual unsigned int	get_child_requested_h(void) const;
			virtual	bool		find_child_place(Lib2D::Control* child, unsigned int index, unsigned int& x, unsigned int& y);
	};
}

#endif
