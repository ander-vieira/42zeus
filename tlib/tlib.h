#ifndef TLIB_H
# define TLIB_H

# define _GNU_SOURCE

typedef enum e_bool {
	FALSE = 0,
	TRUE = 1
}						t_bool;

/****** AUX ******/

t_bool	tlib_aux_memisset(void *addr, size_t n, unsigned char c);
t_bool	tlib_aux_memcmp(void *addr1, void *addr2, size_t n);
t_bool	tlib_aux_strcmp(char *str1, char *str2);
size_t	tlib_aux_strlen(char *str);

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

void	tlib_testmalloc_leak(char *call, ...);
void	tlib_testmalloc_size(void *addr, size_t size, char *call, ...);
void	tlib_testmissing(void (*test)(void), void *fun, char *section);
void	tlib_testresult_raw(t_bool ok);
void	tlib_testresult_true(int value, char *call, ...);
void	tlib_testresult_false(int value, char *call, ...);
void	tlib_testresult_char(int actual_value, int expected_value, char *call, ...);
void	tlib_testresult_int(int actual_value, int expected_value, char *call, ...);
void	tlib_testresult_size(size_t actual_value, size_t expected_value, char *call, ...);
void	tlib_testresult_str(char *actual_value, char *expected_value, char *call, ...);
void	tlib_testresult_addr(void *actual_value, void *expected_value, char *call, ...);
void	tlib_testresult_notnull(void *value, char *call, ...);
void	tlib_testresult_mem(void *addr, size_t n, unsigned char c, char *call, ...);
void	tlib_testprocess_ok(void (*fun)(void));
void	tlib_testprocess_segfault(void (*fun)(void));
int		tlib_test_results(void);

#endif