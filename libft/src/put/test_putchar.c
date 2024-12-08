#include "test.h"

static void	test_putchar_fd_testone(char c, int fd, char *expected) {
	tlib_mockmalloc_reset();
	tlib_testprint_capture(fd);
	ft_putchar_fd(c, fd);
	tlib_testprint_get(fd, expected, "ft_putchar_fd(%c, %d)", c, fd);
	tlib_testmalloc_leak("ft_putchar_fd(%c, %d)", c, fd);
}

static void	test_putchar_fd_child1(void) {
	test_putchar_fd_testone('A', 1, "A");
	test_putchar_fd_testone('A', 100, "A");
	test_putchar_fd_testone('\0', 1, "");
}

void	test_putchar_fd(void) {
	tlib_testprocess_ok(&test_putchar_fd_child1, NULL);
}
