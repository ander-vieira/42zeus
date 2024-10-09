#include "test.h"

static void	test_putnbr_fd_testone(int num, char *expected) {
	tlib_mockmalloc_reset();
	tlib_testprint_capture();
	ft_putnbr_fd(num, STDOUT_FILENO);
	tlib_testprint_get(expected, "ft_putnbr_fd(%d, 1)", num);
	tlib_testmalloc_leak("ft_putnbr_fd(%d, 1)", num);
}

static void	test_putnbr_fd_child1(void) {
	test_putnbr_fd_testone(95, "95");
	test_putnbr_fd_testone(0, "0");
	test_putnbr_fd_testone(-5198, "-5198");
	test_putnbr_fd_testone(2147483647, "2147483647");
	test_putnbr_fd_testone(-2147483648, "-2147483648");
}

void	test_putnbr_fd(void) {
	tlib_testprocess_ok(&test_putnbr_fd_child1, NULL);
}
