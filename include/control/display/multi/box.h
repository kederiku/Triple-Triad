#ifndef __LIB2D_BOX__
#define __LIB2D_BOX__

#include "../multi.h"

namespace	Lib2D
{
	enum	e_box_alignment
	{
		LEFT_ALIGNMENT = 0,
		CENTER_ALIGNMENT,
		RIGHT_ALIGNMENT
	};
	struct	s_box_padding
	{
		int	top;
		int	bottom;
		int	right;
		int	left;
	};
	class	Box: public Lib2D::Multi
	{
		protected:
			s_box_padding	_padding;
			Rect		_virtual_pos;
			size_t		_spacing;
			bool		_homogeneous;
		private:
			bool	__create_background(void);
			bool	__draw_background(void);
		protected:
			virtual void	_apply_padding(void);
			virtual void	_apply_alignment(e_box_alignment aligment);
			virtual void	_apply_spacing(int i) = 0;
			virtual void	_apply_homogeneity(void) = 0;
			virtual void	_apply_expandable(bool expandable) = 0;
			virtual void	_put_child(void) = 0;
		public:
					Box(void);
					Box(const Box& right);
			virtual		~Box(void);
			Box&		operator=(const Box& right);
			virtual bool	add_child(Lib2D::Control* control);
			virtual bool	add_child(Lib2D::Control* control, size_t index);
			virtual bool	add_child(Lib2D::Control* control,
						  e_box_alignment alignment = LEFT_ALIGNMENT,
						  bool expandable = false) = 0;
			virtual bool	init(bool homogeneous = false, int spacing = 0);
			virtual bool	init(const s_box_padding& padding,
					     bool homogeneous = false, int spacing = 0);
			s_box_padding	get_padding(void) const;
			unsigned	get_spacing(void) const;
			bool		get_homogeneous(void) const;
			virtual bool	treat_event(Lib2D::Event* event);
			virtual bool	treat_render(void);
	};
}

#endif
