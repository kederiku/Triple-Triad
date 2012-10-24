#ifndef __LIB2D_IMAGE__
#define __LIB2D_IMAGE__

#include "../multi/container.h"
#include "../object.h"

namespace	Lib2D
{
	class	Image: public Lib2D::Object
	{
		protected:
			Lib2D::Surface		_scale;
		public:
						Image(void);
						Image(const Image& right);
			virtual			~Image(void);
			Image&			operator=(const Image& right);
			bool			load_bmp(const char* path);
			bool			rload_bmp(const char* path);
			bool			tload(int w, int h, int bpp, const void* data);
			bool			tload_bmp(const char* path, int r, int g, int b);
			bool			resize_now(size_t w, size_t h);
			Lib2D::Image*		get_image_part(int x, int y, int w, int h);
			bool			colorkey(uchar r, uchar g, uchar b);
			virtual bool		treat_event(Lib2D::Event* event);
			virtual bool		treat_render(void);
			bool			set_transparence(int r, int g, int b);
	};
}

#endif
