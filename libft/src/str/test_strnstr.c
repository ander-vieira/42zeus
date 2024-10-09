#include "test.h"

//TODO upgrade tests

static void test_strnstr_testone(char *h, char *n, size_t len, char *expected) {
	tlib_testresult_addr(ft_strnstr(h, n, len), expected, "ft_strnstr(%S (%p), %S, %z)", h, h, n, len);
}

static void	test_strnstr_child1(void) {
	char	*str;

	tlib_mockmalloc_reset();
	str = "HOLA";
	test_strnstr_testone(str, "", 4, str);
	test_strnstr_testone(str, "H", 4, str);
	test_strnstr_testone(str, "L", 4, str + 2);
	test_strnstr_testone(str, "F", 4, NULL);
	test_strnstr_testone(str, "HO", 4, str);
	test_strnstr_testone(str, "OLA", 4, str + 1);
	test_strnstr_testone(str, "OH", 4, NULL);
	test_strnstr_testone(str, "L", 2, NULL);
	test_strnstr_testone(str, "OL", 2, NULL);
	test_strnstr_testone(str, "", 0, str);
	test_strnstr_testone(str, "H", 0, NULL);
	test_strnstr_testone(str, "OL", 0, NULL);
	tlib_testmalloc_leak(NULL);
}

static void	test_strnstr_child2(void) {
	char	*str;

	tlib_mockmalloc_reset();
	str = "HOLA";
	test_strnstr_testone(str, "", 7, str);
	test_strnstr_testone(str, "OL", 7, str + 1);
	test_strnstr_testone(str, "F", 7, NULL);
	tlib_testmalloc_leak(NULL);
}

void	test_strnstr(void) {
	tlib_testprocess_ok(&test_strnstr_child1, NULL);
	tlib_testprocess_ok(&test_strnstr_child2, NULL);
}
