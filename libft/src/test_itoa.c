#include "test.h"

static void	test_itoa_testone(int num, char *expected) {
	char	*str;

	tlib_mockmalloc_reset();
	str = ft_itoa(num);
	tlib_testresult_bool(!strcmp(str, expected));
	tlib_testmalloc_size(str, strlen(expected) + 1);
	tlib_testmalloc_count(1);
	free(str);
}

static void	test_itoa_child1(void) {
	test_itoa_testone(314, "314");
	test_itoa_testone(0, "0");
	test_itoa_testone(-4268, "-4268");
	test_itoa_testone(2147483647, "2147483647");
	test_itoa_testone(-2147483648, "-2147483648");
}

static void	test_itoa_child2(void) {
	tlib_mockmalloc_reset();
	tlib_mockmalloc_setmock(1);
	tlib_testresult_bool(ft_itoa(5) == NULL);
}

void	test_itoa(void) {
	tlib_testprocess_ok(&test_itoa_child1);
	tlib_testprocess_ok(&test_itoa_child2);
}
