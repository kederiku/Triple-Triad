#ifndef __LIB2D_SYSTEM_CONTEXT_SWITCH__
#define __LIB2D_SYSTEM_CONTEXT_SWITCH__

#include "../system_event.h"

namespace	Lib2D
{
	class	System_context_switch: public System_event
	{
		public:
						System_context_switch(void);
						System_context_switch(const System_context_switch& right);
			virtual			~System_context_switch(void);
			System_context_switch&	operator=(const System_context_switch& right);
#ifdef D_SDL
			virtual void		set_event(SDL_Event& event);
#elif D_LIB
			// etc...
#endif
	};
}

#endif
