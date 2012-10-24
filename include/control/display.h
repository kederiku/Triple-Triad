#ifndef __LIB2D_DISPLAY__
#define __LIB2D_DISPLAY__

#include "../control.h"
#include "surface.h"
#include "display/color.h"
#include "../window/window.h"
#include "../graphics/graphics.h"

namespace	Lib2D
{
	class	Display: public Lib2D::Control
	{
		private:
			float	__alpha;
			float	__scale_x;
			float	__scale_y;
			float	__rotate;
		protected:
			Lib2D::Surface	_surface;
			size_t		_border_size;
			Color		_border_color;
		protected:
			virtual bool	_apply_border(void);
		public:
						Display(void);
						Display(const Display& right);
			virtual			~Display(void);
			Display&		operator=(const Display& right);
			virtual void		move(int x, int y) = 0;
			virtual void		resize(size_t w, size_t h) = 0;
			virtual bool		add_child(Control* child) = 0;
			virtual bool		add_child(Control* child, size_t index) = 0;
			virtual bool		del_child(Control* child) = 0;
			virtual bool		del_child(size_t index) = 0;
			virtual bool		del_child(void) = 0;
			virtual bool		rmv_child(Control* child) = 0;
			virtual bool		rmv_child(size_t index) = 0;
			virtual bool		rmv_child(void) = 0;
			virtual const Control*	get_child(size_t index) const = 0;
			virtual const Control*	get_child(void) const = 0;
			virtual bool		dispatch(Lib2D::Event* event) = 0;
			virtual bool		end_of_dispatch(Lib2D::Event* event);
			virtual bool		out_of_range(Lib2D::Event* event);
			virtual bool		render(void) = 0;
			virtual bool		treat_event(Lib2D::Event* event) = 0;
			virtual bool		treat_render(void) = 0;
			virtual bool		derived_treat_event(Lib2D::Event* event);
			virtual bool		derived_treat_render(void);
			virtual Lib2D::Surface&	get_surface_ref(void);
			virtual Lib2D::Surface*	get_surface_ptr(void);
			virtual void		set_border(size_t border, const Lib2D::Color& color);
			virtual size_t		get_border_size(void) const;
			virtual Lib2D::Color&	get_color_ref(void);
			virtual Lib2D::Color*	get_color_ptr(void);
			virtual void		set_color(const Lib2D::Color& color);
			virtual void		set_color(int r, int g, int b, int a = 0xff);
	};
}

#endif
