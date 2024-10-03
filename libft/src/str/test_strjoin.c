#include "test.h"

static void	test_strjoin_testone(char *str1, char *str2, char *expected) {
	char	*result;

	tlib_mockmalloc_reset();
	result = ft_strjoin(str1, str2);
	tlib_testresult_raw(result != NULL && !strcmp(result, expected));
	tlib_testmalloc_size(result, strlen(expected) + 1, "ft_strjoin(TODO)");
	free(result);
	tlib_testmalloc_leak();
}

static void	test_strjoin_child1(void) {
	test_strjoin_testone("HOLA", "MUNDO", "HOLAMUNDO");
	test_strjoin_testone("HOLA", "", "HOLA");
	test_strjoin_testone("", "MUNDO", "MUNDO");
	test_strjoin_testone("", "", "");
}

static void	test_strjoin_child2(void) {
	tlib_mockmalloc_reset();
	tlib_mockmalloc_setmock(1);
	tlib_testresult_raw(ft_strjoin("HOLA", "MUNDO") == NULL);
}

static void	test_strjoin_child3(void) {
	tlib_testresult_raw(ft_strjoin(NULL, "MUNDO") == NULL);
}

static void	test_strjoin_child4(void) {
	tlib_testresult_raw(ft_strjoin("HOLA", NULL) == NULL);
}

void	test_strjoin(void) {
	tlib_testprocess_ok(&test_strjoin_child1);
	tlib_testprocess_ok(&test_strjoin_child2);
	tlib_testprocess_ok(&test_strjoin_child3);
	tlib_testprocess_ok(&test_strjoin_child4);
}
