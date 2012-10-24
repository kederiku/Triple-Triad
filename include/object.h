#ifndef __LIB2D_OBJECT__
#define __LIB2D_OBJECT__

#include "display.h"

namespace	Lib2D
{
	class	Object: public Lib2D::Display
	{
		public:
							Object(void);
							Object(const Object& right);
			virtual				~Object(void);
			Object&				operator=(const Object& right);
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
