#ifndef __LIB2D_BUTTON_PICTURES__
#define __LIB2D_BUTTON_PICTURES__

#include "button.h"
#include "../object/image.h"

namespace	Lib2D
{
	class	Button_pictures: public Lib2D::Button
	{
		private:
			Lib2D::Image*	__img_click;
			Lib2D::Image*	__img_unclick;
		public:
						Button_pictures(void);
						Button_pictures(const Button_pictures& right);
			virtual			~Button_pictures(void);
			Button_pictures&	operator=(const Button_pictures& right);
			bool			init_pict(const char* path_unclick, const char* path_click = NULL);
			virtual bool		treat_event(Lib2D::Event* event);
			virtual bool		treat_render(void);
	};
}

#endif
