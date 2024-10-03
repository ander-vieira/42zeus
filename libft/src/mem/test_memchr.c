#include "test.h"

static void	test_memchr_child1(void) {
	char	buf[5];

	tlib_mockmalloc_reset();
	memcpy(buf, "ASD\0G", 5);
	tlib_testresult_raw(ft_memchr(buf, 'A', 5) == buf);
	tlib_testresult_raw(ft_memchr(buf, '\0', 5) == buf + 3);
	tlib_testresult_raw(ft_memchr(buf, 'G', 5) == buf + 4);
	tlib_testresult_raw(ft_memchr(buf, 'G', 3) == NULL);
	tlib_testresult_raw(ft_memchr(buf, 'H', 5) == NULL);
	tlib_testresult_raw(ft_memchr(buf, 'A', 0) == NULL);
	tlib_testresult_raw(ft_memchr(buf, 'A' + 256, 5) == buf);
	tlib_testresult_raw(ft_memchr(buf, 'H' + 256, 5) == NULL);
	tlib_testmalloc_leak(NULL);
}

static void	test_memchr_child2(void) {
	tlib_mockmalloc_reset();
	tlib_testresult_raw(ft_memchr(NULL, 'A', 0) == NULL);
	tlib_testmalloc_leak(NULL);
}

static void	test_memchr_child3(void) {
	ft_memchr(NULL, 'A', 5);
}

void	test_memchr(void) {
	tlib_testprocess_ok(&test_memchr_child1);
	tlib_testprocess_ok(&test_memchr_child2);
	tlib_testprocess_segfault(&test_memchr_child3);
}
