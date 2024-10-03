#include "test.h"

static void	test_calloc_child1(void) {
	void	*buf;

	tlib_mockmalloc_reset();
	buf = ft_calloc(3, 2);
	tlib_testresult_raw(buf != NULL);
	tlib_testmalloc_size(buf, 6, "ft_calloc(3, 2)");
	tlib_testresult_raw(!memcmp(buf, "\0\0\0\0\0\0", 6));
	free(buf);
	tlib_testmalloc_leak("ft_calloc(3, 2)");
}

static void	test_calloc_child2(void) {
	tlib_mockmalloc_reset();
	tlib_mockmalloc_setmock(1);
	tlib_testresult_raw(ft_calloc(3, 2) == NULL);
}

void	test_calloc(void) {
	tlib_testprocess_ok(&test_calloc_child1);
	tlib_testprocess_ok(&test_calloc_child2);
}
