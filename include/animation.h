#ifndef __LIB2D_ANIMATION__
#define __LIB2D_ANIMATION__

#include "mono.h"
#include "timer.h"
#include "image.h"
#include <vector>

namespace	Lib2D
{
	class	Animation : public Lib2D::Object
	{
		public:
			struct	s_frame
			{
				Lib2D::Display*	obj;
				unsigned int	delay;
			};
			enum	e_status
			{
				E_STOP,
				E_PLAY
			};
		private:
			std::vector<s_frame>	__tab_frame;
			e_status		__status;
			unsigned int		__current_frame;
			Lib2D::Timer		__timer;
			Uint32			__time;
			bool			__loop;
		public:
					Animation(void);
					Animation(const Animation& right);
			virtual		~Animation(void);
			Animation&	operator=(const Animation& right);
			bool		init(unsigned int frames, bool loop = false);
			void		play(void);
			void		stop(void);
			void		rewind(void);
			bool		update(void);
			void		set_current_frame(unsigned int pos);
			bool		next_frame(void);
			bool		is_playing(void) const;
			void		set_loop(bool loop);
			bool		set_frame(unsigned int pos, Lib2D::Display* obj, unsigned int delay);
			bool		set_nb_frames(unsigned int frames);
			unsigned int	get_nb_frames(void) const;
			void		set_delay_all_frames(unsigned int delay);
			bool		set_delay_frame(unsigned int pos, unsigned int delay);
			virtual bool	treat_event(Lib2D::Event* event);
			virtual bool	treat_render(void);
			bool		erase_prev_frame(unsigned int pos);
			virtual void	move(int x, int y);
	};
}

#endif

