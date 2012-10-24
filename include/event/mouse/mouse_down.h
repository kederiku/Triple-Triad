#ifndef __LIB2D_MOUSE_DOWN__
#define __LIB2D_MOUSE_DOWN__

#include "../mouse_event.h"

namespace	Lib2D
{
	class	Mouse_down: public Mouse_event
	{
		public:
					Mouse_down(void);
					Mouse_down(const Mouse_down& right);
			virtual		~Mouse_down(void);
			Mouse_down&	operator=(const Mouse_down& right);
	};
}

#endif
