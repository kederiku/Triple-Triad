#ifndef __LIB2D_MOUSE_MOTION__
#define __LIB2D_MOUSE_MOTION__

#include "mouse_event.h"

namespace	Lib2D
{
	class	Mouse_motion: public Mouse_event
	{
		public:
					Mouse_motion(void);
					Mouse_motion(const Mouse_motion& right);
			virtual		~Mouse_motion(void);
			Mouse_motion&	operator=(const Mouse_motion& right);
	};
}

#endif
