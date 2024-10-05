#include "test.h"

static void	test_putstr_fd_testone(char *str) {
	tlib_testprint_capture();
	ft_putstr_fd(str, STDOUT_FILENO);
	tlib_testprint_get(str, "ft_putstr_fd(%S, 1)", str);
}

static void	test_putstr_fd_child1(void) {
	tlib_mockmalloc_reset();
	test_putstr_fd_testone("HOLA MUNDO");
	test_putstr_fd_testone("");
	tlib_testmalloc_leak(NULL);
}

static void	test_putstr_fd_child2(void) {
	tlib_testprint_capture();
	ft_putstr_fd(NULL, STDOUT_FILENO);
	tlib_testprint_get(NULL, "ft_putstr_fd(NULL, 1)");
	tlib_testmalloc_leak("ft_putstr_fd(NULL, 1)");
}

void	test_putstr_fd(void) {
	tlib_testprocess_ok(&test_putstr_fd_child1);
	tlib_testprocess_ok(&test_putstr_fd_child2);
}
