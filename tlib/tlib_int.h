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

typedef struct s_alloc {
	struct s_alloc	*next;
	void			*addr;
	size_t			size;
}	t_alloc;

typedef struct s_amock {
	struct s_amock	*next;
	size_t			timer;
}	t_amock;

/* ************************************************************************** */
/* Alloc: managing lists of memory allocations                                */

size_t	tlib_mockmalloc_lookup(void *addr);
size_t	tlib_mockmalloc_count(void);

/* ************************************************************************** */
/* Printf: making my own version for portability                              */

void	tlib_printf(int fd, char *format, ...);

#endif