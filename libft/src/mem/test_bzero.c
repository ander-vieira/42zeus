#include "test.h"

static void	test_bzero_child1(void)
{
	char	buf[5];

	tlib_mockmalloc_reset();
	ft_bzero(buf, 5);
	tlib_testresult_bool(!memcmp(buf, "\0\0\0\0\0", 5));
	tlib_testmalloc_count(0);
}

static void	test_bzero_child2(void)
{
	char	buf[5];

	tlib_mockmalloc_reset();
	strcpy(buf, "ASDF");
	ft_bzero(buf, 0);
	tlib_testresult_bool(!memcmp(buf, "ASDF", 5));
	tlib_testmalloc_count(0);
}

static void	test_bzero_child3(void)
{
	ft_bzero(NULL, 0);
}

static void	test_bzero_child4(void)
{
	ft_bzero(NULL, 5);
}

void	test_bzero(void)
{
	tlib_test_process(&test_bzero_child1, PRESULT_OK);
	tlib_test_process(&test_bzero_child2, PRESULT_OK);
	tlib_test_process(&test_bzero_child3, PRESULT_OK);
	tlib_test_process(&test_bzero_child4, PRESULT_SEGFAULT);
}
