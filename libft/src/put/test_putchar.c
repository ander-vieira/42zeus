#include "test.h"

static void	test_putchar_fd_testone(char c, char *expected) {
	tlib_testprint_capture();
	ft_putchar_fd(c, STDOUT_FILENO);
	tlib_testprint_get(expected, "ft_putchar_fd(%c, 1)", c);
}

static void	test_putchar_fd_child1(void) {
	tlib_mockmalloc_reset();
	test_putchar_fd_testone('A', "A");
	test_putchar_fd_testone('\0', "");
	tlib_testmalloc_leak(NULL);
}

void	test_putchar_fd(void) {
	tlib_testprocess_ok(&test_putchar_fd_child1);
}
