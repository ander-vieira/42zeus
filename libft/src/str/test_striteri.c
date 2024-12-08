#include "test.h"

static t_bool	striteri_testing;
static char		*striteri_call;
static char		*striteri_str;
static size_t	striteri_str_len;
static char		striteri_checked[FUNPTR_CHECKED];
static size_t	striteri_called;

static void	test_striteri_start(char *call, char *str) {
	size_t	i;

	striteri_call = call;
	striteri_str = str;
	striteri_str_len = tlib_str_len(str);
	i = 0;
	while (i < FUNPTR_CHECKED) {
		striteri_checked[i] = 0;
		i++;
	}
	striteri_called = 0;
	striteri_testing = TRUE;
}

static void	test_striteri_stop() {
	striteri_testing = FALSE;
}

static void	test_striteri_fun(unsigned int i, char *c) {
	if (!striteri_testing)
		return ;
	tlib_testresult_custom(i < striteri_str_len,
		"%s called <fun> with an out of bounds index\n- (expected: less than %z, actual: %u)\n",
		striteri_call, striteri_str_len, i);
	tlib_testresult_custom(c == striteri_str + i,
		"%s called <fun> with an incorrect parameter\n- (expected: %p, actual: %p)\n",
		striteri_call, striteri_str + i, c);
	if (i < FUNPTR_CHECKED) {
		tlib_testresult_custom(striteri_checked[i] == 0,
			"%s called <fun> multiple times on position %u\n",
			striteri_call, i);
		striteri_checked[i] = 1;
	}
	striteri_called += 1;
}

static void	test_striteri_child1(void) {
	tlib_mockmalloc_reset();
	test_striteri_start("ft_striteri(\"HOLA\", <fun>)", "HOLA");
	ft_striteri(striteri_str, &test_striteri_fun);
	test_striteri_stop();
	tlib_testresult_custom(striteri_called == 4,
		"ft_striteri(\"HOLA\", <fun>) called <fun> an incorrect number of times\n- (expected: 4 calls, actual: %z calls)\n",
		striteri_called);
	tlib_testmalloc_leak("ft_striteri(\"HOLA\", <fun>)");
}

static void	test_striteri_child2(void) {
	tlib_mockmalloc_reset();
	test_striteri_start("ft_striteri(\"\", <fun>)", "");
	ft_striteri(striteri_str, &test_striteri_fun);
	test_striteri_stop();
	tlib_testresult_custom(striteri_called == 0,
		"ft_striteri(\"\", <fun>) called <fun> an incorrect number of times\n- (expected: 0 calls, actual: %z calls)\n",
		striteri_called);
	tlib_testmalloc_leak("ft_striteri(\"\", <fun>)");
}

static void	test_striteri_child3(void) {
	tlib_mockmalloc_reset();
	test_striteri_start("ft_striteri(NULL, <fun>)", NULL);
	ft_striteri(NULL, &test_striteri_fun);
	test_striteri_stop();
	tlib_testresult_custom(striteri_called == 0,
		"ft_striteri(NULL, <fun>) called <fun> an incorrect number of times\n- (expected: 0 calls, actual: %z calls)\n",
		striteri_called);
	tlib_testmalloc_leak("ft_striteri(NULL, <fun>)");
}

static void	test_striteri_child4(void) {
	tlib_mockmalloc_reset();
	ft_striteri("HOLA", NULL);
	tlib_testmalloc_leak("ft_striteri(\"HOLA\", NULL)");
}

void	test_striteri(void) {
	tlib_testprocess_ok(&test_striteri_child1, "ft_striteri(\"HOLA\", <fun>)");
	tlib_testprocess_ok(&test_striteri_child2, "ft_striteri(\"\", <fun>)");
	tlib_testprocess_ok(&test_striteri_child3, "ft_striteri(NULL, <fun>)");
	tlib_testprocess_ok(&test_striteri_child4, "ft_striteri(\"HOLA\", NULL)");
}
