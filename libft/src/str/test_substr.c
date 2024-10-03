#include "test.h"

static void	test_substr_testone(char *str, unsigned int start, size_t len,
	char *expected) {
	char	*result;

	tlib_mockmalloc_reset();
	result = ft_substr(str, start, len);
	tlib_testresult_raw(result != NULL && !strcmp(result, expected));
	tlib_testmalloc_size(result, strlen(expected) + 1, "ft_substr(%S, %u, %z)", str, start, len);
	free(result);
	tlib_testmalloc_leak("ft_substr(%S, %u, %z)", str, start, len);
}

static void	test_substr_child1(void) {
	test_substr_testone("ABCDEF", 0, 2, "AB");
	test_substr_testone("ABCDEF", 2, 3, "CDE");
	test_substr_testone("ABCDEF", 3, 3, "DEF");
	test_substr_testone("ABCDEF", 3, 0, "");
	test_substr_testone("ABCDEF", 4, 4, "EF");
	test_substr_testone("ABCDEF", 8, 4, "");
}

static void	test_substr_child2(void) {
	tlib_mockmalloc_reset();
	tlib_mockmalloc_setmock(1);
	tlib_testresult_raw(ft_substr("ABCDEF", 0, 4) == NULL);
}

static void	test_substr_child3(void) {
	tlib_testresult_raw(ft_substr(NULL, 0, 4) == NULL);
}

void	test_substr(void) {
	tlib_testprocess_ok(&test_substr_child1);
	tlib_testprocess_ok(&test_substr_child2);
	tlib_testprocess_ok(&test_substr_child3);
}
