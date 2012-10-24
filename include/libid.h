#ifndef LIBID__
#define LIBID__

#include <iostream>
#include <stdio.h>
#include <netdb.h>

namespace cste
{
	size_t		strlen(const char*);
	int		strcmp(const char*, const char*);
	int		strncmp(const char*, const char*, size_t);
	char*		strcpy(char*, const char*);
	char*		strncpy(char*, const char*, size_t);
	char*		strcat(char*, const char*);
	void*		memset(void*, int, size_t);
	char*		strdup(const char*);
	char*		strndup(const char*, size_t);
	void		free_tab(char** tab);
	char*		realloc_string(char*, size_t);
	char**		split(char*, const char*);
	size_t		count_word(char*, const char*);
	char**		str_copy_word(char*, char**, const char*);
	char		is_charset(char, const char*);
	void		bcopy(const void*, void*, size_t);
	void*		memcpy(void*, const void*, size_t);
	size_t		count_char_tab(char** tab);
	int		atoi(char*);
	void		swap(void*, void*);
	int		min(int, int);
	int		max(int, int);
	int		err_color(const char*, int, int);
	int		err_perror(const char*, int);
	void		itoa_base(int, char*, size_t);
	char*		itoa(int);
	char*		inet_ntoa(struct in_addr);
	void		free_tab(char**);
	const char*	Get_Platform();
	char*		encrypt(void* structure, size_t len);
	void		decrypt(void* structure, const char* encode, size_t len);
	void		Version();
	const char*	Get_Content(int fd);
}

#define ERR_IMP 1
#define ERR_ITER 2
#define ERR_INFO 3


#endif
