#ifndef __LIB2D_TEXTBOX_NUM_H__
#define __LIB2D_TEXTBOX_NUM_H__

#include "textbox.h"

namespace	Lib2D
{
	class	TextBox_num: public Lib2D::TextBox
	{
		private:
			virtual bool	__check_value(char c);
		public:
			TextBox_num(void);
			TextBox_num(const TextBox_num& right);
			~TextBox_num(void);
	};
}

#endif

