#include "test.h"

static void	test_calloc_child1(void) {
	void	*buf;

	tlib_mockmalloc_reset();
	buf = ft_calloc(3, 2);
	tlib_testresult_bool(buf != NULL);
	tlib_testmalloc_count(1);
	tlib_testmalloc_size(buf, 6);
	tlib_testresult_bool(!memcmp(buf, "\0\0\0\0\0\0", 6));
	free(buf);
}

static void	test_calloc_child2(void) {
	tlib_mockmalloc_reset();
	tlib_mockmalloc_setmock(1);
	tlib_testresult_bool(ft_calloc(3, 2) == NULL);
}

void	test_calloc(void) {
	tlib_test_process(&test_calloc_child1, PRESULT_OK);
	tlib_test_process(&test_calloc_child2, PRESULT_OK);
}
