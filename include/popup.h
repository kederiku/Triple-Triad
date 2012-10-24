#ifndef __LIB2D_POPUP__
#define __LIB2D_POPUP__

#include "multi.h"

namespace	Lib2D
{
	class	Label;
	class	Popup: public Lib2D::Multi
	{
		protected:
			Lib2D::Label*	_label;

		protected:
			bool		_init_interface(void);
			bool		_init(const char* title, const char* path);

		protected:
					Popup(void);
					Popup(const Popup& right);
			virtual		~Popup(void);
			Popup&		operator=(const Popup& right);
			virtual bool	treat_event(Lib2D::Event* event);
			virtual bool	treat_render(void);
	};
}

#endif
