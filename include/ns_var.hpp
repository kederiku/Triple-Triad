#ifndef __NS_VAR_PP__
#define __NS_VAR_PP__

inline
void
ns_cmc::ns_var::f_print_aligned(const char* str, char filler, size_t total_chars, bool lf)
{
	size_t	diff;
	size_t len;

	len = ns_cmc::ns_var::f_str_len(str);
	if (total_chars <= len)
	{
		std::cout << str;
		return ;
	}
	diff = total_chars - len;
	for (size_t i = 0; i < diff; ++i)
		std::cout << filler;
	std::cout << str;
	if (lf == true)
		std::cout << std::endl;
}

template <typename T>
void
ns_cmc::ns_var::f_swap(T& a, T& b)
{
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

#endif
