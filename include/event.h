#ifndef __LIB2D_EVENTS__
#define __LIB2D_EVENTS__

#include <SDL/SDL.h>

namespace	Lib2D
{
	enum	e_event_type
	{
		E_KEYDOWN_EVENT = 0,
		E_KEYUP_EVENT,
		E_MOUSEMOTION_EVENT,
		E_MOUSEDOWN_EVENT,
		E_MOUSECLICK_EVENT,
		E_MOUSEUP_EVENT,
		E_VIDEORESIZE_EVENT,
		E_ACTIVE_EVENT,
		E_QUIT_EVENT,
		E_CONTEXT_SWITCH_EVENT
	};
	struct	s_mouse_event;
	struct	s_key_event;
	class	Event
	{
		private:
			e_event_type	__type;
		public:
					Event(e_event_type type);
					Event(const Event& right);
			virtual		~Event(void);
			Event&		operator=(const Event& right);
			e_event_type	get_type(void) const;
			void		set_type(e_event_type e);
#ifdef D_SDL
			static Event*	convert_event(SDL_Event& event);
			virtual void	set_event(SDL_Event& event) = 0;
#elif D_LIB
			// etc...
#endif
			virtual const s_mouse_event*	get_mouse_event(void) const;
			virtual const s_key_event*	get_key_event(void) const;
	};
}

#endif
