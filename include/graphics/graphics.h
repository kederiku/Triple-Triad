#ifndef __LIB2D_GRAPHICS__
#define __LIB2D_GRAPHICS__

#include "../control/rect.h"
#include "../control/surface.h"
#include "../control/display/color.h"

namespace	Lib2D
{
	namespace	graphics
	{
		bool	draw_rect(int x, int y, size_t w, size_t h,
				  const Color& c, const Surface& surface);
		bool	draw_rect(const Rect& rect, const Color& c, const Surface& surface);
		bool	draw_border(const Rect& rect, const Color& c,
				    const Surface& surface, size_t size);
		bool	draw_circle(int x, int y, int radius, const Color& color,
				    const Surface& surface, bool fill);
		bool	draw_horizontal_line(int x, int y, int w,
					     const Color& color, const Surface& surface);
		bool	draw_horizontal_line(const Rect& rect, const Color& color,
					     const Surface& surface);
		bool	draw_vertical_line(int x, int y, int h, const Color& c,
					   const Surface& surface);
		bool	draw_vertical_line(const Rect& rect, const Color& c, const Surface& surface);
		bool	draw(int x1, int y1, int x2, int y2, const Color& color,
			     const Surface& surface, size_t size = 1, bool filled = true);
	}
}

#endif

