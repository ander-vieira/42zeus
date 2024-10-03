#ifndef TLIB_H
# define TLIB_H

# define _GNU_SOURCE

typedef enum e_bool {
	FALSE = 0,
	TRUE = 1
}						t_bool;

/****** LOG ******/

void	tlib_log_end(void);
void	tlib_log_section(char *section);
void	tlib_log_start(t_bool clear);

/* ************************************************************************** */
/* Alloc: managing lists of memory allocations                                */

void	tlib_mockmalloc_reset(void);
void	tlib_mockmalloc_setmock(size_t timer);

/* ************************************************************************** */
/* Test: printing test results                                                */

void	tlib_testmalloc_count(size_t count);
void	tlib_testmalloc_size(void *addr, size_t size, char *call);
void	tlib_testmissing(void (*test)(void), void *fun, char *section);
void	tlib_testresult_raw(t_bool ok);
void	tlib_testresult_true(int value, char *call);
void	tlib_testresult_false(int value, char *call);
void	tlib_testprocess_ok(void (*fun)(void));
void	tlib_testprocess_segfault(void (*fun)(void));
int		tlib_test_results(void);

#endif