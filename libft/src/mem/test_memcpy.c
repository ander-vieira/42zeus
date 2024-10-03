#include "test.h"

static void	test_memcpy_child1(void) {
	char	buf[5];

	tlib_mockmalloc_reset();
	tlib_testresult_bool(ft_memcpy(buf, "ASDFG", 5) == buf);
	tlib_testresult_bool(!memcmp(buf, "ASDFG", 5));
	tlib_testresult_bool(ft_memcpy(buf, "JJ", 2) == buf);
	tlib_testresult_bool(!memcmp(buf, "JJDFG", 5));
	tlib_testresult_bool(ft_memcpy(buf, "JJ", 2) == buf);
	tlib_testresult_bool(!memcmp(buf, "JJDFG", 5));
	tlib_testmalloc_count(0);
}

static void	test_memcpy_child2(void) {
	char	buf[5];

	tlib_mockmalloc_reset();
	memcpy(buf, "ASDFG", 5);
	tlib_testresult_bool(ft_memcpy(NULL, NULL, 3) == NULL);
	tlib_testresult_bool(ft_memcpy(NULL, "ASDFG", 0) == NULL);
	tlib_testresult_bool(ft_memcpy(buf, NULL, 0) == buf);
	tlib_testresult_bool(!memcmp(buf, "ASDFG", 5));
	tlib_testmalloc_count(0);
}

static void	test_memcpy_child3(void) {
	ft_memcpy(NULL, "ASDFG", 5);
}

static void	test_memcpy_child4(void) {
	char	buf[5];

	ft_memcpy(buf, NULL, 5);
}

void	test_memcpy(void) {
	tlib_test_process(&test_memcpy_child1, PRESULT_OK);
	tlib_test_process(&test_memcpy_child2, PRESULT_OK);
	tlib_test_process(&test_memcpy_child3, PRESULT_SEGFAULT);
	tlib_test_process(&test_memcpy_child4, PRESULT_SEGFAULT);
}
