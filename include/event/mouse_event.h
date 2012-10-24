#ifndef __LIB2D_MOUSE_EVENT__
#define __LIB2D_MOUSE_EVENT__

#include "event.h"

namespace	Lib2D
{
	enum	e_mouse_button
	{
		E_BUTTON_LEFT = 0,
		E_BUTTON_RIGHT,
		E_BUTTON_MIDDLE,
		E_BUTTON_MIDDLEUP,
		E_BUTTON_MIDDLEDOWN
	};
	struct	s_mouse_event
	{
		e_mouse_button	button;
		int		delta;
		unsigned int	state;
		int		x;
		int		y;
	};
	class	Mouse_event: public Event
	{
		protected:
			s_mouse_event	_mouse_event;
		public:
							Mouse_event(Lib2D::e_event_type type);
							Mouse_event(const Mouse_event& right);
			virtual				~Mouse_event(void);
			Mouse_event&			operator=(const Mouse_event& right);
#ifdef D_SDL
			virtual void			set_event(SDL_Event& event);
#elif D_LIB
			// etc...
#endif
			virtual const s_mouse_event*	get_mouse_event(void) const;
	};
}

#endif
