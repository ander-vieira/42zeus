#include "test.h"

static t_bool	strmapi_testing;
static char		*strmapi_call;
static char		*strmapi_str;
static size_t	strmapi_str_len;
static char		*strmapi_expected;
static char		strmapi_checked[FUNPTR_CHECKED];
static size_t	strmapi_called;

static void	test_strmapi_start(char *call, char *str, char *expected) {
	size_t	i;

	strmapi_call = call;
	strmapi_str = str;
	strmapi_str_len = tlib_str_len(str);
	strmapi_expected = expected;
	i = 0;
	while (i < FUNPTR_CHECKED) {
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
		"%s called <fun> with an out of bounds index\n- (expected: less than %z, actual: %u)\n",
		strmapi_call, strmapi_str_len, i);
	tlib_testresult_custom(c == strmapi_str[i],
		"%s called <fun> with an incorrect parameter\n- (expected: %c, actual: %c)\n",
		strmapi_call, strmapi_str[i], c);
	if (i < FUNPTR_CHECKED) {
		tlib_testresult_custom(strmapi_checked[i] == 0,
			"%s called <fun> multiple times on position %u\n",
			strmapi_call, i);
		strmapi_checked[i] = 1;
	}
	strmapi_called += 1;
	if (i >= strmapi_str_len)
		return ('\0');
	return (strmapi_expected[i % strmapi_str_len]);
}

static void	test_strmapi_child1(void) {
	char	*str;
	char	*str2;

	str = "HOLA";
	tlib_mockmalloc_reset();
	test_strmapi_start("ft_strmapi(\"HOLA\", <fun>)", str, "QWER");
	str2 = ft_strmapi(str, &test_strmapi_fun);
	test_strmapi_stop();
	tlib_testresult_custom(strmapi_called == 4,
		"ft_strmapi(\"HOLA\", <fun>) called <fun> an incorrect number of times\n- (expected: 4 calls, actual: %z calls)\n",
		strmapi_called);
	tlib_testresult_str(str2, "QWER", "ft_strmapi(\"HOLA\", <fun>)");
	tlib_testmalloc_size(str2, 5, "ft_strmapi(\"HOLA\", <fun>)");
	free(str2);
	tlib_testmalloc_leak("ft_strmapi(\"HOLA\", <fun>)");
}

static void	test_strmapi_child2(void) {
	char	*str;
	char	*str2;

	str = "";
	tlib_mockmalloc_reset();
	test_strmapi_start("ft_strmapi(\"\", <fun>)", str, "");
	str2 = ft_strmapi(str, &test_strmapi_fun);
	test_strmapi_stop();
	tlib_testresult_custom(strmapi_called == 0,
		"ft_strmapi(\"\", <fun>) called <fun> an incorrect number of times\n- (expected: 0 calls, actual: %z calls)\n",
		strmapi_called);
	tlib_testresult_str(str2, "", "ft_strmapi(\"\", <fun>)");
	tlib_testmalloc_size(str2, 1, "ft_strmapi(\"\", <fun>)");
	free(str2);
	tlib_testmalloc_leak("ft_strmapi(\"\", <fun>)");
}

static void	test_strmapi_child3(void) {
	char	*str;

	str = "HOLA";
	tlib_mockmalloc_reset();
	tlib_mockmalloc_setmock(1);
	test_strmapi_start("ft_strmapi(\"HOLA\", <fun>) (with malloc fail)", str, "QWER");
	tlib_testresult_addr(ft_strmapi(str, &test_strmapi_fun), NULL, "ft_strmapi(\"HOLA\", <fun>) with malloc fail");
	test_strmapi_stop();
	tlib_testresult_custom(strmapi_called == 0,
		"ft_strmapi(\"HOLA\", <fun>) (with malloc fail) called <fun> an incorrect number of times\n- (expected: 0 calls, actual: %z calls)\n",
		strmapi_called);
	tlib_testmalloc_leak("ft_strmapi(\"HOLA\", <fun>) (with malloc fail)");
}

static void	test_strmapi_child4(void) {
	tlib_mockmalloc_reset();
	tlib_testresult_addr(ft_strmapi(NULL, &test_strmapi_fun), NULL, "ft_strmapi(NULL, <fun>)");
	tlib_testmalloc_leak("ft_strmapi(NULL, <fun>)");
}

static void	test_strmapi_child5(void) {
	tlib_mockmalloc_reset();
	tlib_testresult_addr(ft_strmapi("HOLA", NULL), NULL, "ft_strmapi(\"HOLA\", NULL)");
	tlib_testmalloc_leak("ft_strmapi(\"HOLA\", NULL)");
}

void	test_strmapi(void) {
	tlib_testprocess_ok(&test_strmapi_child1, "ft_strmapi(\"HOLA\", <fun>)");
	tlib_testprocess_ok(&test_strmapi_child2, "ft_strmapi(\"\", <fun>)");
	tlib_testprocess_ok(&test_strmapi_child3, "ft_strmapi(\"HOLA\", <fun>) (with malloc fail)");
	tlib_testprocess_ok(&test_strmapi_child4, "ft_strmapi(NULL, <fun>)");
	tlib_testprocess_ok(&test_strmapi_child5, "ft_strmapi(\"HOLA\", NULL)");
}
