#ifndef __NS_MACROS_PP__
#define __NS_MACROS_PP__

#include <new>

template <typename T>
inline
void
ns_cmc::ns_macros::f_delete_ptr(T& ptr)
{
	delete ptr;
	ptr = NULL;
}

template <typename T>
inline
void
ns_cmc::ns_macros::f_delete_aptr(T& ptr)
{
	delete [] ptr;
	ptr = NULL;
}

inline
void
ns_cmc::ns_macros::f_close_fd(int& fd)
{
	if (fd != -1)
	{
		close(fd);
		fd = -1;
	}
}

#ifdef D_ERRORS_ON

#define m_error(error) ns_cmc::ns_macros::f_error(__FILE__, __LINE__, __func__, error)

inline
void
ns_cmc::ns_macros::f_error(const char* file, int line,
			   const char* function, const char* error)
{
	std::cerr << "In file: " << file << " @" << line << ":" << std::endl;
	std::cerr << "\t" << function << "(): " << error << std::endl;
}

#else

#define m_error(str) 

#endif

#ifdef D_INFOS_ON

#define m_info(info) ns_cmc::ns_macros::f_info(info)

inline
void
ns_cmc::ns_macros::f_info(const char* info)
{
	std::cerr << info << std::endl;
}

#else

#define m_info(info) 

#endif

template <typename T4B>
inline
T4B&
ns_cmc::ns_macros::f_4_bytes_to_uint(const char* buf, T4B& ret)
{
	ret = (T4B)(((buf[3] << 24) & 0xff000000) |
		    ((buf[2] << 16) & 0x00ff0000) |
		    ((buf[1] << 8) & 0x0000ff00) |
		    (buf[0] & 0x000000ff));
	return ret;
}

template <typename T4B>
inline
char*
ns_cmc::ns_macros::f_uint_to_4_bytes(T4B val, char* ret)
{
	ret[3] = (val >> 24) & 0xff;
	ret[2] = (val >> 16) & 0xff;
	ret[1] = (val >> 8) & 0xff;
	ret[0] = val & 0xff;
	return ret;
}

inline
void
ns_cmc::ns_macros::f_end_request(char* rq_end)
{
	rq_end[0] = '\r';
	rq_end[1] = '\n';
}

inline
bool
ns_cmc::ns_macros::f_end_of_request(const char* rq_end)
{
	if (rq_end[-1] == '\r' && rq_end[0] == '\n')
		return true;
	return false;
}

template <typename T>
inline
T
ns_cmc::ns_macros::f_inter(int min, int max, T ret)
{
	if (ret < (T)min)
	{
		ret = min;
		return (T)min;
	}
	if (ret > (T)max)
	{
		ret = max;
		return (T)max;
	}
	return ret;
}

#endif
