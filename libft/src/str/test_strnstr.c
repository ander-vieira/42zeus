#include "test.h"

//TODO

static void test_strnstr_testone(char *h, char *n, size_t len, char *expected) {
	tlib_testresult_addr(ft_strnstr(h, n, len), expected, "ft_strnstr(%S, %S, %z)", h, n, len);
}

static void	test_strnstr_child1(void) {
	char	*str;

	tlib_mockmalloc_reset();
	str = "ABCDE";
	test_strnstr_testone(str, "", 5, str);
	test_strnstr_testone(str, "A", 5, str);
	test_strnstr_testone(str, "ABC", 5, str);
	test_strnstr_testone(str, "ABCDE", 5, str);
	test_strnstr_testone(str, "C", 5, str + 2);
	test_strnstr_testone(str, "BCD", 5, str + 1);
	test_strnstr_testone(str, "F", 5, NULL);
	test_strnstr_testone(str, "CB", 5, NULL);
	test_strnstr_testone(str, "C", 2, NULL);
	test_strnstr_testone(str, "ABC", 2, NULL);
	test_strnstr_testone(str, "", 0, str);
	test_strnstr_testone(str, "ABC", 0, NULL);
	tlib_testmalloc_leak(NULL);
}

static void	test_strnstr_child2(void) {
	char	*str;

	tlib_mockmalloc_reset();
	str = "ABCDE";
	test_strnstr_testone(str, "", 10, str);
	test_strnstr_testone(str, "BCD", 10, str + 1);
	tlib_testmalloc_leak(NULL);
}

void	test_strnstr(void) {
	tlib_testprocess_ok(&test_strnstr_child1);
	tlib_testprocess_ok(&test_strnstr_child2);
}
