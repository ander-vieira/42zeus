#include "test.h"

static void	test_putstr_fd_testone(char *str) {
	tlib_mockmalloc_reset();
	tlib_testprint_capture();
	ft_putstr_fd(str, STDOUT_FILENO);
	tlib_testprint_get(str, "ft_putstr_fd(%S, 1)", str);
	tlib_testmalloc_leak("ft_putstr_fd(%S, 1)", str);
}

static void	test_putstr_fd_child1(void) {
	test_putstr_fd_testone("HOLA MUNDO");
	test_putstr_fd_testone("");
}

static void	test_putstr_fd_child2(void) {
	test_putstr_fd_testone(NULL);
}

void	test_putstr_fd(void) {
	tlib_testprocess_ok(&test_putstr_fd_child1, NULL);
	tlib_testprocess_ok(&test_putstr_fd_child2, "ft_putstr_fd(NULL, 1)");
}
