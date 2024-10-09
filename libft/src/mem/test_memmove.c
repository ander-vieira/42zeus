#include "test.h"

static char	memmove_buf[11];

static void	test_memmove_testone(char *dst, char *src, size_t n, char *expected) {
	tlib_mockmalloc_reset();
	tlib_testresult_addr(ft_memmove(dst, src, n), dst, "ft_memmove(%p, %S (%p), %z)", dst, src, src, n);
	if (expected != NULL)
		tlib_testresult_str(memmove_buf, expected, "ft_memmove(%p, %S (%p), %z)", dst, src, src, n);
	tlib_testmalloc_leak("ft_memmove(%p, %S (%p), %z)", dst, src, src, n);
}

static void	test_memmove_child1(void) {
	test_memmove_testone(memmove_buf, "HOLA MUNDO", 11, "HOLA MUNDO");
	test_memmove_testone(memmove_buf, memmove_buf + 5, 2, "MULA MUNDO");
	test_memmove_testone(memmove_buf + 3, memmove_buf, 4, "MULMULANDO");
	test_memmove_testone(memmove_buf + 7, memmove_buf, 3, "MULMULAMUL");
}

static void	test_memmove_child2(void) {
	test_memmove_testone(memmove_buf, NULL, 0, NULL);
	test_memmove_testone(NULL, "HOLA MUNDO", 0, NULL);
	test_memmove_testone(NULL, NULL, 0, NULL);
	test_memmove_testone(NULL, NULL, 3, NULL);
}

static void	test_memmove_child3(void) {
	ft_memmove(NULL, "HOLA MUNDO", 11);
}

static void	test_memmove_child4(void) {
	ft_memmove(memmove_buf, NULL, 11);
}

void	test_memmove(void) {
	tlib_testprocess_ok(&test_memmove_child1, NULL);
	tlib_testprocess_ok(&test_memmove_child2, NULL);
	tlib_testprocess_segfault(&test_memmove_child3, "ft_memmove(NULL, \"HOLA MUNDO\", 11)");
	tlib_testprocess_segfault(&test_memmove_child4, "ft_memmove(%p, NULL, 11)", memmove_buf);
}
