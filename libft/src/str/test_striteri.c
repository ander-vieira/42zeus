#include "test.h"

static char		*g_str;
static t_uint	g_i;

static void	test_striteri_fun1(t_uint i, char *c)
{
	tlib_testresult_bool(i == g_i && c == g_str + g_i);
	g_i++;
}

static void	test_striteri_fun2(t_uint i, char *c)
{
	(void)i;
	(void)c;
}

static void	test_striteri_testone(char *str)
{
	g_str = str;
	g_i = 0;
	tlib_mockmalloc_reset();
	ft_striteri(g_str, &test_striteri_fun1);
	tlib_testresult_bool(g_i == strlen(str));
	tlib_testmalloc_count(0);
}

static void	test_striteri_child1(void)
{
	test_striteri_testone("HOLA");
	test_striteri_testone("");
}

static void	test_striteri_child2(void)
{
	ft_striteri(NULL, &test_striteri_fun2);
}

static void	test_striteri_child3(void)
{
	ft_striteri("HOLA", NULL);
}

void	test_striteri(void)
{
	tlib_test_process(&test_striteri_child1, PRESULT_OK);
	tlib_test_process(&test_striteri_child2, PRESULT_OK);
	tlib_test_process(&test_striteri_child3, PRESULT_OK);
}
