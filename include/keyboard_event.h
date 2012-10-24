#ifndef __LIB2D_KEYBOARD_EVENT__
#define __LIB2D_KEYBOARD_EVENT__

#include "event.h"
#include "key_code.h"

namespace	Lib2D
{
	enum	e_key_state
	{
		E_KEY_PRESSED = 0,
		E_KEY_RELEASED
	};
	struct	s_key_event
	{
		e_key_code	code;
		e_key_name	name;
		e_key_state	state;
		bool		alt;
		bool		control;
		bool		shift;
		bool		caps;
	};
	class	Keyboard_event: public Event
	{
		protected:
			s_key_event	_key_event;
		public:
							Keyboard_event(Lib2D::e_event_type type);
							Keyboard_event(const Keyboard_event& right);
			virtual				~Keyboard_event(void);
			Keyboard_event&			operator=(const Keyboard_event& right);
#ifdef D_SDL
			virtual void			set_event(SDL_Event& event);
#elif D_LIB
			// etc...
#endif
			virtual const s_key_event*	get_key_event(void) const;
			int				get_key_char(void);
			int				convert_key_name(void);
			int				convert_pavnum(void);
	};
}

#endif
