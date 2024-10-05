#include "test.h"

static void	test_tolower_testone(int c, int expected) {
	tlib_testresult_char(ft_tolower(c), expected, "ft_tolower(%c)", c);
}

void	test_tolower(void) {
	tlib_mockmalloc_reset();
	test_tolower_testone('\0', '\0');
	test_tolower_testone('\n', '\n');
	test_tolower_testone(' ', ' ');
	test_tolower_testone('5', '5');
	test_tolower_testone('G', 'g');
	test_tolower_testone('j', 'j');
	test_tolower_testone(128, 128);
	tlib_testmalloc_leak(NULL);
}

static void	test_toupper_testone(int c, int expected) {
	tlib_testresult_char(ft_toupper(c), expected, "ft_toupper(%c)", c);
}

void	test_toupper(void) {
	tlib_mockmalloc_reset();
	test_toupper_testone('\0', '\0');
	test_toupper_testone('\n', '\n');
	test_toupper_testone(' ', ' ');
	test_toupper_testone('5', '5');
	test_toupper_testone('G', 'G');
	test_toupper_testone('j', 'J');
	test_toupper_testone(128, 128);
	tlib_testmalloc_leak(NULL);
}
