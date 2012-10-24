#ifndef __LIB2D_CONTEXT__
#define __LIB2D_CONTEXT__

#include "multi.h"

namespace	Lib2D
{
	class	Context: public Lib2D::Multi
	{
		private:
			size_t	__number;
		public:
					Context(void);
					Context(const Context& right);
			virtual		~Context(void);
			void		init(size_t number);
			Context&	operator=(const Context& right);
			virtual bool	treat_event(Lib2D::Event* event);
			virtual bool	treat_render(void);
			bool		screenshot(const char* path) const;
			bool		background(size_t color = 0xFFFFFF00);
	};
}

#endif
