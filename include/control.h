#ifndef __LIB2D_CONTROL__
#define __LIB2D_CONTROL__

#include "signal_lister.h"
#include "event.h"
#include "rect.h"
#include <iostream>
#include <SDL/SDL.h>


namespace	Lib2D
{
	class	Control
	{
		public:
			typedef std::list<Control*>			t_control_list;
			typedef std::list<Control*>::iterator		t_control_it;
			typedef std::list<Control*>::const_iterator	t_control_cit;
			typedef std::list<Control*>::reverse_iterator	t_control_rit;
		protected:
			Control*	_parent;
			Rect		_pos;
			Rect		_real_pos;
			bool		_validated;
			bool		_focus;
			bool		_visible;
			bool		_moved;
			bool		_resized;
		public:
			Lib2D::Signal_lister<Control>	signals;
		public:
						Control(void);
						Control(const Control& right);
			virtual			~Control(void);
			Control&		operator=(const Control& right);
			bool			validated(void) const;
			void			validated(bool validated);
			bool			focused(void) const;
			void			focused(bool focused);
			bool			visible(void) const;
			void			visible(bool visible);
			bool			moved(void) const;
			void			moved(bool moved);
			bool			resized(void) const;
			void			resized(bool resized);
			const Control*		parent(void) const;
			void			parent(Control* parent);
			void			set_size(int w, int h);
			Rect&			pos(void);
			Rect&			real_pos(void);
			virtual void		context_loaded(void) = 0;
			virtual void		move(int x, int y) = 0;
			virtual void		resize(size_t w, size_t h) = 0;
			virtual bool		add_child(Control* child) = 0;
			virtual bool		add_child(Control* child, size_t index) = 0;
			virtual bool		del_child(Control* child) = 0;
			virtual bool		del_child(size_t index) = 0;
			virtual bool		del_child(void) = 0;
			virtual bool		rmv_child(Control* child) = 0;
			virtual bool		rmv_child(size_t index) = 0;
			virtual bool		rmv_child(void) = 0;
			virtual const Control*	get_child(size_t index) const = 0;
			virtual const Control*	get_child(void) const = 0;
			virtual size_t		children(void) const = 0;
			virtual bool		dispatch(Lib2D::Event* event) = 0;
			virtual bool		end_of_dispatch(Lib2D::Event* event) = 0;
			virtual bool		out_of_range(Lib2D::Event* event) = 0;
			virtual bool		render(void) = 0;
			virtual bool		treat_event(Lib2D::Event* event) = 0;
			virtual bool		treat_render(void) = 0;
			virtual bool		derived_treat_event(Lib2D::Event* event) = 0;
			virtual bool		derived_treat_render(void) = 0;
			virtual void		cleaner(void) = 0;
	};
}

#endif
