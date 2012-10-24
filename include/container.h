#ifndef __LIB2D_CONTAINER__
#define __LIB2D_CONTAINER__

#include "multi.h"

namespace	Lib2D
{
	class	Container: public Lib2D::Multi
	{
		protected:
			bool	_draw_background(void);
		public:
					Container(void);
					Container(const Container& right);
			virtual		~Container(void);
			Container&	operator=(const Container& right);
			virtual bool	init(void);
			virtual bool	treat_event(Lib2D::Event* event);
			virtual bool	treat_render(void);
	};
}

#endif
