#include "test.h"

static void	test_strjoin_testone(char *str1, char *str2, char *expected) {
	char	*result;

	tlib_mockmalloc_reset();
	result = ft_strjoin(str1, str2);
	tlib_testresult_str(result, expected, "ft_strjoin(%S, %S)", str1, str2);
	tlib_testmalloc_size(result, strlen(expected) + 1, "ft_strjoin(%S, %S)", str1, str2);
	free(result);
	tlib_testmalloc_leak("ft_strjoin(%S, %S)", str1, str2);
}

static void	test_strjoin_child1(void) {
	test_strjoin_testone("HOLA", " MUNDO", "HOLA MUNDO");
	test_strjoin_testone("HOLA", "", "HOLA");
	test_strjoin_testone("", "MUNDO", "MUNDO");
	test_strjoin_testone("", "", "");
}

static void	test_strjoin_child2(void) {
	tlib_mockmalloc_reset();
	tlib_mockmalloc_setmock(1);
	tlib_testresult_addr(ft_strjoin("HOLA", " MUNDO"), NULL, "ft_strjoin(\"HOLA\", \" MUNDO\") (with malloc fail)");
}

static void	test_strjoin_child3(void) {
	tlib_testresult_addr(ft_strjoin(NULL, " MUNDO"), NULL, "ft_strjoin(NULL, \" MUNDO\")");
}

static void	test_strjoin_child4(void) {
	tlib_testresult_addr(ft_strjoin("HOLA", NULL), NULL, "ft_strjoin(\"HOLA\", NULL)");
}

void	test_strjoin(void) {
	tlib_testprocess_ok(&test_strjoin_child1, NULL);
	tlib_testprocess_ok(&test_strjoin_child2, "ft_strjoin(\"HOLA\", \" MUNDO\") (with malloc fail)");
	tlib_testprocess_ok(&test_strjoin_child3, "ft_strjoin(NULL, \" MUNDO\")");
	tlib_testprocess_ok(&test_strjoin_child4, "ft_strjoin(\"HOLA\", NULL)");
}
