#ifndef __LIB2D_TEXTBOX_ALPHA_H__
#define __LIB2D_TEXTBOX_ALPHA_H__

#include "textbox.h"

namespace	Lib2D
{
	class	TextBox_alpha: public Lib2D::TextBox
	{
		private:
			virtual bool	__check_value(char c);
		public:
			TextBox_alpha(void);
			TextBox_alpha(const TextBox_alpha& right);
			~TextBox_alpha(void);
	};
}
#endif

