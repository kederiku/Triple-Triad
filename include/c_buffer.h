#ifndef __C_BUFFER__
#define __C_BUFFER__

#include <iostream>
#include "ns_macros.h"

namespace	ns_cmc
{
	class	c_buffer
	{
		public:
			#include "c_buffer_requirements.h"
		private:
			char*	__v_buf;
			char*	__v_pos;
			size_t	__v_capacity;
			size_t	__v_size;
			size_t	__v_mem_step;
		private:
			void	__f_destroy(void);
		public:
					c_buffer(void);
					c_buffer(const c_buffer& right);
			virtual		~c_buffer(void);
			bool		f_init_empty(size_t capacity,
						     size_t mem_step = D_DEFAULT_MEM_STEP);
			bool		f_init(const c_buffer& right, size_t len = 0);
			bool		f_init(const char* str, size_t len = 0,
					       size_t mem_step = D_DEFAULT_MEM_STEP);
			bool		f_init(uint val, size_t mem_step = D_DEFAULT_MEM_STEP);
			c_buffer&	operator=(const c_buffer& right);
			c_buffer&	operator=(const char* right);
			char&		operator*(void);
			char*		operator->(void);
			char&		operator[](const int right);
			bool		operator==(const c_buffer& right) const;
			bool		operator!=(const c_buffer& right) const;
			bool		operator==(const char* right) const;
			bool		operator!=(const char* right) const;
			bool		operator<(const c_buffer& right) const;
			bool		operator>(const c_buffer& right) const;
			bool		operator<=(const c_buffer& right) const;
			bool		operator>=(const c_buffer& right) const;
			bool		operator<(const char* right) const;
			bool		operator>(const char* right) const;
			bool		operator<=(const char* right) const;
			bool		operator>=(const char* right) const;
			c_buffer&	operator++(void);
			c_buffer&	operator--(void);
			c_buffer	operator++(int);
			c_buffer	operator--(int);
			c_buffer	operator+(const char* right) const;
			c_buffer	operator+(const c_buffer& right) const;
			c_buffer&	operator+=(const int right);
			c_buffer&	operator-=(const int right);
			c_buffer&	operator+=(const char* right);
			c_buffer&	operator+=(const c_buffer& right);
			char*		f_get_str_by_len(size_t beg, size_t len) const;
			char*		f_get_str_by_limit(size_t beg, char limit,
							   bool include) const;
			void		f_pos_reset(void);
			bool		f_resize(size_t size);
			bool		f_recap(size_t capacity);
			size_t		f_size(void) const;
			size_t		f_capacity(void) const;
			size_t		f_space(void) const;
			size_t		f_get_mem_step(void) const;
			void		f_set_mem_step(size_t arg_mem_step);
			bool		f_empty(void) const;
			bool		f_full(void) const;
			size_t		f_add_string(const char* str, size_t len);
			bool		f_concat(const char* str, size_t len = 0);
			bool		f_precat(const char* str, size_t len = 0);
			bool		f_concat(uint val);
			bool		f_precat(uint val);
			bool		f_concat(const c_buffer& right);
			bool		f_precat(const c_buffer& right);
			bool		f_getchar(char* ptr);
			char		f_getchar_nv(void);
			bool		f_peekchar(char* ptr, size_t index) const;
			char		f_peekchar_nv(size_t index) const;
			char*		f_getline(void);
			char*		f_peekline(size_t index) const;
			char*		f_flush(void);
			void		f_clear(void);
			void		f_swap(c_buffer* right);
			void		f_erase(size_t pos, size_t n);
			int		f_compare(const char* str) const;
			int		f_ncompare(const char* str, size_t limit) const;
			int		f_pos_compare(const char* str, size_t pos) const;
			int		f_pos_ncompare(const char* str, size_t limit,
						       size_t pos) const;
			int		f_compare(const c_buffer& right) const;
			int		f_ncompare(const c_buffer& right, size_t limit) const;
			int		f_pos_compare(const c_buffer& right, size_t pos) const;
			int		f_pos_ncompare(const c_buffer& right,
						       size_t limit, size_t pos) const;
			int		f_find(const char* str, size_t pos, size_t n) const;
			size_t		f_rfind(const char* str, size_t pos, size_t n) const;
			bool		f_alphanum(void) const;
			void		f_print(bool endl = false) const;
			char*		f_to_str(void);
			const char*	f_to_const_str(void);
			char*		f_peek_request(size_t& size);
			char*		f_get_request(size_t& size);
			c_buffer*	f_peek_request(void);
			c_buffer*	f_get_request(void);
			uint		f_peek_uint(void);
			uint		f_get_uint(void);
			size_t		f_occurences(const char* str, size_t len) const;
			char**		f_to_words(const char* dividers = " ,;\t\n") const;
		public:
			static char**	sf_str_to_words(const char* str,
							const char* dividers = " ,;\t\n");
	};
}

#endif
