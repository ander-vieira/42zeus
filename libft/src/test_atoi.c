#include "test.h"

static void	test_atoi_child1(void) {
	tlib_mockmalloc_reset();
	tlib_testresult_bool(ft_atoi("4") == 4);
	tlib_testresult_bool(ft_atoi("42") == 42);
	tlib_testresult_bool(ft_atoi("4242") == 4242);
	tlib_testresult_bool(ft_atoi("0") == 0);
	tlib_testresult_bool(ft_atoi("+4") == 4);
	tlib_testresult_bool(ft_atoi("+42") == 42);
	tlib_testresult_bool(ft_atoi("+4242") == 4242);
	tlib_testresult_bool(ft_atoi("+0") == 0);
	tlib_testresult_bool(ft_atoi("-6") == -6);
	tlib_testresult_bool(ft_atoi("-777") == -777);
	tlib_testresult_bool(ft_atoi("-4343") == -4343);
	tlib_testresult_bool(ft_atoi("-0") == 0);
	tlib_testresult_bool(ft_atoi("2147483647") == 2147483647);
	tlib_testresult_bool(ft_atoi("+2147483647") == 2147483647);
	tlib_testresult_bool(ft_atoi("-2147483648") == -2147483648);
	tlib_testresult_bool(ft_atoi("2147483648") == -2147483648);
	tlib_testresult_bool(ft_atoi("+2147483648") == -2147483648);
	tlib_testresult_bool(ft_atoi("88aaa") == 88);
	tlib_testresult_bool(ft_atoi("100b.g") == 100);
	tlib_testresult_bool(ft_atoi("f55") == 0);
	tlib_testresult_bool(ft_atoi("500  13") == 500);
	tlib_testresult_bool(ft_atoi(" 34") == 34);
	tlib_testresult_bool(ft_atoi("   51") == 51);
	tlib_testresult_bool(ft_atoi("\n681") == 681);
	tlib_testresult_bool(ft_atoi("  \n \t 7007") == 7007);
	tlib_testresult_bool(ft_atoi("   124aaa5") == 124);
	tlib_testresult_bool(ft_atoi(" +153") == 153);
	tlib_testresult_bool(ft_atoi(" -169") == -169);
	tlib_testresult_bool(ft_atoi("  \n -2147483648  5a7") == -2147483648);
	tlib_testresult_bool(ft_atoi("+-101") == 0);
	tlib_testresult_bool(ft_atoi("-+102") == 0);
	tlib_testresult_bool(ft_atoi("--103") == 0);
	tlib_testresult_bool(ft_atoi("++104") == 0);
	tlib_testresult_bool(ft_atoi("   -+117") == 0);
	tlib_testmalloc_count(0);
}

static void	test_atoi_child2(void) {
	ft_atoi(NULL);
}

void	test_atoi(void) {
	tlib_test_process(&test_atoi_child1, PRESULT_OK);
	tlib_test_process(&test_atoi_child2, PRESULT_SEGFAULT);
}
