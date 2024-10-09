#include "test.h"

static void	test_strlcat_testone(char *dst, char *src, size_t dstsize, char *start_value, char *expected_value) {
	size_t	expected_size;

	if (dstsize >= tlib_str_len(start_value))
		expected_size = tlib_str_len(start_value) + tlib_str_len(src);
	else
		expected_size = dstsize + tlib_str_len(src);
	tlib_str_cpy(dst, start_value);
	tlib_testresult_size(ft_strlcat(dst, src, dstsize), expected_size, "ft_strlcat(%S, %S, %z)", start_value, src, dstsize);
	tlib_testresult_str(dst, expected_value, "ft_strlcat(%S, %S, %z)", start_value, src, dstsize);
}

static void	test_strlcat_child1(void) {
	char	buf[11];

	test_strlcat_testone(buf, " MUNDO", 11, "HOLA", "HOLA MUNDO");
	test_strlcat_testone(buf, "", 11, "HOLA", "HOLA");
	test_strlcat_testone(buf, "MUNDO", 11, "", "MUNDO");
	test_strlcat_testone(buf, " MUNDO", 8, "HOLA", "HOLA MU");
	test_strlcat_testone(buf, "MUNDO", 4, "", "MUN");
	tlib_testmalloc_leak(NULL);
}

static void	test_strlcat_child2(void) {
	char	buf[11];

	tlib_mockmalloc_reset();
	test_strlcat_testone(buf, " MUNDO", 3, "HOLA", "HOLA");
	test_strlcat_testone(buf, " MUNDO", 0, "HOLA", "HOLA");
	tlib_testmalloc_leak(NULL);
}

static void	test_strlcat_child3(void) {
	ft_strlcat(NULL, "HOLA", 5);
}

static void	test_strlcat_child4(void) {
	ft_strlcat("HOLA", NULL, 5);
}

void	test_strlcat(void) {
	tlib_testprocess_ok(&test_strlcat_child1, NULL);
	tlib_testprocess_ok(&test_strlcat_child2, NULL);
	tlib_testprocess_segfault(&test_strlcat_child3, NULL);
	tlib_testprocess_segfault(&test_strlcat_child4, NULL);
}
