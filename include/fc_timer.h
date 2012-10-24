#ifndef __FC_TIMER__
#define __FC_TIMER__

#include <iostream>
#include <time.h>
#include "ns_macros.h"

namespace	ns_cmc
{
	class	fc_timer
	{
		public:
			typedef struct timespec	s_ts;
		public:
			s_ts*	operator()(size_t seconds);
	};
}

#endif
