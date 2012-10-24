#ifndef __LIB2D_HBOX__
#define __LIB2D_HBOX__

#include "../box.h"

namespace	Lib2D
{
	class	Hbox: public Box
	{
		protected:
			virtual void	_apply_spacing(int i);
			virtual void	_apply_homogeneity(void);
			virtual void	_apply_expandable(bool expandable);
			virtual void	_put_child(void);
		public:
					Hbox(void);
					Hbox(const Hbox& right);
			virtual		~Hbox(void);
			Hbox&		operator=(const Hbox& right);
			virtual bool	add_child(Lib2D::Control* child, e_box_alignment alignment = LEFT_ALIGNMENT, bool expandable = false);
	};
}

#endif
