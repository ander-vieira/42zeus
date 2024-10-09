#include "test.h"

static char	memset_buf[5];

static void	test_memset_testone(char *buf, int c, size_t n) {
	tlib_mockmalloc_reset();
	tlib_testresult_addr(ft_memset(buf, c, n), buf, "ft_memset(%p, %d, %z)", buf, c, n);
	if (buf != NULL && n != 0)
		tlib_testresult_mem(buf, n, (unsigned char)c, "ft_memset(%p, %d, %z)", buf, c, n);
	tlib_testmalloc_leak("ft_memset(%p, %d, %z)", buf, c, n);
}

static void	test_memset_child1(void) {
	test_memset_testone(memset_buf, 0, 5);
	test_memset_testone(memset_buf, 60, 5);
	test_memset_testone(memset_buf, 128, 5);
	test_memset_testone(memset_buf, 256, 5);
	test_memset_testone(memset_buf, 'A', 0);
}

static void	test_memset_child2(void) {
	test_memset_testone(NULL, 'A', 0);
}

static void	test_memset_child3(void) {
	ft_memset(NULL, 'A', 5);
}

void	test_memset(void) {
	tlib_testprocess_ok(&test_memset_child1, NULL);
	tlib_testprocess_ok(&test_memset_child2, "ft_memset(NULL, 'A', 0)");
	tlib_testprocess_segfault(&test_memset_child3, "ft_memset(NULL, 'A', 5)");
}
