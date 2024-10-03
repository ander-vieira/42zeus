#include "test.h"

static void	test_strlcpy_child1(void) {
	char	buf[5];

	tlib_mockmalloc_reset();
	tlib_testresult_raw(ft_strlcpy(buf, "", 5) == 0);
	tlib_testresult_raw(!strcmp(buf, ""));
	tlib_testresult_raw(ft_strlcpy(buf, "ABC", 5) == 3);
	tlib_testresult_raw(!strcmp(buf, "ABC"));
	tlib_testresult_raw(ft_strlcpy(buf, "ABCD", 5) == 4);
	tlib_testresult_raw(!strcmp(buf, "ABCD"));
	tlib_testresult_raw(ft_strlcpy(buf, "ABCDE", 5) == 5);
	tlib_testresult_raw(!strcmp(buf, "ABCD"));
	tlib_testresult_raw(ft_strlcpy(buf, "ABCDEFGH", 5) == 8);
	tlib_testresult_raw(!strcmp(buf, "ABCD"));
	tlib_testresult_raw(ft_strlcpy(buf, "", 0) == 0);
	tlib_testresult_raw(buf[0] != '\0');
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
