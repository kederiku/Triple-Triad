#ifndef __NS_MACROS__
#define __NS_MACROS__

#include <iostream>
#include <unistd.h>

typedef unsigned int		uint;
typedef unsigned short int	usint;
typedef unsigned long int	ulint;
typedef unsigned long long int	ullint;
typedef short int		sint;
typedef long int		lint;
typedef long long int		llint;
typedef unsigned char		uchar;

namespace	ns_cmc
{
	namespace	ns_macros
	{
		template <typename T>
		void	f_delete_ptr(T& ptr);
		template <typename T>
		void	f_delete_aptr(T& ptr);
		void	f_close_fd(int& fd);
#ifdef D_ERRORS_ON
		void	f_error(const char* file, int line,
				const char* function, const char* error);
#endif
#ifdef D_INFOS_ON
		void	f_info(const char* info);
#endif
		template <typename T4B>
		T4B&	f_4_bytes_to_uint(const char* buf, T4B& ret);
		template <typename T4B>
		char*	f_uint_to_4_bytes(T4B val, char* ret);
		void	f_end_request(char* rq_end);
		bool	f_end_of_request(const char* rq_end);
		template <typename T>
		T	f_inter(int min, int max, T ret);
	}
}

#include "ns_macros.hpp"

#endif
