#include "test.h"

static void	test_memcmp_child1(void) {
	tlib_mockmalloc_reset();
	tlib_testresult_raw(!ft_memcmp("ASDFG", "ASDFG", 5));
	tlib_testresult_raw(ft_memcmp("ASDFG", "ASDFH", 5));
	tlib_testresult_raw(ft_memcmp("ASDFG", "ASFFG", 5));
	tlib_testresult_raw(!ft_memcmp("ASDFG", "ASDFH", 4));
	tlib_testresult_raw(!ft_memcmp("ASDFG", "ASD", 3));
	tlib_testresult_raw(!ft_memcmp("ASD", "ASDFG", 3));
	tlib_testresult_raw(ft_memcmp("ASD\0G", "ASD\0H", 5));
	tlib_testmalloc_leak();
}

static void	test_memcmp_child2(void) {
	tlib_mockmalloc_reset();
	tlib_testresult_raw(!ft_memcmp(NULL, "ASDFG", 0));
	tlib_testresult_raw(!ft_memcmp("ASDFG", NULL, 0));
	tlib_testresult_raw(!ft_memcmp(NULL, NULL, 0));
	tlib_testmalloc_leak();
}

static void	test_memcmp_child3(void) {
	ft_memcmp(NULL, "ASDFG", 5);
}

static void	test_memcmp_child4(void) {
	ft_memcmp("ASDFG", NULL, 5);
}

void	test_memcmp(void) {
	tlib_testprocess_ok(&test_memcmp_child1);
	tlib_testprocess_ok(&test_memcmp_child2);
	tlib_testprocess_segfault(&test_memcmp_child3);
	tlib_testprocess_segfault(&test_memcmp_child4);
}
