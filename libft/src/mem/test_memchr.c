#include "test.h"

static void	test_memchr_testone(char *str, int c, size_t n, char *expected) {
	tlib_mockmalloc_reset();
	tlib_testresult_addr(ft_memchr(str, c, n), expected, "ft_memchr(%S (%p), %c (%d), %z)", str, str, c, c, n);
	tlib_testmalloc_leak("ft_memchr(%S (%p), %c (%d), %z)", str, str, c, c, n);
}

static void	test_memchr_child1(void) {
	char	*str;

	str = "HOLA";
	test_memchr_testone(str, 'H', 5, str);
	test_memchr_testone(str, 'L', 5, str + 2);
	test_memchr_testone(str, '\0', 5, str + 4);
	test_memchr_testone(str, 'L', 2, NULL);
	test_memchr_testone(str, 'F', 5, NULL);
	test_memchr_testone(str, 'H', 0, NULL);
	test_memchr_testone(str, 'H' + 256, 5, str);
	test_memchr_testone(str, 'F' + 256, 5, NULL);
}

static void	test_memchr_child2(void) {
	tlib_mockmalloc_reset();
	tlib_testresult_addr(ft_memchr(NULL, 'A', 0), NULL, "ft_memchr(NULL, 'A', 0)");
	tlib_testmalloc_leak("ft_memchr(NULL, 'A', 0)");
}

static void	test_memchr_child3(void) {
	ft_memchr(NULL, 'A', 5);
}

void	test_memchr(void) {
	tlib_testprocess_ok(&test_memchr_child1, NULL);
	tlib_testprocess_ok(&test_memchr_child2, "ft_memchr(NULL, 'A', 0)");
	tlib_testprocess_segfault(&test_memchr_child3, "ft_memchr(NULL, 'A', 5)");
}
