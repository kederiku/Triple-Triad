#ifndef __LIB2D_BUTTON_TOGGLE__
#define __LIB2D_BUTTON_TOGGLE__

#include "button.h"

namespace	Lib2D
{
	class	Button_toggle: public Lib2D::Button
	{
		public:
					Button_toggle(void);
					Button_toggle(const Button_toggle& right);
			virtual		~Button_toggle(void);
			Button_toggle&	operator=(const Button_toggle& right);
			virtual bool	treat_event(Lib2D::Event* event);
			virtual bool	pressed(void) const;
			virtual void	pressed(bool pressed);
	};
}

#endif
