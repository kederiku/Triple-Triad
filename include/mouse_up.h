#ifndef __LIB2D_MOUSE_UP__
#define __LIB2D_MOUSE_UP__

#include "mouse_event.h"

namespace	Lib2D
{
	class	Mouse_up: public Mouse_event
	{
		public:
					Mouse_up(void);
					Mouse_up(const Mouse_up& right);
			virtual		~Mouse_up(void);
			Mouse_up&	operator=(const Mouse_up& right);
	};
}

#endif
