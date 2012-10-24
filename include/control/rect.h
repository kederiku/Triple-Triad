#ifndef __LIB2D_RECT__
#define __LIB2D_RECT__

#include <iostream>

struct	SDL_Rect;

namespace	Lib2D
{
	class	Rect
	{
		public:
			int	x;
			int	y;
			size_t	w;
			size_t	h;
		public:
				Rect(int x = 0, int y = 0, size_t w = 0, size_t h = 0);
				Rect(size_t hex);
				Rect(const Rect& right);
			virtual	~Rect(void);
			Rect&	operator=(const Rect& right);
			Rect&	operator+(const Rect& right);
			Rect&	operator-(const Rect& right);
			void	init(int x, int y, size_t h, size_t w);
			void	pos(int x, int y);
			void	size(size_t w, size_t h);
#ifdef D_SDL
			SDL_Rect*	real_rect(void) const;
#elif D_LIB
			// etc...
#endif
	};
}

std::ostream&	operator<<(std::ostream&, Lib2D::Rect&);


#endif
