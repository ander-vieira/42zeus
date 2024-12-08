#ifndef TLIB_INT_H
# define TLIB_INT_H

# define _GNU_SOURCE

# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <dlfcn.h>
# include <fcntl.h>
# include <sys/wait.h>

# include "tlib.h"

# define COLORCODE_GREEN	"\033[0;32m"
# define COLORCODE_NONE		"\033[0m"
# define COLORCODE_RED		"\033[0;31m"
# define COLORCODE_YELLOW	"\033[0;33m"

# define ERRORLOG_FILE		"errors.log"
# define ERRORLOG_FULLFILE	"~/42zeus/"ERRORLOG_FILE

# define __tlib_log_call(call) \
if (call == NULL)\
	tlib_log_print("A function call");\
else {\
	va_list args;\
	va_start(args, call);\
	tlib_log_vaprint(call, args);\
	va_end(args);\
}

typedef struct s_alloc {
	struct s_alloc	*next;
	void			*addr;
	size_t			size;
}	t_alloc;

typedef struct s_amock {
	struct s_amock	*next;
	size_t			timer;
}	t_amock;

/****** GLOBAL ******/

extern t_bool	tlib_islogging;
extern int		tlib_logfd;
extern char		*tlib_section;
extern t_bool	tlib_newsection;

extern t_alloc	*tlib_allocs;
extern t_amock	*tlib_mocks;

extern t_bool	tlib_ischild;
extern t_bool	tlib_testfailed;
extern int		tlib_testprint_pipe[2];

/****** LOG ******/

void	tlib_log_print(char *format, ...);
void	tlib_log_vaprint(char *format, va_list args);

/****** MOCKMALLOC ******/

void	*libc_malloc(size_t len);
void	libc_free(void *addr);
size_t	tlib_mockmalloc_lookup(void *addr);
size_t	tlib_mockmalloc_count(void);


/****** PRINT ******/

void	tlib_print(int fd, char *format, ...);
void	tlib_vaprint(int fd, char *format, va_list args);

#endif