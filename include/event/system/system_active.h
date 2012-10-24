#ifndef __LIB2D_SYSTEM_ACTIVE__
#define __LIB2D_SYSTEM_ACTIVE__

#include "../system_event.h"

namespace	Lib2D
{
	enum	e_active_state
	{
		E_ACTIVE_MOUSE_FOCUS = 0,
		E_ACTIVE_INPUT_FOCUS,
		E_ACTIVE_APP
	};
	struct	s_active_event
	{
		unsigned int	gain;
		e_active_state	state;
	};
	class	System_active: public System_event
	{
		private:
			s_active_event	__active_event;
		public:
					System_active(void);
					System_active(const System_active& right);
			virtual		~System_active(void);
			System_active&	operator=(const System_active& right);
#ifdef D_SDL
			virtual void	set_event(SDL_Event& event);
#elif D_LIB
			// etc...
#endif
	};
}

#endif
