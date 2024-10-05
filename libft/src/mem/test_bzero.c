#include "test.h"

static void	test_bzero_child1(void) {
	char	buf[5];

	tlib_mockmalloc_reset();
	ft_bzero(buf, 5);
	tlib_testresult_mem(buf, 5, '\0', "ft_bzero(%p, 5)", buf);
	tlib_testmalloc_leak(NULL);
}

static void	test_bzero_child2(void) {
	char	buf[5];

	tlib_mockmalloc_reset();
	ft_bzero(buf, 0);
	tlib_testmalloc_leak(NULL);
}

static void	test_bzero_child3(void) {
	tlib_mockmalloc_reset();
	ft_bzero(NULL, 0);
	tlib_testmalloc_leak(NULL);
}

static void	test_bzero_child4(void) {
	ft_bzero(NULL, 5);
}

void	test_bzero(void) {
	tlib_testprocess_ok(&test_bzero_child1);
	tlib_testprocess_ok(&test_bzero_child2);
	tlib_testprocess_ok(&test_bzero_child3);
	tlib_testprocess_segfault(&test_bzero_child4);
}
