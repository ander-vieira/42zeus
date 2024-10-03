#include "test.h"

static void	test_memset_child1(void) {
	char	buf[5];

	tlib_mockmalloc_reset();
	tlib_testresult_bool(ft_memset(buf, 'A', 5) == buf);
	tlib_testresult_bool(!memcmp(buf, "AAAAA", 5));
	tlib_testresult_bool(ft_memset(buf, 'B', 2) == buf);
	tlib_testresult_bool(!memcmp(buf, "BBAAA", 5));
	tlib_testresult_bool(ft_memset(buf, 'C' + 256, 4) == buf);
	tlib_testresult_bool(!memcmp(buf, "CCCCA", 5));
	tlib_testresult_bool(ft_memset(buf + 3, '\0', 1) == buf + 3);
	tlib_testresult_bool(!memcmp(buf, "CCC\0A", 5));
	tlib_testresult_bool(ft_memset(buf, 'A' + 256, 2) == buf);
	tlib_testresult_bool(!memcmp(buf, "AAC\0A", 5));
	tlib_testmalloc_count(0);
}

static void	test_memset_child2(void) {
	char	buf[5];

	tlib_mockmalloc_reset();
	memset(buf, 'A', 5);
	tlib_testresult_bool(ft_memset(NULL, 'A', 0) == NULL);
	tlib_testresult_bool(ft_memset(buf, 'B', 0) == buf);
	tlib_testresult_bool(!memcmp(buf, "AAAAA", 5));
	tlib_testmalloc_count(0);
}

static void	test_memset_child3(void) {
	ft_memset(NULL, 'A', 5);
}

void	test_memset(void) {
	tlib_testprocess_ok(&test_memset_child1);
	tlib_testprocess_ok(&test_memset_child2);
	tlib_testprocess_segfault(&test_memset_child3);
	tlib_mockmalloc_reset();
}
