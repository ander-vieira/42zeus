#include "test.h"

static char			*g_str;
static unsigned int	g_i;

static void	test_striteri_fun1(unsigned int i, char *c) {
	tlib_testresult_raw(i == g_i && c == g_str + g_i);
	g_i++;
}

static void	test_striteri_fun2(unsigned int i, char *c) {
	(void)i;
	(void)c;
}

static void	test_striteri_testone(char *str) {
	g_str = str;
	g_i = 0;
	tlib_mockmalloc_reset();
	ft_striteri(g_str, &test_striteri_fun1);
	tlib_testresult_raw(g_i == strlen(str));
}

static void	test_striteri_child1(void) {
	test_striteri_testone("HOLA");
	test_striteri_testone("");
	tlib_testmalloc_leak(NULL);
}

static void	test_striteri_child2(void) {
	ft_striteri(NULL, &test_striteri_fun2);
}

static void	test_striteri_child3(void) {
	ft_striteri("HOLA", NULL);
}

void	test_striteri(void) {
	tlib_testprocess_ok(&test_striteri_child1);
	tlib_testprocess_ok(&test_striteri_child2);
	tlib_testprocess_ok(&test_striteri_child3);
}
