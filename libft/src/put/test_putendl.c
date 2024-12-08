#include "test.h"

static void	test_putendl_fd_testone(char *str, int fd, char *expected) {
	tlib_mockmalloc_reset();
	tlib_testprint_capture(fd);
	ft_putendl_fd(str, fd);
	tlib_testprint_get(fd, expected, "ft_putendl_fd(%S, %d)", str, fd);
	tlib_testmalloc_leak("ft_putendl_fd(%S, %d)", str, fd);
}

static void	test_putendl_fd_child1(void) {
	test_putendl_fd_testone("HOLA MUNDO", 1, "HOLA MUNDO\n");
	test_putendl_fd_testone("HOLA MUNDO", 100, "HOLA MUNDO\n");
	test_putendl_fd_testone("", 1, "\n");
}

static void	test_putendl_fd_child2(void) {
	test_putendl_fd_testone(NULL, 1, NULL);
}

void	test_putendl_fd(void) {
	tlib_testprocess_ok(&test_putendl_fd_child1, NULL);
	tlib_testprocess_ok(&test_putendl_fd_child2, "ft_putendl_fd(NULL, 1)");
}
