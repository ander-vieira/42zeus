#include "test.h"

static void	test_calloc_child1(void) {
	void	*buf;

	tlib_mockmalloc_reset();
	buf = ft_calloc(3, 2);
	tlib_testresult_notnull(buf, "ft_calloc(3, 2)");
	tlib_testresult_mem(buf, 6, '\0', "ft_calloc(3, 2)");
	tlib_testmalloc_size(buf, 6, "ft_calloc(3, 2)");
	free(buf);
	tlib_testmalloc_leak("ft_calloc(3, 2)");
}

static void	test_calloc_child2(void) {
	tlib_mockmalloc_reset();
	tlib_mockmalloc_setmock(1);
	tlib_testresult_addr(ft_calloc(3, 2), NULL, "ft_calloc(3, 2) (with malloc fail)");
}

void	test_calloc(void) {
	tlib_testprocess_ok(&test_calloc_child1, "ft_calloc(3, 2)");
	tlib_testprocess_ok(&test_calloc_child2, "ft_calloc(3, 2) (with malloc fail)");
}
