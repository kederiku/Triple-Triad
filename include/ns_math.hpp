#ifndef __NS_MATH_PP__
#define __NS_MATH_PP__

template <typename T>
T
ns_cmc::ns_math::f_abs(T a)
{
	if (a < 0)
		return -a;
	return a;
}

#endif
