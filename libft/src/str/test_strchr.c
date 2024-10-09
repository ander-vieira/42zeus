#include "test.h"

static void test_strchr_testone(char *str, int c, char *expected) {
	tlib_mockmalloc_reset();
	tlib_testresult_addr(ft_strchr(str, c), expected, "ft_strchr(%S (%p), %c (%d))", str, str, c, c);
	tlib_testmalloc_leak("ft_strchr(%S (%p), %c (%d))", str, str, c, c);
}

static void	test_strchr_child1(void) {
	char	*str;

	str = "ALOHA";
	test_strchr_testone(str, 'A', str);
	test_strchr_testone(str, 'O', str + 2);
	test_strchr_testone(str, '\0', str + 5);
	test_strchr_testone(str, 'F', NULL);
	test_strchr_testone(str, 'A' + 256, str);
	test_strchr_testone(str, 'F' + 256, NULL);
}

static void	test_strchr_child2(void) {
	ft_strchr(NULL, 'A');
}

void	test_strchr(void) {
	tlib_testprocess_ok(&test_strchr_child1, NULL);
	tlib_testprocess_segfault(&test_strchr_child2, "ft_strchr(NULL, 'A')");
}
