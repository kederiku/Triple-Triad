#ifndef __C_FILE_READER__
#define __C_FILE_READER__

#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include "c_buffer.h"

namespace	ns_cmc
{
	class	c_file_reader
	{
		public:
			#include "c_file_reader_requirements.h"
		private:
			int			__v_fd;
			size_t			__v_read_step;
			bool			__v_eof;
			ns_cmc::c_buffer	__v_path;
		private:
			void	__f_destroy(void);
		public:
						c_file_reader(void);
						c_file_reader(const c_file_reader& right);
			virtual			~c_file_reader(void);
			bool			f_init(const char* path, const char* root = "",
						       size_t read_step = D_DEFAULT_READ_STEP,
						       int flags = O_RDONLY | O_LARGEFILE,
						       mode_t mode = S_IRWXU);
			c_file_reader&		operator=(const c_file_reader& right);
			ns_cmc::c_buffer	f_read_chunk(void);
			bool			f_begin(void);
			bool			f_go_to(off_t position, int whence = SEEK_SET);
			bool			f_eof(void) const;
			int			f_fd(void) const;
			int			f_read_step(void) const;
			const char*		f_path(void);
			void			f_close(void);
		public:
			static void	sf_path_simplifier(ns_cmc::c_buffer& path,
							   bool folder);
			static bool	sf_exists(const char* path, const char* root = "");
	};
}

#endif
