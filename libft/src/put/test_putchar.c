#include "test.h"

static void	test_putchar_fd_testone(char c, char *expected) {
	tlib_mockmalloc_reset();
	tlib_testprint_capture();
	ft_putchar_fd(c, STDOUT_FILENO);
	tlib_testprint_get(expected, "ft_putchar_fd(%c, 1)", c);
	tlib_testmalloc_leak("ft_putchar_fd(%c, 1)", c);
}

static void	test_putchar_fd_child1(void) {
	test_putchar_fd_testone('A', "A");
	test_putchar_fd_testone('\0', "");
}

void	test_putchar_fd(void) {
	tlib_testprocess_ok(&test_putchar_fd_child1, NULL);
}
