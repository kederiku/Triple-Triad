#ifndef __NS_VAR__
#define __NS_VAR__

#include <iostream>

namespace	ns_cmc
{
	namespace	ns_var
	{
		size_t	f_str_len(const char* str);
		int	f_str_cmp(const char* str1, const char* str2);
		int	f_str_ncmp(const char* str1, const char* str2, size_t limit);
		void	f_str_cpy(char* str1, const char* str2);
		void	f_str_ncpy(char* str1, const char* str2, size_t limit);
		void	f_str_cat(char* str1, const char* str2);
		void	f_str_ncat(char* str1, const char* str2, size_t limit);
		char*	f_realloc(char* to_realloc, size_t new_size);
		char*	f_word_dup(const char* str);
		char*	f_str_dup(const char* str);
		char*	f_str_ndup(const char* str, size_t limit);
		size_t	__f_itoa_alloc(int n);
		char*	f_itoa(int n);
		int	f_atoi(const char* str);
		int	f_hexastring_to_int(const char* hexastring, size_t len);
		bool	f_is_integer(const char* word);
		bool	f_is_hex_value(const char* word);
		bool	f_is_boolean(const char* word);
		void	f_print_aligned(const char* str, char filler,
					size_t total_chars, bool lf);
		template <typename T>
		void	f_swap(T& a, T& b);
	}
}

#include "ns_var.hpp"

#endif
