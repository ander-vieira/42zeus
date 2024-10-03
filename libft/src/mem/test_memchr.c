#include "test.h"

static void	test_memchr_child1(void) {
	char	buf[5];

	tlib_mockmalloc_reset();
	memcpy(buf, "ASD\0G", 5);
	tlib_testresult_addr(ft_memchr(buf, 'A', 5), buf, "ft_memchr(%p, 'A', 5)", buf);
	tlib_testresult_addr(ft_memchr(buf, '\0', 5), buf + 3, "ft_memchr(%p, '\\0', 5)", buf);
	tlib_testresult_addr(ft_memchr(buf, 'G', 5), buf + 4, "ft_memchr(%p, 'G', 5)", buf);
	tlib_testresult_addr(ft_memchr(buf, 'G', 3), NULL, "ft_memchr(%p, 'G', 3)", buf);
	tlib_testresult_addr(ft_memchr(buf, 'H', 5), NULL, "ft_memchr(%p, 'H', 5)", buf);
	tlib_testresult_addr(ft_memchr(buf, 'A', 0), NULL, "ft_memchr(%p, 'A', 0)", buf);
	tlib_testresult_addr(ft_memchr(buf, 'A' + 256, 5), buf, "ft_memchr(%p, 'A' + 256, 5)", buf);
	tlib_testresult_addr(ft_memchr(buf, 'H' + 256, 5), NULL, "ft_memchr(%p, 'H' + 256, 5)", buf);
	tlib_testmalloc_leak(NULL);
}

static void	test_memchr_child2(void) {
	tlib_mockmalloc_reset();
	tlib_testresult_addr(ft_memchr(NULL, 'A', 0), NULL, "ft_memchr(NULL, 'A', 0)");
	tlib_testmalloc_leak(NULL);
}

static void	test_memchr_child3(void) {
	ft_memchr(NULL, 'A', 5);
}

void	test_memchr(void) {
	tlib_testprocess_ok(&test_memchr_child1);
	tlib_testprocess_ok(&test_memchr_child2);
	tlib_testprocess_segfault(&test_memchr_child3);
}
