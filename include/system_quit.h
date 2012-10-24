#ifndef __LIB2D_SYSTEM_QUIT__
#define __LIB2D_SYSTEM_QUIT__

#include "system_event.h"

namespace	Lib2D
{
	class	System_quit: public System_event
	{
		public:
					System_quit(void);
					System_quit(const System_quit& right);
			virtual		~System_quit(void);
			System_quit&	operator=(const System_quit& right);
#ifdef D_SDL
			virtual void	set_event(SDL_Event& event);
#elif D_LIB
			// etc...
#endif
	};
}

#endif
