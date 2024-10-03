#include "test.h"

static void	test_memcmp_testequal(char *s1, char *s2, size_t n) {
	tlib_testresult_false(ft_memcmp(s1, s2, n), "ft_memcmp(%S, %S, %z)", s1, s2, n);
}

static void	test_memcmp_testdiff(char *s1, char *s2, size_t n) {
	tlib_testresult_true(ft_memcmp(s1, s2, n), "ft_memcmp(%S, %S, %z)", s1, s2, n);
}

static void	test_memcmp_child1(void) {
	tlib_mockmalloc_reset();
	test_memcmp_testequal("ASDFG", "ASDFG", 5);
	test_memcmp_testdiff("ASDFG", "ASDFH", 5);
	test_memcmp_testdiff("ASDFG", "ASFFG", 5);
	test_memcmp_testequal("ASDFG", "ASDFH", 4);
	test_memcmp_testequal("ASDFG", "ASD", 3);
	test_memcmp_testequal("ASD", "ASDFG", 3);
	tlib_testmalloc_leak(NULL);
}

static void	test_memcmp_child2(void) {
	tlib_mockmalloc_reset();
	test_memcmp_testequal(NULL, "ASDFG", 0);
	test_memcmp_testequal("ASDFG", NULL, 0);
	test_memcmp_testequal(NULL, NULL, 0);
	tlib_testmalloc_leak(NULL);
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
