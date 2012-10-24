#ifndef __LIB2D_DAREA__
#define __LIB2D_DAREA__

#include "../object.h"

namespace	Lib2D
{
	class	Darea: public Lib2D::Object
	{
		private:
			Lib2D::Surface	__scale;
		public:
					Darea(void);
					Darea(const Darea& right);
			virtual		~Darea(void);
			Darea&		operator=(const Darea& right);
			bool		init(const Color& right = (size_t)0x00000001);
			virtual bool	treat_event(Lib2D::Event* event);
			virtual bool	treat_render(void);
	};
}

#endif
