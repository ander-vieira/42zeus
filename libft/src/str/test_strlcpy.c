#include "test.h"

static void	test_strlcpy_testone(char *dst, char *src, size_t n, char *expected_str) {
	tlib_testresult_size(ft_strlcpy(dst, src, n), tlib_str_len(src), "ft_strlcpy(%p, %S, %z)", dst, src, n);
	tlib_testresult_str(dst, expected_str, "ft_strlcpy(%p, %S, %z)", dst, src, n);
}

static void	test_strlcpy_child1(void) {
	char	buf[5];

	tlib_mockmalloc_reset();
	test_strlcpy_testone(buf, "", 5, "");
	test_strlcpy_testone(buf, "H", 5, "H");
	test_strlcpy_testone(buf, "HOLA", 5, "HOLA");
	test_strlcpy_testone(buf, "HOLA MUNDO", 5, "HOLA");
	tlib_testresult_size(ft_strlcpy(buf, "", 0), 0, "ft_strlcpy(%p, \"\", 0)", buf);
	tlib_testresult_custom(buf[0] != '\0', "ft_strlcpy(%p, \"\", 0) writes '\\0' to the buffer (should not write anything)\n", buf);
	tlib_testmalloc_leak(NULL);
}

static void	test_strlcpy_child2(void) {
	ft_strlcpy(NULL, "ABC", 5);
}

static void	test_strlcpy_child3(void) {
	ft_strlcpy("ABC", NULL, 5);
}

static void	test_strlcpy_child4(void) {
	ft_strlcpy(NULL, NULL, 5);
}

void	test_strlcpy(void) {
	tlib_testprocess_ok(&test_strlcpy_child1);
	tlib_testprocess_segfault(&test_strlcpy_child2);
	tlib_testprocess_segfault(&test_strlcpy_child3);
	tlib_testprocess_segfault(&test_strlcpy_child4);
}
