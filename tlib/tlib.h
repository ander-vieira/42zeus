#ifndef TLIB_H
# define TLIB_H

# define _GNU_SOURCE

typedef enum e_bool {
	FALSE = 0,
	TRUE = 1
}						t_bool;

/****** AUX ******/

t_bool	tlib_isalloc(void *addr);
t_bool	tlib_mem_isset(void *addr, size_t n, unsigned char c);
t_bool	tlib_mem_cmp(void *addr1, void *addr2, size_t n);
char	*tlib_readall(int fd);
t_bool	tlib_str_cmp(char *str1, char *str2);
void	tlib_str_cpy(char *dst, char *src);
size_t	tlib_str_len(char *str);

/****** LOG ******/

void	tlib_log_end(void);
void	tlib_log_section(char *section);
void	tlib_log_start(t_bool clear);

/****** MOCKMALLOC ******/

void	tlib_mockmalloc_reset(void);
void	tlib_mockmalloc_setmock(size_t timer);

/****** TEST ******/

void	tlib_testmalloc_leak(char *call, ...);
void	tlib_testmalloc_notfreed(void *addr, char *call, ...);
void	tlib_testmalloc_size(void *addr, size_t size, char *call, ...);
void	tlib_testmissing(void (*test)(void), void *fun, char *section);
void	tlib_testprint_capture(int fd);
void	tlib_testprint_get(int fd, char *expected, char *call, ...);
void	tlib_testprocess_ok(void (*fun)(void), char *call, ...);
void	tlib_testprocess_segfault(void (*fun)(void), char *call, ...);
void	tlib_testresult_char(int actual_value, int expected_value, char *call, ...);
void	tlib_testresult_int(int actual_value, int expected_value, char *call, ...);
void	tlib_testresult_nonzero(int value, char *call, ...);
void	tlib_testresult_size(size_t actual_value, size_t expected_value, char *call, ...);
void	tlib_testresult_str(char *actual_value, char *expected_value, char *call, ...);
void	tlib_testresult_addr(void *actual_value, void *expected_value, char *call, ...);
void	tlib_testresult_notnull(void *value, char *call, ...);
void	tlib_testresult_mem(void *addr, size_t n, unsigned char c, char *call, ...);
void	tlib_testresult_custom(t_bool condition, char *message, ...);
int		tlib_test_results(void);

#endif