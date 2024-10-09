#include "test.h"

//TODO test positive vs negative values, not just equal/different

static void	test_memcmp_testequal(char *s1, char *s2, size_t n) {
	tlib_testresult_int(ft_memcmp(s1, s2, n), 0, "ft_memcmp(%S, %S, %z)", s1, s2, n);
}

static void	test_memcmp_testdiff(char *s1, char *s2, size_t n) {
	tlib_testresult_nonzero(ft_memcmp(s1, s2, n), "ft_memcmp(%S, %S, %z)", s1, s2, n);
}

static void	test_memcmp_child1(void) {
	tlib_mockmalloc_reset();
	test_memcmp_testequal("HOLA", "HOLA", 5);
	test_memcmp_testdiff("HOLA", "HOLE", 5);
	test_memcmp_testdiff("HOLA", "HALA", 5);
	test_memcmp_testequal("HOLA", "HOLE", 3);
	test_memcmp_testdiff("HOLA", "HALA", 3);
	tlib_testmalloc_leak(NULL);
}

static void	test_memcmp_child2(void) {
	tlib_mockmalloc_reset();
	test_memcmp_testequal(NULL, "HOLA", 0);
	test_memcmp_testequal("HOLA", NULL, 0);
	test_memcmp_testequal(NULL, NULL, 0);
	tlib_testmalloc_leak(NULL);
}

static void	test_memcmp_child3(void) {
	ft_memcmp(NULL, "HOLA", 5);
}

static void	test_memcmp_child4(void) {
	ft_memcmp("HOLA", NULL, 5);
}

void	test_memcmp(void) {
	tlib_testprocess_ok(&test_memcmp_child1, NULL);
	tlib_testprocess_ok(&test_memcmp_child2, NULL);
	tlib_testprocess_segfault(&test_memcmp_child3, NULL);
	tlib_testprocess_segfault(&test_memcmp_child4, NULL);
}
