#include "test.h"

static void	test_bzero_child1(void) {
	char	buf[5];

	tlib_mockmalloc_reset();
	ft_bzero(buf, 5);
	tlib_testresult_raw(!memcmp(buf, "\0\0\0\0\0", 5));
	tlib_testmalloc_leak(NULL);
}

static void	test_bzero_child2(void) {
	char	buf[5];

	tlib_mockmalloc_reset();
	strcpy(buf, "ASDF");
	ft_bzero(buf, 0);
	tlib_testresult_raw(!memcmp(buf, "ASDF", 5));
	tlib_testmalloc_leak(NULL);
}

static void	test_bzero_child3(void) {
	ft_bzero(NULL, 0);
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
