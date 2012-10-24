#ifndef __NS_MATH__
#define __NS_MATH__

#include <iostream>

namespace	ns_cmc
{
	namespace	ns_math
	{
		template <typename T>
		T	f_abs(T a);
		double	f_distance(int x1, int y1, int x2, int y2);
		double	f_square_root(double n);
		int	f_range(int val, int min, int max);
		int	f_max(int a, int b);
		int	f_min(int a, int b);
		int	f_power(int n, size_t p);
		int	f_factor(int n);
		int	f_decreased_sum(int n, int limit);
	}
}

#include "ns_math.hpp"

#endif
