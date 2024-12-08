#include "test.h"

static void	test_putnbr_fd_testone(int num, int fd, char *expected) {
	tlib_mockmalloc_reset();
	tlib_testprint_capture(fd);
	ft_putnbr_fd(num, fd);
	tlib_testprint_get(fd, expected, "ft_putnbr_fd(%d, %d)", num, fd);
	tlib_testmalloc_leak("ft_putnbr_fd(%d, %d)", num, fd);
}

static void	test_putnbr_fd_child1(void) {
	test_putnbr_fd_testone(95, 1, "95");
	test_putnbr_fd_testone(95, 100, "95");
	test_putnbr_fd_testone(0, 1, "0");
	test_putnbr_fd_testone(-5198, 1, "-5198");
	test_putnbr_fd_testone(2147483647, 1, "2147483647");
	test_putnbr_fd_testone(-2147483648, 1, "-2147483648");
}

void	test_putnbr_fd(void) {
	tlib_testprocess_ok(&test_putnbr_fd_child1, NULL);
}
