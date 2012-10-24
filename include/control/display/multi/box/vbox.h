#ifndef __LIB2D_VBOX__
#define __LIB2D_VBOX__

#include "../box.h"

namespace	Lib2D
{
	class	Vbox: public Box
	{
		protected:
			virtual void	_apply_spacing(int i);
			virtual void	_apply_homogeneity(void);
			virtual void	_apply_expandable(bool expandable);
			virtual void	_put_child(void);
		public:
					Vbox(void);
					Vbox(const Vbox& right);
			virtual		~Vbox(void);
			Vbox&		operator=(const Vbox& right);
			virtual bool	add_child(Lib2D::Control* child, e_box_alignment alignment = LEFT_ALIGNMENT, bool expandable = false);
	};
}

#endif
