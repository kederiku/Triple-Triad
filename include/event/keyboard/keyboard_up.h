#ifndef __LIB2D_KEYBOARD_UP__
#define __LIB2D_KEYBOARD_UP__

#include "../keyboard_event.h"

namespace	Lib2D
{
	class	Keyboard_up: public Keyboard_event
	{
		public:
					Keyboard_up(void);
					Keyboard_up(const Keyboard_up& right);
			virtual		~Keyboard_up(void);
			Keyboard_up&	operator=(const Keyboard_up& right);
	};
}

#endif
