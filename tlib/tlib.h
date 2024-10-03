#ifndef TLIB_H
# define TLIB_H

# define _GNU_SOURCE

typedef enum e_bool {
	FALSE = 0,
	TRUE = 1
}						t_bool;

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
void	tlib_testprocess_ok(void (*fun)(void));
void	tlib_testprocess_segfault(void (*fun)(void));
int		tlib_test_results(void);

#endif