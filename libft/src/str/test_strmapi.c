#include "test.h"

//TODO upgrade tests

static char			*strmapi_str;
static unsigned int	strmapi_called;

static char	test_strmapi_fun1(unsigned int i, char c) {
	tlib_testresult_raw(i == strmapi_called && c == strmapi_str[strmapi_called]);
	strmapi_called++;
	if (i == 0)
		return (c + 1);
	return (c);
}

static char	test_strmapi_fun2(unsigned int i, char c) {
	(void)i;
	return (c);
}

static void	test_strmapi_testone(char *str) {
	char	*str2;

	strmapi_str = str;
	strmapi_called = 0;
	tlib_mockmalloc_reset();
	str2 = ft_strmapi(str, &test_strmapi_fun1);
	if (strlen(str) == 0)
		tlib_testresult_raw(strlen(str2) == 0);
	else
		tlib_testresult_raw(str2[0] == str[0] + 1 && !strcmp(str2 + 1, str + 1));
	tlib_testmalloc_size(str2, strlen(str) + 1, "ft_strmapi(%S, %p)", str, &test_strmapi_fun1);
	free(str2);
	tlib_testmalloc_leak("ft_strmapi(%S, %p)", str, &test_strmapi_fun1);
}

static void	test_strmapi_child1(void) {
	test_strmapi_testone("ABCD");
	test_strmapi_testone("");
}

static void	test_strmapi_child2(void) {
	tlib_mockmalloc_reset();
	tlib_mockmalloc_setmock(1);
	tlib_testresult_raw(ft_strmapi("HOLA", &test_strmapi_fun2) == NULL);
}

static void	test_strmapi_child3(void) {
	tlib_testresult_raw(ft_strmapi(NULL, &test_strmapi_fun2) == NULL);
}

static void	test_strmapi_child4(void) {
	tlib_testresult_raw(ft_strmapi("HOLA", NULL) == NULL);
}

void	test_strmapi(void) {
	tlib_testprocess_ok(&test_strmapi_child1);
	tlib_testprocess_ok(&test_strmapi_child2);
	tlib_testprocess_ok(&test_strmapi_child3);
	tlib_testprocess_ok(&test_strmapi_child4);
}
