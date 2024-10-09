#include "test.h"

static void test_strlen_testone(char *str, size_t expected) {
	tlib_mockmalloc_reset();
	tlib_testresult_size(ft_strlen(str), expected, "ft_strlen(%S)", str);
	tlib_testmalloc_leak("ft_strlen(%S)", str);
}

static void	test_strlen_child1(void) {
	test_strlen_testone("HOLA", 4);
	test_strlen_testone("HOLA MUNDO", 10);
	test_strlen_testone("", 0);
}

static void	test_strlen_child2(void) {
	ft_strlen(NULL);
}

void	test_strlen(void) {
	tlib_testprocess_ok(&test_strlen_child1, NULL);
	tlib_testprocess_segfault(&test_strlen_child2, "ft_strlen(NULL)");
}
