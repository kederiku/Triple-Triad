#ifndef __LIB2D_MONO__
#define __LIB2D_MONO__

#include "display.h"

namespace	Lib2D
{
	class	Mono: public Lib2D::Display
	{
		protected:
			Lib2D::Control*	_child;
		public:
							Mono(void);
							Mono(const Mono& right);
			virtual				~Mono(void);
			Mono&				operator=(const Mono& right);
			virtual void			context_loaded(void);
			virtual void			move(int x, int y);
			virtual void			resize(size_t w, size_t h);
			virtual bool			add_child(Control* child);
			virtual bool			add_child(Control* child, size_t index);
			virtual bool			del_child(Control* child);
			virtual bool			del_child(size_t index);
			virtual bool			del_child(void);
			virtual bool			rmv_child(Control* child);
			virtual bool			rmv_child(size_t index);
			virtual bool			rmv_child(void);
			virtual const Lib2D::Control*	get_child(size_t index) const;
			virtual const Lib2D::Control*	get_child(void) const;
			virtual size_t			children(void) const;
			virtual bool			dispatch(Lib2D::Event* event);
			virtual bool			render(void);
			virtual void			cleaner(void);
	};
}

#endif
