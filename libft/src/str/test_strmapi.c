#include "test.h"

static t_bool	strmapi_testing;
static char		*strmapi_str;
static size_t	strmapi_str_len;
static char		*strmapi_expected;
static char		strmapi_checked[10];
static size_t	strmapi_called;

static void	test_strmapi_start(char *str, char *expected) {
	size_t	i;

	strmapi_str = str;
	strmapi_str_len = tlib_str_len(str);
	strmapi_expected = expected;
	i = 0;
	while (i < strmapi_str_len) {
		strmapi_checked[i] = 0;
		i++;
	}
	strmapi_called = 0;
	strmapi_testing = TRUE;
}

static void	test_strmapi_stop() {
	strmapi_testing = FALSE;
}

static char	test_strmapi_fun(unsigned int i, char c) {
	if (!strmapi_testing)
		return (c);
	tlib_testresult_custom(i < strmapi_str_len,
		"ft_strmapi(%S, %p) has been called with an out of bounds index (%d)\n", strmapi_str, &test_strmapi_fun, i);
	tlib_testresult_custom(c == strmapi_str[i],
		"ft_strmapi(%S, %p) has been called with an incorrect parameter\n- (expected: %c, actual: %c)\n", strmapi_str, &test_strmapi_fun, strmapi_str[i], c);
	if (i < strmapi_str_len) {
		tlib_testresult_custom(strmapi_checked[i] == 0,
			"ft_strmapi(%S, %p) has been called multiple times on position %u\n", strmapi_str, &test_strmapi_fun, i);
		strmapi_checked[i] = 1;
	}
	strmapi_called += 1;
	if (strmapi_str_len == 0)
		return ('\0');
	return (strmapi_expected[i % strmapi_str_len]);
}

static void	test_strmapi_testone(char *str, char *expected) {
	char	*str2;

	tlib_mockmalloc_reset();
	test_strmapi_start(str, expected);
	str2 = ft_strmapi(str, &test_strmapi_fun);
	test_strmapi_stop();
	tlib_testresult_custom(strmapi_called == tlib_str_len(str),
		"ft_strmapi(%S, %p) has called its function an incorrect number of times\n- (expected: %z calls, actual: %z calls)\n", str, &test_strmapi_fun, tlib_str_len(str), strmapi_called);
	tlib_testresult_str(str2, expected, "ft_strmapi(%S, %p)", str, &test_strmapi_fun);
	tlib_testmalloc_size(str2, tlib_str_len(str) + 1, "ft_strmapi(%S, %p)", str, &test_strmapi_fun);
	free(str2);
	tlib_testmalloc_leak("ft_strmapi(%S, %p)", str, &test_strmapi_fun);
}

static void	test_strmapi_child1(void) {
	test_strmapi_testone("HOLA", "QWER");
	test_strmapi_testone("", "");
}

static void	test_strmapi_child2(void) {
	tlib_mockmalloc_reset();
	tlib_mockmalloc_setmock(1);
	test_strmapi_start("HOLA", "QWER");
	tlib_testresult_addr(ft_strmapi("HOLA", &test_strmapi_fun), NULL, "ft_strmapi(\"HOLA\", %p) with malloc fail", test_strmapi_fun);
	test_strmapi_stop();
	tlib_testresult_custom(strmapi_called == 0,
		"ft_strmapi(\"HOLA\", %p) (with malloc fail) has called its function an incorrect number of times\n- (expected: 0 calls, actual: %z calls)\n", &test_strmapi_fun, strmapi_called);
	tlib_testmalloc_leak("ft_strmapi(\"HOLA\", %p) (with malloc fail)", &test_strmapi_fun);
}

static void	test_strmapi_child3(void) {
	tlib_testresult_addr(ft_strmapi(NULL, &test_strmapi_fun), NULL, "ft_strmapi(NULL, %p)", &test_strmapi_fun);
}

static void	test_strmapi_child4(void) {
	tlib_testresult_addr(ft_strmapi("HOLA", NULL), NULL, "ft_strmapi(\"HOLA\", NULL)");
}

void	test_strmapi(void) {
	tlib_testprocess_ok(&test_strmapi_child1);
	tlib_testprocess_ok(&test_strmapi_child2);
	tlib_testprocess_ok(&test_strmapi_child3);
	tlib_testprocess_ok(&test_strmapi_child4);
}
