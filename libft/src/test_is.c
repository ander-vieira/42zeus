#include "test.h"

void	test_isalpha(void) {
	tlib_mockmalloc_reset();
	tlib_testresult_true(ft_isalpha('a'), "ft_isalpha('a')");
	tlib_testresult_true(ft_isalpha('F'), "ft_isalpha('F')");
	tlib_testresult_false(ft_isalpha('3'), "ft_isalpha('3')");
	tlib_testresult_false(ft_isalpha(' '), "ft_isalpha(' ')");
	tlib_testresult_false(ft_isalpha('.'), "ft_isalpha('.')");
	tlib_testresult_false(ft_isalpha(127), "ft_isalpha(127)");
	tlib_testmalloc_count(0);
}

void	test_isdigit(void) {
	tlib_mockmalloc_reset();
	tlib_testresult_true(ft_isdigit('5'), "ft_isdigit('5')");
	tlib_testresult_false(ft_isdigit('d'), "ft_isdigit('d')");
	tlib_testresult_false(ft_isdigit(' '), "ft_isdigit(' ')");
	tlib_testresult_false(ft_isdigit(5), "ft_isdigit(5)");
	tlib_testmalloc_count(0);
}

void	test_isalnum(void) {
	tlib_mockmalloc_reset();
	tlib_testresult_true(ft_isalnum('5'), "ft_isalnum('5')");
	tlib_testresult_true(ft_isalnum('d'), "ft_isalnum('d')");
	tlib_testresult_true(ft_isalnum('J'), "ft_isalnum('J')");
	tlib_testresult_false(ft_isalnum(' '), "ft_isalnum(' ')");
	tlib_testresult_false(ft_isalnum(5), "ft_isalnum(5)");
	tlib_testmalloc_count(0);
}

void	test_isascii(void) {
	tlib_mockmalloc_reset();
	tlib_testresult_true(ft_isascii('0'), "ft_isalnum('0')");
	tlib_testresult_true(ft_isascii(0x00), "ft_isascii(0x00)");
	tlib_testresult_true(ft_isascii(0x7F), "ft_isascii(0x7F)");
	tlib_testresult_false(ft_isascii(0x80), "ft_isascii(0x80)");
	tlib_testresult_false(ft_isascii(0x100), "ft_isascii(0x100)");
	tlib_testmalloc_count(0);
}

void	test_isprint(void) {
	tlib_mockmalloc_reset();
	tlib_testresult_false(ft_isprint(0), "ft_isprint(0)");
	tlib_testresult_false(ft_isprint('\n'), "ft_isprint('\\n')");
	tlib_testresult_true(ft_isprint(' '), "ft_isprint(' ')");
	tlib_testresult_true(ft_isprint('5'), "ft_isprint('5')");
	tlib_testresult_true(ft_isprint('A'), "ft_isprint('A')");
	tlib_testresult_true(ft_isprint('a'), "ft_isprint('a')");
	tlib_testresult_true(ft_isprint('~'), "ft_isprint('~')");
	tlib_testresult_false(ft_isprint(0x7F), "ft_isprint(0x7F)");
	tlib_testresult_false(ft_isprint(0x100), "ft_isprint(0x100)");
	tlib_testmalloc_count(0);
}
