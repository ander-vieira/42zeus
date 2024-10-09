#include "test.h"

static void	test_substr_testone(char *str, unsigned int start, size_t len, char *expected) {
	char	*result;

	tlib_mockmalloc_reset();
	result = ft_substr(str, start, len);
	tlib_testresult_str(result, expected, "ft_substr(%S, %u, %z)", str, start, len);
	tlib_testmalloc_size(result, strlen(expected) + 1, "ft_substr(%S, %u, %z)", str, start, len);
	free(result);
	tlib_testmalloc_leak("ft_substr(%S, %u, %z)", str, start, len);
}

static void	test_substr_child1(void) {
	test_substr_testone("HOLA MUNDO", 0, 4, "HOLA");
	test_substr_testone("HOLA MUNDO", 3, 3, "A M");
	test_substr_testone("HOLA MUNDO", 5, 5, "MUNDO");
	test_substr_testone("HOLA MUNDO", 0, 0, "");
	test_substr_testone("HOLA MUNDO", 5, 0, "");
	test_substr_testone("HOLA MUNDO", 8, 5, "DO");
	test_substr_testone("HOLA MUNDO", 10, 5, "");
	test_substr_testone("HOLA MUNDO", 15, 5, "");
}

static void	test_substr_child2(void) {
	tlib_mockmalloc_reset();
	tlib_mockmalloc_setmock(1);
	tlib_testresult_addr(ft_substr("HOLA", 0, 2), NULL, "ft_substr(\"HOLA\", 0, 2) (with malloc fail)");
}

static void	test_substr_child3(void) {
	tlib_testresult_addr(ft_substr(NULL, 0, 2), NULL, "ft_substr(NULL, 0, 2)");
}

void	test_substr(void) {
	tlib_testprocess_ok(&test_substr_child1, NULL);
	tlib_testprocess_ok(&test_substr_child2, NULL);
	tlib_testprocess_ok(&test_substr_child3, NULL);
}
