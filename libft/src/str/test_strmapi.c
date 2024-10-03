#include "test.h"

static char		*g_str;
static t_uint	g_i;

static char	test_strmapi_fun1(unsigned int i, char c)
{
	tlib_testresult_bool(i == g_i && c == g_str[g_i]);
	g_i++;
	if (i == 0)
		return (c + 1);
	return (c);
}

static char	test_strmapi_fun2(unsigned int i, char c)
{
	(void)i;
	return (c);
}

static void	test_strmapi_testone(char *str)
{
	char	*str2;

	g_str = str;
	g_i = 0;
	tlib_mockmalloc_reset();
	str2 = ft_strmapi(str, &test_strmapi_fun1);
	if (strlen(str) == 0)
		tlib_testresult_bool(strlen(str2) == 0);
	else
		tlib_testresult_bool(str2[0] == str[0] + 1 && !strcmp(str2 + 1, str + 1));
	tlib_testmalloc_size(str2, strlen(str) + 1);
	tlib_testmalloc_count(1);
	free(str2);
}

static void	test_strmapi_child1(void)
{
	test_strmapi_testone("ABCD");
	test_strmapi_testone("");
}

static void	test_strmapi_child2(void)
{
	tlib_mockmalloc_reset();
	tlib_mockmalloc_setmock(1);
	tlib_testresult_bool(ft_strmapi("HOLA", &test_strmapi_fun2) == NULL);
}

static void	test_strmapi_child3(void)
{
	tlib_testresult_bool(ft_strmapi(NULL, &test_strmapi_fun2) == NULL);
}

static void	test_strmapi_child4(void)
{
	tlib_testresult_bool(ft_strmapi("HOLA", NULL) == NULL);
}

void	test_strmapi(void)
{
	tlib_test_process(&test_strmapi_child1, PRESULT_OK);
	tlib_test_process(&test_strmapi_child2, PRESULT_OK);
	tlib_test_process(&test_strmapi_child3, PRESULT_OK);
	tlib_test_process(&test_strmapi_child4, PRESULT_OK);
}
