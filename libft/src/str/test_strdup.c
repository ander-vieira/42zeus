#include "test.h"

static void	test_strdup_testone(char *str) {
	char	*result;

	tlib_mockmalloc_reset();
	result = ft_strdup(str);
	tlib_testresult_str(result, str, "ft_strdup(%S)", str);
	tlib_testmalloc_size(result, strlen(str) + 1, "ft_strdup(%S)", str);
	free(result);
	tlib_testmalloc_leak("ft_strdup(%S)", str);
}

static void	test_strdup_child1(void) {
	test_strdup_testone("ABCDE");
	test_strdup_testone("");
}

static void	test_strdup_child2(void) {
	tlib_mockmalloc_reset();
	tlib_mockmalloc_setmock(1);
	tlib_testresult_addr(ft_strdup("HOLA"), NULL, "ft_strdup(\"HOLA\") (with malloc fail)");
	tlib_testmalloc_leak("ft_strdup(\"HOLA\") (with malloc fail)");
}

static void	test_strdup_child3(void) {
	ft_strdup(NULL);
}

void	test_strdup(void) {
	tlib_testprocess_ok(&test_strdup_child1, NULL);
	tlib_testprocess_ok(&test_strdup_child2, "ft_strdup(\"HOLA\") (with malloc fail)");
	tlib_testprocess_segfault(&test_strdup_child3, "ft_strdup(NULL)");
}
