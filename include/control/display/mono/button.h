#ifndef __LIB2D_BUTTON__
#define __LIB2D_BUTTON__

#include "../mono.h"
#include "../../rect.h"
#include "../../surface.h"

namespace	Lib2D
{
	class	Button: public Lib2D::Mono
	{
		public:
			enum	e_button_state
			{
				E_BUTTON_UNCLICK = 0,
				E_BUTTON_CLICK,
				E_BUTTON_FOCUS
			};
		protected:
			size_t		_right_corner;
			size_t		_left_corner;
			size_t		_background;
			size_t		_color_border;
			bool		_border;
			bool		_focus;
			e_button_state	_state;
		protected:
			bool		_draw_rectangle(int x, int y, size_t w,
							size_t h, size_t color);
			bool		_create_button_focus(void);
			bool		_create_button_simple(void);
			bool		_create_button(void);
		public:
						Button(void);
						Button(const Button& right);
			virtual			~Button(void);
			Button&			operator=(const Button& right);
			bool			init(bool focus = true, bool border = false,
						     size_t right_corner = 0x393939ff,
						     size_t left_corner = 0xd1d1d1ff,
						     size_t background = 0x989898ff,
						     size_t color_border = 0xff0000ff);
			virtual bool		treat_event(Lib2D::Event* event);
			virtual bool		treat_render(void);
			virtual e_button_state	get_state(void) const;
			virtual void		set_right_corner(size_t color = 0x393939ff);
			virtual void		set_left_corner(size_t color = 0xd1d1d1ff);
			virtual	void		set_background(size_t bg = 0x989898ff);
	};
}

#endif
