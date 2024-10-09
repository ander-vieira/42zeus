#include "test.h"

static void	test_memset_testone(char *buf, int c, size_t n) {
	tlib_testresult_addr(ft_memset(buf, c, n), buf, "ft_memset(%p, %d, %z)", buf, c, n);
	tlib_testresult_mem(buf, n, (unsigned char)c, "ft_memset(%p, %d, %z)", buf, c, n);
}

static void	test_memset_child1(void) {
	char	buf[5];

	tlib_mockmalloc_reset();
	test_memset_testone(buf, 0, 5);
	test_memset_testone(buf, 60, 5);
	test_memset_testone(buf, 128, 5);
	test_memset_testone(buf, 256, 5);
	tlib_testmalloc_leak(NULL);
}

static void	test_memset_child2(void) {
	char	buf[5];

	tlib_mockmalloc_reset();
	tlib_testresult_addr(ft_memset(NULL, 'A', 0), NULL, "ft_memset(NULL, 'A', 0)");
	tlib_testresult_addr(ft_memset(buf, 'A', 0), buf, "ft_memset(%p, 'A', 0)", buf);
	tlib_testmalloc_leak(NULL);
}

static void	test_memset_child3(void) {
	ft_memset(NULL, 'A', 5);
}

void	test_memset(void) {
	tlib_testprocess_ok(&test_memset_child1, NULL);
	tlib_testprocess_ok(&test_memset_child2, NULL);
	tlib_testprocess_segfault(&test_memset_child3, NULL);
	tlib_mockmalloc_reset();
}
