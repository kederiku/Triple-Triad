#ifndef __LIB2D_TEXTBOX__
#define __LIB2D_TEXTBOX__

#include "../mono.h"
#include "../color.h"
#include "../../timer.h"
#include "../object/label.h"

// 275 right
// 276 left
namespace	Lib2D
{
	class	TextBox: public Lib2D::Mono
	{
		protected:
			bool		__border;
			Timer		__timer;
			int		__time_tick;
			bool		__tick;
			int		__max_char;
			Lib2D::Label*	__label;
			Lib2D::Rect	__pos_curs;
			int		__width;
		protected:
			bool		__print_line(void);
			bool		__erase_line(void);
			bool		__update_pos_curs(int key, bool action);
			int		__get_width_char(int key);
			int		__get_width_char_pos(int pos);
			bool		__set_pos_label(void);
			virtual bool	__check_value(char c);
		public:
					TextBox(void);
					TextBox(const TextBox& right);
			virtual		~TextBox(void);
			TextBox&	operator=(const TextBox& right);
			bool		init(const char* font_path, size_t font_size,
					     int max_char = -1, const Color& hex_bg = 0xffffff01,
					     bool border = false, const Color& hex_border = 0x00000001);
			virtual bool	treat_event(Lib2D::Event* event);
			virtual bool	treat_render(void);
			bool		get_border(void) const;
			void		set_border(bool border, Color color);
			void		set_border(bool border, size_t hex_color);
			bool		draw_surface(void);
			void		set_max_char(int max);
			int		get_max_char(void) const;
			const char*	get_value(void) const;
			bool		set_value(const char* value);
			bool		empty(void) const;
	};
}

#endif
