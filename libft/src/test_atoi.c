#include "test.h"

static void test_atoi_testone(char *str, int expected) {
	tlib_testresult_int(ft_atoi(str), expected, "ft_atoi(%S)", str);
}

static void	test_atoi_child1(void) {
	tlib_mockmalloc_reset();
	test_atoi_testone("4", 4);
	test_atoi_testone("42", 42);
	test_atoi_testone("4242", 4242);
	test_atoi_testone("+4", 4);
	test_atoi_testone("+42", 42);
	test_atoi_testone("0", 0);
	test_atoi_testone("+0", 0);
	test_atoi_testone("-0", 0);
	test_atoi_testone("-6", -6);
	test_atoi_testone("-777", -777);
	test_atoi_testone("-4343", -4343);
	test_atoi_testone("2147483647", 2147483647);
	test_atoi_testone("-2147483648", -2147483648);
	test_atoi_testone("88abc", 88);
	test_atoi_testone("0.5", 0);
	test_atoi_testone("g55", 0);
	test_atoi_testone("51 4", 51);
	test_atoi_testone(" 77", 77);
	test_atoi_testone("    1717 ", 1717);
	test_atoi_testone("  -5675  ", -5675);
	test_atoi_testone("  3a5", 3);
	test_atoi_testone("  q7", 0);
	test_atoi_testone("  +5g", 5);
	test_atoi_testone("  -79p1", -79);
	test_atoi_testone("  3 7", 3);
	test_atoi_testone("++13", 0);
	test_atoi_testone("+-27", 0);
	test_atoi_testone("-+99", 0);
	test_atoi_testone("--814", 0);
	tlib_testmalloc_leak(NULL);
}

static void	test_atoi_child2(void) {
	ft_atoi(NULL);
}

void	test_atoi(void) {
	tlib_testprocess_ok(&test_atoi_child1);
	tlib_testprocess_segfault(&test_atoi_child2);
}
