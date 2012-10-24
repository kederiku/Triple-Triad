#ifndef __LIB2D_COLOR__
#define __LIB2D_COLOR__

#include "ns_macros.h"

struct	SDL_Color;

namespace	Lib2D
{
	class	Color
	{
		public:
			uchar	r;
			uchar	g;
			uchar	b;
			uchar	a;
		public:
					Color(uchar r = 0, uchar g = 0, uchar b = 0, uchar a = 0);
					Color(int hex_color);
					Color(size_t hex_color);
					Color(const Color& right);
			virtual		~Color(void);
			Color&		operator=(const Color& right);
			Color&		operator+(const Color& right);
			Color&		operator-(const Color& right);
			void		hex_to_color(size_t hex_color);
			size_t		color_to_hex(void) const;
			size_t		color_to_hex_no_alpha(void) const;
#ifdef D_SDL
			SDL_Color*	real_color(void) const;
#elif D_LIB
			// etc...
#endif
	};
}

std::ostream&	operator<<(std::ostream& out, Lib2D::Color&);

#endif
