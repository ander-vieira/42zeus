#include "test.h"

static void	test_strchr_child1(void) {
	char	*str;

	tlib_mockmalloc_reset();
	str = "ASDFA";
	tlib_testresult_bool(ft_strchr(str, 'A') == str);
	tlib_testresult_bool(ft_strchr(str, 'D') == str + 2);
	tlib_testresult_bool(ft_strchr(str, '\0') == str + 5);
	tlib_testresult_bool(ft_strchr(str, 'H') == NULL);
	tlib_testresult_bool(ft_strchr(str, 'A' + 256) == str);
	tlib_testresult_bool(ft_strchr(str, 'H' + 256) == NULL);
	tlib_testmalloc_count(0);
}

static void	test_strchr_child2(void) {
	ft_strchr(NULL, 'A');
}

void	test_strchr(void) {
	tlib_testprocess_ok(&test_strchr_child1);
	tlib_testprocess_segfault(&test_strchr_child2);
}
