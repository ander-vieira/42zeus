#include "test.h"

void	test_isalpha(void)
{
	tlib_mockmalloc_reset();
	tlib_testresult_bool(ft_isalpha('a'));
	tlib_testresult_bool(ft_isalpha('F'));
	tlib_testresult_bool(!ft_isalpha('3'));
	tlib_testresult_bool(!ft_isalpha(' '));
	tlib_testresult_bool(!ft_isalpha('.'));
	tlib_testresult_bool(!ft_isalpha(127));
	tlib_testmalloc_count(0);
}

void	test_isdigit(void)
{
	tlib_mockmalloc_reset();
	tlib_testresult_bool(ft_isdigit('5'));
	tlib_testresult_bool(!ft_isdigit('d'));
	tlib_testresult_bool(!ft_isdigit(' '));
	tlib_testresult_bool(!ft_isdigit(5));
	tlib_testmalloc_count(0);
}

void	test_isalnum(void)
{
	tlib_mockmalloc_reset();
	tlib_testresult_bool(ft_isalnum('5'));
	tlib_testresult_bool(ft_isalnum('d'));
	tlib_testresult_bool(ft_isalnum('J'));
	tlib_testresult_bool(!ft_isalnum(' '));
	tlib_testresult_bool(!ft_isalnum(5));
	tlib_testmalloc_count(0);
}

void	test_isascii(void)
{
	tlib_mockmalloc_reset();
	tlib_testresult_bool(ft_isascii('0'));
	tlib_testresult_bool(ft_isascii(0x00));
	tlib_testresult_bool(ft_isascii(0x7F));
	tlib_testresult_bool(!ft_isascii(0x80));
	tlib_testresult_bool(!ft_isascii(0x100));
	tlib_testmalloc_count(0);
}

void	test_isprint(void)
{
	tlib_mockmalloc_reset();
	tlib_testresult_bool(!ft_isprint(0));
	tlib_testresult_bool(!ft_isprint('\n'));
	tlib_testresult_bool(ft_isprint(' '));
	tlib_testresult_bool(ft_isprint('5'));
	tlib_testresult_bool(ft_isprint('A'));
	tlib_testresult_bool(ft_isprint('a'));
	tlib_testresult_bool(ft_isprint('~'));
	tlib_testresult_bool(!ft_isprint(0x7F));
	tlib_testresult_bool(!ft_isprint(0x100));
	tlib_testmalloc_count(0);
}
