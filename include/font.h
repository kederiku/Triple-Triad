#ifndef __LIB2D_FONT__
#define __LIB2D_FONT__

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <map>
#include "libid.h"

namespace	Lib2D
{
	typedef struct	s_val
	{
		TTF_Font*	font;
		size_t		size;
	}	t_val;

	class	Font
	{
		private:
			char*					__path;
			size_t					__ptsize;
			bool					__underline;
#ifdef D_SDL
			static std::map<char*, t_val>		__map;
#elif D_LIB
			// etc...
#endif
		private:
			void	__f_destroy(void);
		public:
					Font(void);
					Font(const Font& right);
			virtual		~Font(void);
			Font&		operator=(const Font& right);
			bool		init(const char* path, size_t ptsize);
#ifdef D_SDL
			TTF_Font*	get_font(void) const;
#elif D_LIB
			// etc...
#endif
			size_t		get_ptsize(void) const;
			bool		set_underline(bool);
			bool		get_underline(void) const;
	};
}

#endif
