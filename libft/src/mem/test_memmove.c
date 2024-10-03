#include "test.h"

static void	test_memmove_child1(void) {
	char	buf[5];

	tlib_mockmalloc_reset();
	tlib_testresult_raw(ft_memmove(buf, "ASDFG", 5) == buf);
	tlib_testresult_raw(!memcmp(buf, "ASDFG", 5));
	tlib_testresult_raw(ft_memmove(buf, buf + 3, 2) == buf);
	tlib_testresult_raw(!memcmp(buf, "FGDFG", 5));
	tlib_testresult_raw(ft_memmove(buf + 2, buf, 3) == buf + 2);
	tlib_testresult_raw(!memcmp(buf, "FGFGD", 5));
	tlib_testmalloc_count(0);
}

static void	test_memmove_child2(void) {
	char	buf[5];

	tlib_mockmalloc_reset();
	memcpy(buf, "ASDFG", 5);
	tlib_testresult_raw(ft_memmove(NULL, "ASDFG", 0) == NULL);
	tlib_testresult_raw(ft_memmove(buf, NULL, 0) == buf);
	tlib_testresult_raw(!memcmp(buf, "ASDFG", 5));
	tlib_testresult_raw(ft_memmove(NULL, NULL, 0) == NULL);
	tlib_testresult_raw(ft_memmove(NULL, NULL, 3) == NULL);
	tlib_testmalloc_count(0);
}

static void	test_memmove_child3(void) {
	ft_memmove(NULL, "ASDFG", 5);
}

static void	test_memmove_child4(void) {
	char	buf[5];

	ft_memmove(buf, NULL, 5);
}

void	test_memmove(void) {
	tlib_testprocess_ok(&test_memmove_child1);
	tlib_testprocess_ok(&test_memmove_child2);
	tlib_testprocess_segfault(&test_memmove_child3);
	tlib_testprocess_segfault(&test_memmove_child4);
}
