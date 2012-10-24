#ifndef __LIB2D_KEYBOARD_DOWN__
#define __LIB2D_KEYBOARD_DOWN__

#include "../keyboard_event.h"

namespace	Lib2D
{
	class	Keyboard_down: public Keyboard_event
	{
		public:
					Keyboard_down(void);
					Keyboard_down(const Keyboard_down& right);
			virtual		~Keyboard_down(void);
			Keyboard_down&	operator=(const Keyboard_down& right);
	};
}

#endif
