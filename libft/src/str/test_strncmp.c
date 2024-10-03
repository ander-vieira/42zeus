#include "test.h"

static void	test_strncmp_child1(void) {
	tlib_mockmalloc_reset();
	tlib_testresult_raw(!ft_strncmp("ASDFG", "ASDFG", 5));
	tlib_testresult_raw(!ft_strncmp("ASDFG", "ASDFG", 10));
	tlib_testresult_raw(!ft_strncmp("ASDFG", "ASDFG", 3));
	tlib_testresult_raw(ft_strncmp("ASDFG", "ASDFH", 5));
	tlib_testresult_raw(ft_strncmp("ASDFG", "ASDFH", 10));
	tlib_testresult_raw(!ft_strncmp("ASDFG", "ASDFH", 3));
	tlib_testresult_raw(ft_strncmp("ASDFG", "SSDFG", 5));
	tlib_testresult_raw(ft_strncmp("ASDFG", "ASD", 5));
	tlib_testresult_raw(!ft_strncmp("ASDFG", "ASD", 3));
	tlib_testresult_raw(ft_strncmp("ASD", "ASDFG", 5));
	tlib_testresult_raw(!ft_strncmp("ASD", "ASDFG", 3));
	tlib_testresult_raw(ft_strncmp("", "ASDFG", 5));
	tlib_testresult_raw(!ft_strncmp("ASDFG", "SSDFG", 0));
	tlib_testresult_raw(!ft_strncmp("ASDFG", "", 0));
	tlib_testresult_raw(!ft_strncmp("", "ASDFG", 0));
	tlib_testmalloc_leak();
}

static void	test_strncmp_child2(void) {
	tlib_mockmalloc_reset();
	tlib_testresult_raw(!ft_strncmp(NULL, "ASDFG", 0));
	tlib_testresult_raw(!ft_strncmp("ASDFG", NULL, 0));
	tlib_testresult_raw(!ft_strncmp(NULL, NULL, 0));
	tlib_testmalloc_leak();
}

static void	test_strncmp_child3(void) {
	ft_strncmp("ASDFG", NULL, 5);
}

static void	test_strncmp_child4(void) {
	ft_strncmp(NULL, "ASDFG", 5);
}

void	test_strncmp(void) {
	tlib_testprocess_ok(&test_strncmp_child1);
	tlib_testprocess_ok(&test_strncmp_child2);
	tlib_testprocess_segfault(&test_strncmp_child3);
	tlib_testprocess_segfault(&test_strncmp_child4);
}
