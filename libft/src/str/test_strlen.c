#include "test.h"

static void	test_strlen_child1(void) {
	tlib_mockmalloc_reset();
	tlib_testresult_raw(ft_strlen("ASDFG") == 5);
	tlib_testresult_raw(ft_strlen("AAA BBB CCC") == 11);
	tlib_testresult_raw(ft_strlen("") == 0);
	tlib_testmalloc_count(0);
}

static void	test_strlen_child2(void) {
	ft_strlen(NULL);
}

void	test_strlen(void) {
	tlib_testprocess_ok(&test_strlen_child1);
	tlib_testprocess_segfault(&test_strlen_child2);
}
