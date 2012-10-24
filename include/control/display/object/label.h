#ifndef __LIB2D_LABEL__
#define __LIB2D_LABEL__

#include "../object.h"
#include "../../font.h"
#include <string>

namespace	Lib2D
{
	class	Label: public Lib2D::Object
	{
		protected:
			std::string	_label;
			Font		_font;
			Color		_color;
			bool		_bg;
		protected:
			bool		_render_parent(Display* parent);
			bool		_render_context(void);
			bool		_render_bg(SDL_Surface* text);
		public:
					Label(void);
					Label(const Label& right);
			virtual		~Label(void);
			bool		init(const char* label, const char* font_path,
					     size_t font_ptsize,
					     const Color& hex_color = (size_t)0xFFFFFF01,
					     bool bg = false,
					     const Color& bg_hex_color = (size_t)0x00000001);
			Label&		operator=(const Label& right);
			bool		set_label(const char* label);
			const char*	get_label(void) const;
			void		set_font(Font& font);
			Font&		get_font(void);
			uint		get_width(void) const;
			virtual bool	treat_event(Lib2D::Event* event);
			virtual bool	treat_render(void);
			bool		add_char(const char c, int pos);
			bool		del_char(int pos);
			size_t		get_width_surface(void) const;
			size_t		get_height_surface(void) const;
			void		set_color(Color color);
			void		set_color(size_t hex_color);
			const Color&	get_color(void) const;
			void		set_background_color(Color color);
			void		set_background_color(size_t color);
			Color*		get_background_color(void);
			bool		get_background(void) const;
			void		set_background(bool bg, Color color);
			void		set_background(bool bg, size_t hex_color);
			char		get_char(size_t pos) const;
			bool		empty(void) const;
	};
}

#endif
