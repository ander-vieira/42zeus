#include "test.h"

static void	test_strrchr_child1(void) {
	char	*str;

	tlib_mockmalloc_reset();
	str = "ASDFA";
	tlib_testresult_raw(ft_strrchr(str, 'A') == str + 4);
	tlib_testresult_raw(ft_strrchr(str, 'D') == str + 2);
	tlib_testresult_raw(ft_strrchr(str, '\0') == str + 5);
	tlib_testresult_raw(ft_strrchr(str, 'H') == NULL);
	tlib_testresult_raw(ft_strrchr(str, 'A' + 256) == str + 4);
	tlib_testresult_raw(ft_strrchr(str, 'H' + 256) == NULL);
	tlib_testmalloc_leak();
}

static void	test_strrchr_child2(void) {
	ft_strrchr(NULL, 'A');
}

void	test_strrchr(void) {
	tlib_testprocess_ok(&test_strrchr_child1);
	tlib_testprocess_segfault(&test_strrchr_child2);
}
