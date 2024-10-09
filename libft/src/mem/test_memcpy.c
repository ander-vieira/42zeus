#include "test.h"

static char	memcpy_buf[5];

static void	test_memcpy_testone(void *dst, void *src, size_t n) {
	tlib_mockmalloc_reset();
	tlib_testresult_addr(ft_memcpy(dst, src, n), dst, "ft_memcpy(%p, %S, %z)", dst, src, n);
	if (dst != NULL && src != NULL)
		tlib_testresult_str(dst, src, "ft_memcpy(%p, %S, %z)", dst, src, n);
	tlib_testmalloc_leak("ft_memcpy(%p, %S, %z)", dst, src, n);
}

static void	test_memcpy_child1(void) {
	test_memcpy_testone(memcpy_buf, "HOLA", 5);
}

static void	test_memcpy_child2(void) {
	test_memcpy_testone(NULL, NULL, 5);
	test_memcpy_testone(NULL, "HOLA", 0);
	test_memcpy_testone(memcpy_buf, NULL, 0);
}

static void	test_memcpy_child3(void) {
	ft_memcpy(NULL, "HOLA", 5);
}

static void	test_memcpy_child4(void) {
	ft_memcpy(memcpy_buf, NULL, 5);
}

void	test_memcpy(void) {
	tlib_testprocess_ok(&test_memcpy_child1, NULL);
	tlib_testprocess_ok(&test_memcpy_child2, NULL);
	tlib_testprocess_segfault(&test_memcpy_child3, "ft_memcpy(NULL, \"HOLA\", 5)");
	tlib_testprocess_segfault(&test_memcpy_child4, "ft_memcpy(%p, NULL, 5)", memcpy_buf);
}
