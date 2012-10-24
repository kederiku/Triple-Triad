#ifndef __LIB2D_SURFACE__
#define __LIB2D_SURFACE__

#include <SDL/SDL.h>
#include "color.h"

namespace	Lib2D
{
	class	Surface
	{
		private:
			Color		__color;
#ifdef D_SDL
			SDL_Surface*	__surface;
#elif D_LIB
			// etc...
#endif
		private:
			void	__f_destroy(void);
		public:
					Surface(void);
					Surface(const Surface& right);
			virtual		~Surface(void);
			bool		init(SDL_Surface* surface,
					     const Color& color = (size_t)0x00000001);
			Surface&	operator=(const Surface& right);
#ifdef D_SDL
			size_t		width(void) const;
			size_t		height(void) const;
			SDL_Surface&	get_surface_ref(void) const;
			SDL_Surface*	get_surface_ptr(void) const;
			bool		update(SDL_Surface* surface);
			void		clear(void);
			void		set_color(const Color& color);
			Color&		get_color_ref(void);
			Color*		get_color_ptr(void);
			size_t		get_color_sdl(void) const;
			static bool	lock(SDL_Surface* surface);
			static void	unlock(SDL_Surface* surface);
			static void	scale(SDL_Surface* src, SDL_Surface* dst);
			static void	set_pixel(SDL_Surface* target, int x, int y, Uint32 pixel);
			static Uint32	get_pixel(SDL_Surface* target, int x, int y);
#elif D_LIB
			// etc...
#endif
	};
}

#endif
