#include "test.h"

static void test_strchr_testone(char *str, int c, char *expected) {
	tlib_testresult_addr(ft_strchr(str, c), expected, "ft_strchr(%S, %c)", str, c);
}

static void	test_strchr_child1(void) {
	char	*str;

	tlib_mockmalloc_reset();
	str = "ASDFA";
	test_strchr_testone(str, 'A', str);
	test_strchr_testone(str, 'D', str + 2);
	test_strchr_testone(str, '\0', str + 5);
	test_strchr_testone(str, 'H', NULL);
	test_strchr_testone(str, 'A' + 256, str);
	test_strchr_testone(str, 'H' + 256, NULL);
	tlib_testmalloc_leak(NULL);
}

static void	test_strchr_child2(void) {
	ft_strchr(NULL, 'A');
}

void	test_strchr(void) {
	tlib_testprocess_ok(&test_strchr_child1);
	tlib_testprocess_segfault(&test_strchr_child2);
}
