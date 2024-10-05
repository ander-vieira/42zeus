#include "test.h"

//TODO test positive vs negative values, not just equal/different

static void	test_strncmp_testequal(char *s1, char *s2, size_t n) {
	tlib_testresult_int(ft_strncmp(s1, s2, n), 0, "ft_strncmp(%S, %S, %z)", s1, s2, n);
}

static void	test_strncmp_testdiff(char *s1, char *s2, size_t n) {
	tlib_testresult_nonzero(ft_strncmp(s1, s2, n), "ft_strncmp(%S, %S, %z)", s1, s2, n);
}

static void	test_strncmp_child1(void) {
	tlib_mockmalloc_reset();
	test_strncmp_testequal("ASDFG", "ASDFG", 5);
	test_strncmp_testequal("ASDFG", "ASDFG", 10);
	test_strncmp_testequal("ASDFG", "ASDFG", 3);
	test_strncmp_testdiff("ASDFG", "ASDFH", 5);
	test_strncmp_testdiff("ASDFG", "ASDFH", 10);
	test_strncmp_testequal("ASDFG", "ASDFH", 3);
	test_strncmp_testdiff("ASDFG", "SSDFG", 5);
	test_strncmp_testdiff("ASDFG", "ASD", 5);
	test_strncmp_testequal("ASDFG", "ASD", 3);
	test_strncmp_testdiff("ASD", "ASDFG", 5);
	test_strncmp_testequal("ASD", "ASDFG", 3);
	test_strncmp_testdiff("", "ASDFG", 5);
	test_strncmp_testequal("ASDFG", "SSDFG", 0);
	test_strncmp_testequal("ASDFG", "", 0);
	test_strncmp_testequal("", "SSDFG", 0);
	tlib_testmalloc_leak(NULL);
}

static void	test_strncmp_child2(void) {
	tlib_mockmalloc_reset();
	test_strncmp_testequal(NULL, "ASDFG", 0);
	test_strncmp_testequal("ASDFG", NULL, 0);
	test_strncmp_testequal(NULL, NULL, 0);
	tlib_testmalloc_leak(NULL);
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
