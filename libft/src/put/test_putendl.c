#include "test.h"

static void	test_putendl_fd_testone(char *str, char *expected) {
	tlib_testprint_capture();
	ft_putendl_fd(str, STDOUT_FILENO);
	tlib_testprint_get(expected, "ft_putendl_fd(%S, 1)", str);
}

static void	test_putendl_fd_child1(void) {
	tlib_mockmalloc_reset();
	test_putendl_fd_testone("HOLA MUNDO", "HOLA MUNDO\n");
	test_putendl_fd_testone("", "\n");
	tlib_testmalloc_leak(NULL);
}

static void	test_putendl_fd_child2(void) {
	tlib_testprint_capture();
	ft_putendl_fd(NULL, STDOUT_FILENO);
	tlib_testprint_get(NULL, "ft_putendl_fd(NULL, 1)");
	tlib_testmalloc_leak("ft_putendl_fd(NULL, 1)");
}

void	test_putendl_fd(void) {
	tlib_testprocess_ok(&test_putendl_fd_child1, NULL);
	tlib_testprocess_ok(&test_putendl_fd_child2, NULL);
}
