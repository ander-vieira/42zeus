#include "test.h"

static void	test_strrchr_child1(void) {
	char	*str;

	tlib_mockmalloc_reset();
	str = "ASDFA";
	tlib_testresult_bool(ft_strrchr(str, 'A') == str + 4);
	tlib_testresult_bool(ft_strrchr(str, 'D') == str + 2);
	tlib_testresult_bool(ft_strrchr(str, '\0') == str + 5);
	tlib_testresult_bool(ft_strrchr(str, 'H') == NULL);
	tlib_testresult_bool(ft_strrchr(str, 'A' + 256) == str + 4);
	tlib_testresult_bool(ft_strrchr(str, 'H' + 256) == NULL);
	tlib_testmalloc_count(0);
}

static void	test_strrchr_child2(void) {
	ft_strrchr(NULL, 'A');
}

void	test_strrchr(void) {
	tlib_test_process(&test_strrchr_child1, PRESULT_OK);
	tlib_test_process(&test_strrchr_child2, PRESULT_SEGFAULT);
}
