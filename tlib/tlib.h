#ifndef TLIB_H
# define TLIB_H

# define _GNU_SOURCE

# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <dlfcn.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef unsigned int	t_uint;

typedef enum e_bool {
	FALSE = 0,
	TRUE = 1
}						t_bool;

typedef enum s_pres {
	PRESULT_OK,
	PRESULT_SEGFAULT,
	PRESULT_CRASH
}	t_pres;

/* ************************************************************************** */
/* Alloc: managing lists of memory allocations                                */

void	tlib_mockmalloc_reset(void);
void	tlib_mockmalloc_setmock(size_t timer);

/* ************************************************************************** */
/* Test: printing test results                                                */

void	tlib_testmalloc_count(size_t count);
void	tlib_testmalloc_size(void *addr, size_t size);
void	tlib_testmissing(void (*test)(void), void *fun, char *title);
void	tlib_testresult_bool(t_bool ok);
void	tlib_test_process(void (*fun)(void), t_pres expected);
int		tlib_test_results(void);

#endif