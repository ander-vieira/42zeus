#include "test.h"

static void	test_putstr_fd_testone(char *str, int fd) {
	tlib_mockmalloc_reset();
	tlib_testprint_capture(fd);
	ft_putstr_fd(str, fd);
	tlib_testprint_get(fd, str, "ft_putstr_fd(%S, %d)", str, fd);
	tlib_testmalloc_leak("ft_putstr_fd(%S, %d)", str, fd);
}

static void	test_putstr_fd_child1(void) {
	test_putstr_fd_testone("HOLA MUNDO", 1);
	test_putstr_fd_testone("HOLA MUNDO", 100);
	test_putstr_fd_testone("", 1);
}

static void	test_putstr_fd_child2(void) {
	test_putstr_fd_testone(NULL, 1);
}

void	test_putstr_fd(void) {
	tlib_testprocess_ok(&test_putstr_fd_child1, NULL);
	tlib_testprocess_ok(&test_putstr_fd_child2, "ft_putstr_fd(NULL, 1)");
}
