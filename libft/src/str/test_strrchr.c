#include "test.h"

static void test_strrchr_testone(char *str, int c, char *expected) {
	tlib_testresult_addr(ft_strrchr(str, c), expected, "ft_strrchr(%S (%p), %c (%d))", str, str, c, c);
}

static void	test_strrchr_child1(void) {
	char	*str;

	tlib_mockmalloc_reset();
	str = "ALOHA";
	test_strrchr_testone(str, 'A', str + 4);
	test_strrchr_testone(str, 'O', str + 2);
	test_strrchr_testone(str, '\0', str + 5);
	test_strrchr_testone(str, 'F', NULL);
	test_strrchr_testone(str, 'A' + 256, str + 4);
	test_strrchr_testone(str, 'F' + 256, NULL);
	tlib_testmalloc_leak(NULL);
}

static void	test_strrchr_child2(void) {
	ft_strrchr(NULL, 'A');
}

void	test_strrchr(void) {
	tlib_testprocess_ok(&test_strrchr_child1, NULL);
	tlib_testprocess_segfault(&test_strrchr_child2, NULL);
}
