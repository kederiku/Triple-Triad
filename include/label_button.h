#ifndef __LIB2D_BUTTON_LABEL__
#define __LIB2D_BUTTON_LABEL__

#include "button.h"
#include "color.h"
#include "label.h"

namespace	Lib2D
{
	class	Button_label: public Lib2D::Button
	{
		private:
			Lib2D::Label*	__label;
			bool		__new_label;
		public:
					Button_label(void);
					Button_label(const Button_label& right);
			virtual		~Button_label(void);
			Button_label&	operator=(const Button_label& right);
			bool		init_label(const char* label, const char* font_path,
						   size_t font_ptsize,
						   const Color& hex_color = 0x00000000);
			bool		set_label(const char* label);
			virtual bool	treat_event(Lib2D::Event* event);
			virtual bool	treat_render(void);
	};
}

#endif
