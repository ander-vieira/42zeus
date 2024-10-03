#include "test.h"

static void	test_memcpy_child1(void) {
	char	buf[5];

	tlib_mockmalloc_reset();
	tlib_testresult_addr(ft_memcpy(buf, "ASDFG", 5), buf, "ft_memcpy(%p, \"ASDFG\", 5)", buf);
	tlib_testresult_raw(!memcmp(buf, "ASDFG", 5));
	tlib_testresult_addr(ft_memcpy(buf, "JJ", 2), buf, "ft_memcpy(%p, \"JJ\", 2)", buf);
	tlib_testresult_raw(!memcmp(buf, "JJDFG", 5));
	tlib_testmalloc_leak(NULL);
}

static void	test_memcpy_child2(void) {
	char	buf[5];

	tlib_mockmalloc_reset();
	memcpy(buf, "ASDFG", 5);
	tlib_testresult_addr(ft_memcpy(NULL, NULL, 3), NULL, "ft_memcpy(NULL, NULL, 3)");
	tlib_testresult_addr(ft_memcpy(NULL, "ASDFG", 0), NULL, "ft_memcpy(NULL, \"ASDFG\", 0)");
	tlib_testresult_addr(ft_memcpy(buf, NULL, 0), buf, "ft_memcpy(%p, NULL, 0)", buf);
	tlib_testresult_raw(!memcmp(buf, "ASDFG", 5));
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
	tlib_testprocess_ok(&test_memcpy_child1);
	tlib_testprocess_ok(&test_memcpy_child2);
	tlib_testprocess_segfault(&test_memcpy_child3);
	tlib_testprocess_segfault(&test_memcpy_child4);
}
