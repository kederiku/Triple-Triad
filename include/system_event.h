#ifndef __LIB2D_SYSTEM_EVENT__
#define __LIB2D_SYSTEM_EVENT__

#include "event.h"

namespace	Lib2D
{
	class	System_event: public Event
	{
		public:
					System_event(Lib2D::e_event_type type);
					System_event(const System_event& right);
			virtual		~System_event(void);
			System_event&	operator=(const System_event& right);
#ifdef D_SDL
			virtual void	set_event(SDL_Event& event) = 0;
#elif D_LIB
			// etc...
#endif
	};
}

#endif
