#include "test.h"

static void	test_strlcat_testone(char *str1, char *str2, char *expected) {
	char	buf[5];

	tlib_mockmalloc_reset();
	strcpy(buf, str1);
	tlib_testresult_bool(ft_strlcat(buf, str2, 5) == strlen(str1) + strlen(str2));
	tlib_testresult_bool(!strcmp(buf, expected));
	tlib_testmalloc_count(0);
}

static void	test_strlcat_child1(void) {
	test_strlcat_testone("AB", "CD", "ABCD");
	test_strlcat_testone("", "ABC", "ABC");
	test_strlcat_testone("AB", "CDE", "ABCD");
	test_strlcat_testone("", "ABCDE", "ABCD");
}

static void	test_strlcat_child2(void) {
	char	buf[5];

	tlib_mockmalloc_reset();
	strcpy(buf, "AB");
	tlib_testresult_bool(ft_strlcat(buf, "C", 1) == 2);
	tlib_testresult_bool(!strcmp(buf, "AB"));
	strcpy(buf, "AB");
	tlib_testresult_bool(ft_strlcat(buf, "C", 0) == 1);
	tlib_testresult_bool(!strcmp(buf, "AB"));
	tlib_testmalloc_count(0);
}

static void	test_strlcat_child3(void) {
	ft_strlcat(NULL, "HOLA", 5);
}

static void	test_strlcat_child4(void) {
	ft_strlcat("HOLA", NULL, 5);
}

void	test_strlcat(void) {
	tlib_test_process(&test_strlcat_child1, PRESULT_OK);
	tlib_test_process(&test_strlcat_child2, PRESULT_OK);
	tlib_test_process(&test_strlcat_child3, PRESULT_SEGFAULT);
	tlib_test_process(&test_strlcat_child4, PRESULT_SEGFAULT);
}
