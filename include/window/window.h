#ifndef __LIB2D_WINDOW__
#define __LIB2D_WINDOW__

#include "../control/display.h"
#include "../control/rect.h"
#include <vector>
#include <singleton.hpp>

namespace	Lib2D
{
	class	Surface;
	class	Context;
	class	Window : public singleton<Window>
	{
		public:
			typedef std::vector<Lib2D::Context*>			t_ctxt_vector;
			typedef std::vector<Lib2D::Context*>::iterator		t_ctxt_it;
			typedef std::vector<Lib2D::Context*>::const_iterator	t_ctxt_const_it;
		private:
			Surface*	__window;
			Rect		__min;
			Rect		__max;
			size_t		__cur_context;
			t_ctxt_vector	__contexts;
			Control*	__obj_focus;
			uint		__flags;
		private:
			friend class singleton<Window>;

						Window(void);
			virtual			~Window(void);
		protected:
			virtual void	_quit(void);
		public:
			bool			init(Surface* display, uint flags);
			Surface*		screen(void) const;
#ifdef D_SDL
			SDL_Surface*		real_screen(void) const;
#elif D_LIB
			// etc...
#endif
			void			limits(size_t w_min, size_t w_max,
						       size_t h_min, size_t h_max);
			bool			add_context(Lib2D::Context* context);
			bool			add_context(Lib2D::Context* context, size_t index);
			bool			del_context(Lib2D::Context* context);
			bool			del_context(size_t index);
			const Lib2D::Context*	get_context(void) const;
			const Lib2D::Context*	get_context(size_t index) const;
			bool			context(size_t context);
			size_t			contexts(void) const;
			void			next_context(void);
			void			prev_context(void);
			bool			dispatch(Lib2D::Event* event);
			bool			render(void);
			bool			treat_event(Lib2D::Event* event);
			bool			treat_render(void);
			bool			screenshot(const char* path) const;
			void			cleaner(void);
			void			set_obj_focus(Lib2D::Control* control);
	};
}

#endif
