#include "test.h"

static void	test_bzero_child1(void) {
	char	buf[5];

	tlib_mockmalloc_reset();
	ft_bzero(buf, 5);
	tlib_testresult_mem(buf, 5, '\0', "ft_bzero(*, 5)");
	tlib_testmalloc_leak("ft_bzero(*, 5)");
}

static void	test_bzero_child2(void) {
	char	buf[5];

	tlib_mockmalloc_reset();
	ft_bzero(buf, 0);
	tlib_testmalloc_leak("ft_bzero(*, 0)");
}

static void	test_bzero_child3(void) {
	tlib_mockmalloc_reset();
	ft_bzero(NULL, 0);
	tlib_testmalloc_leak("ft_bzero(NULL, 0)");
}

static void	test_bzero_child4(void) {
	ft_bzero(NULL, 5);
}

void	test_bzero(void) {
	tlib_testprocess_ok(&test_bzero_child1, "ft_bzero(*, 5)");
	tlib_testprocess_ok(&test_bzero_child2, "ft_bzero(*, 0)");
	tlib_testprocess_ok(&test_bzero_child3, "ft_bzero(NULL, 0)");
	tlib_testprocess_segfault(&test_bzero_child4, "ft_bzero(NULL, 5)");
}
