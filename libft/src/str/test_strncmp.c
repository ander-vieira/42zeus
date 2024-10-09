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
	test_strncmp_testequal("HOLA", "HOLA", 4);
	test_strncmp_testequal("HOLA", "HOLA", 7);
	test_strncmp_testdiff("HOLA", "HOLE", 4);
	test_strncmp_testequal("HOLA", "HOLE", 2);
	test_strncmp_testdiff("HOLA", "HALA", 4);
	test_strncmp_testdiff("HOLA", "HALA", 2);
	test_strncmp_testdiff("HOLA", "HO", 4);
	test_strncmp_testdiff("HO", "HOLA", 4);
	test_strncmp_testequal("HOLA", "HO", 2);
	test_strncmp_testequal("HO", "HOLA", 2);
	test_strncmp_testdiff("HOLA", "", 4);
	test_strncmp_testdiff("", "HOLA", 4);
	test_strncmp_testequal("HOLA", "", 0);
	test_strncmp_testequal("", "HOLA", 0);
	test_strncmp_testequal("", "", 4);
	tlib_testmalloc_leak(NULL);
}

static void	test_strncmp_child2(void) {
	tlib_mockmalloc_reset();
	test_strncmp_testequal(NULL, "HOLA", 0);
	test_strncmp_testequal("HOLA", NULL, 0);
	test_strncmp_testequal(NULL, NULL, 0);
	tlib_testmalloc_leak(NULL);
}

static void	test_strncmp_child3(void) {
	ft_strncmp("HOLA", NULL, 5);
}

static void	test_strncmp_child4(void) {
	ft_strncmp(NULL, "HOLA", 5);
}

void	test_strncmp(void) {
	tlib_testprocess_ok(&test_strncmp_child1, NULL);
	tlib_testprocess_ok(&test_strncmp_child2, NULL);
	tlib_testprocess_segfault(&test_strncmp_child3, NULL);
	tlib_testprocess_segfault(&test_strncmp_child4, NULL);
}
