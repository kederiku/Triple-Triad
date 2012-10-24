#ifndef __LIB2D_LABEL_LINK__
#define __LIB2D_LABEL_LINK__

#include "label.h"

namespace	Lib2D
{
	class	Label_link: public Lib2D::Label
	{
		protected:
			size_t		_context;
		public:
					Label_link(void);
					Label_link(const Label_link& right);
			virtual		~Label_link(void);
			bool		init(const char* label, const char* font_path,
					     size_t font_ptsize, size_t context,
					     const Color& hex_color = 0xFFFFFF01,
					     bool bg = true,
					     const Color& bg_hex_color = 0x00000001);
			Label_link&	operator=(const Label_link& right);
			virtual bool	treat_event(Lib2D::Event* event);
	};
}

#endif
