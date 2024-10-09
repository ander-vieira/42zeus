#include "test.h"

static void	test_memcpy_testone(void *dst, void *src, size_t n) {
	tlib_testresult_addr(ft_memcpy(dst, src, n), dst, "ft_memcpy(%p, %S, %z)", dst, src, n);
	tlib_testresult_str(dst, src, "ft_memcpy(%p, %S, %z)", dst, src, n);
}

static void	test_memcpy_child1(void) {
	char	buf[5];

	tlib_mockmalloc_reset();
	test_memcpy_testone(buf, "HOLA", 5);
	tlib_testmalloc_leak(NULL);
}

static void	test_memcpy_child2(void) {
	char	buf[5];

	tlib_mockmalloc_reset();
	tlib_testresult_addr(ft_memcpy(NULL, NULL, 3), NULL, "ft_memcpy(NULL, NULL, 3)");
	tlib_testresult_addr(ft_memcpy(NULL, "ASDFG", 0), NULL, "ft_memcpy(NULL, \"ASDFG\", 0)");
	tlib_testresult_addr(ft_memcpy(buf, NULL, 0), buf, "ft_memcpy(%p, NULL, 0)", buf);
	tlib_testmalloc_leak(NULL);
}

static void	test_memcpy_child3(void) {
	ft_memcpy(NULL, "ASDFG", 5);
}

static void	test_memcpy_child4(void) {
	char	buf[5];

	ft_memcpy(buf, NULL, 5);
}

void	test_memcpy(void) {
	tlib_testprocess_ok(&test_memcpy_child1, NULL);
	tlib_testprocess_ok(&test_memcpy_child2, NULL);
	tlib_testprocess_segfault(&test_memcpy_child3, NULL);
	tlib_testprocess_segfault(&test_memcpy_child4, NULL);
}
