#ifndef __LIB2D_INFO_POPUP__
#define __LIB2D_INFO_POPUP__

#include "popup.h"

namespace	Lib2D
{
	class	Button_label;
	class	Label;
	class	Popup_info: public Lib2D::Popup
	{
		private:
			Lib2D::Button_label*	__button;
			Lib2D::Label*		__info;
		public:
				Popup_info();
		virtual		~Popup_info();
		bool		init(const char* title, const char* info, const char* path);
		virtual bool	treat_event(Lib2D::Event* event);
		virtual bool	treat_render(void);
	};
}

#endif
