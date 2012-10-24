#ifndef _LIB2D_ENGINE_
#define _LIB2D_ENGINE_

#include "ns_macros.h"
#include <list>
#include "event.h"
#include "signal_lister.h"

namespace	Lib2D
{
	class	Control;
	class	Window;
	enum	e_screen_flags
	{
		E_RESIZABLE = 1,
		E_FULLSCREEN = 2,
		E_SOFTWARE = 4,
		E_HARDWARE = 8,
		E_THROWONEXIT = 16
	};
	class	Engine
	{
		protected:
			bool	_running;
		protected:
			virtual bool	_flag_found(uint flags, uint flag);
			virtual uint	_flags_convert(uint flags);
			virtual bool	_catch_events(void);
			virtual bool	_render(void);
			virtual bool	_refresh(Window* window);
			virtual bool	_engine_idle(void* data);
		public:
					Engine(void);
					Engine(const Engine& right);
			virtual		~Engine(void);
			Engine&		operator=(const Engine& right);
			virtual bool	init(void);
			virtual bool	init_main_window(int w, int h, size_t bpp, uint flags,
							 const char* title = "Powered by Lib2D");
			virtual bool	run(void* data = NULL, size_t fps_max = -1);
			virtual void	cleaner(void);
			virtual size_t	ticks(void) const;
			virtual void	wait(size_t ms) const;
	};
}

#endif
