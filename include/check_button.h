#ifndef __LIB2D_BUTTON_CHECK__
#define __LIB2D_BUTTON_CHECK__

#include "button.h"

namespace	Lib2D
{
	class	Button_check: public Lib2D::Button
	{
		private:
			size_t	__check_case;
			bool	__draw;
			bool	__actif;
		public:
					Button_check(void);
					Button_check(const Button_check& right);
			virtual		~Button_check(void);
			Button_check&	operator=(const Button_check& right);
			void		change_color_case(size_t color);
			virtual bool	get_value(void) const;
			virtual void	set_value(bool value);
			virtual bool	treat_event(Lib2D::Event* event);
			virtual bool	treat_render(void);
	};
}

#endif
