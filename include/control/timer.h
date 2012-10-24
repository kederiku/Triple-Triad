#ifndef __LIB2D_TIMER__
#define __LIB2D_TIMER__

#include <iostream>

namespace	Lib2D
{
	class	Timer
	{
		private:
			size_t	__start_ticks;
			size_t	__paused_ticks;
			bool	__paused;
			bool	__started;
		public:
				Timer(void);
				Timer(const Timer& right);
				~Timer(void);
			Timer&	operator=(const Timer& right);
			void	start(void);
			void	stop(void);
			void	pause(void);
			void	unpause(void);
			size_t	get_ticks(void);
			bool	is_started(void);
			bool	is_paused(void);
	};

}

#endif
