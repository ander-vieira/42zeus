#include "test.h"

void	test_isalpha(void) {
	tlib_mockmalloc_reset();
	tlib_testresult_nonzero(ft_isalpha('a'), "ft_isalpha('a')");
	tlib_testresult_nonzero(ft_isalpha('F'), "ft_isalpha('F')");
	tlib_testresult_int(ft_isalpha('3'), 0, "ft_isalpha('3')");
	tlib_testresult_int(ft_isalpha(' '), 0, "ft_isalpha(' ')");
	tlib_testresult_int(ft_isalpha('.'), 0, "ft_isalpha('.')");
	tlib_testresult_int(ft_isalpha(127), 0, "ft_isalpha(127)");
	tlib_testmalloc_leak(NULL);
}

void	test_isdigit(void) {
	tlib_mockmalloc_reset();
	tlib_testresult_nonzero(ft_isdigit('5'), "ft_isdigit('5')");
	tlib_testresult_int(ft_isdigit('d'), 0, "ft_isdigit('d')");
	tlib_testresult_int(ft_isdigit(' '), 0, "ft_isdigit(' ')");
	tlib_testresult_int(ft_isdigit(5), 0, "ft_isdigit(5)");
	tlib_testmalloc_leak(NULL);
}

void	test_isalnum(void) {
	tlib_mockmalloc_reset();
	tlib_testresult_nonzero(ft_isalnum('5'), "ft_isalnum('5')");
	tlib_testresult_nonzero(ft_isalnum('d'), "ft_isalnum('d')");
	tlib_testresult_nonzero(ft_isalnum('J'), "ft_isalnum('J')");
	tlib_testresult_int(ft_isalnum(' '), 0, "ft_isalnum(' ')");
	tlib_testresult_int(ft_isalnum(5), 0, "ft_isalnum(5)");
	tlib_testmalloc_leak(NULL);
}

void	test_isascii(void) {
	tlib_mockmalloc_reset();
	tlib_testresult_nonzero(ft_isascii('0'), "ft_isalnum('0')");
	tlib_testresult_nonzero(ft_isascii(0x00), "ft_isascii(0x00)");
	tlib_testresult_nonzero(ft_isascii(0x7F), "ft_isascii(0x7F)");
	tlib_testresult_int(ft_isascii(0x80), 0, "ft_isascii(0x80)");
	tlib_testresult_int(ft_isascii(0x100), 0, "ft_isascii(0x100)");
	tlib_testmalloc_leak(NULL);
}

void	test_isprint(void) {
	tlib_mockmalloc_reset();
	tlib_testresult_int(ft_isprint(0), 0, "ft_isprint(0)");
	tlib_testresult_int(ft_isprint('\n'), 0, "ft_isprint('\\n')");
	tlib_testresult_nonzero(ft_isprint(' '), "ft_isprint(' ')");
	tlib_testresult_nonzero(ft_isprint('5'), "ft_isprint('5')");
	tlib_testresult_nonzero(ft_isprint('A'), "ft_isprint('A')");
	tlib_testresult_nonzero(ft_isprint('a'), "ft_isprint('a')");
	tlib_testresult_nonzero(ft_isprint('~'), "ft_isprint('~')");
	tlib_testresult_int(ft_isprint(0x7F), 0, "ft_isprint(0x7F)");
	tlib_testresult_int(ft_isprint(0x100), 0, "ft_isprint(0x100)");
	tlib_testmalloc_leak(NULL);
}
