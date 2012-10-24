#ifndef __LIB2D_SYSTEM_RESIZE__
#define __LIB2D_SYSTEM_RESIZE__

#include "../system_event.h"

namespace	Lib2D
{
	struct	s_system_resize
	{
		int	w;
		int	h;
	};
	class	System_resize: public System_event
	{
		private:
			s_system_resize	__system_resize;
		public:
					System_resize(void);
					System_resize(const System_resize& right);
			virtual		~System_resize(void);
			System_resize&	operator=(const System_resize& right);
#ifdef D_SDL
			virtual void	set_event(SDL_Event& event);
#elif D_LIB
		// etc...
#endif
	};
}

#endif
