#ifndef __LIB2D_MULTI__
#define __LIB2D_MULTI__

#include "../display.h"
#include <list>

namespace	Lib2D
{
	class	Multi: public Lib2D::Display
	{
		protected:
			t_control_list	_children;
		public:
							Multi(void);
							Multi(const Multi& right);
			virtual				~Multi(void);
			Multi&				operator=(const Multi& right);
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
			virtual bool			treat_event(Lib2D::Event* event) = 0;
			virtual bool			treat_render(void) = 0;
			virtual void			cleaner(void);
	};
}

#endif
