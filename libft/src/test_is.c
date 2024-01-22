/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:15:49 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/22 20:22:59 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_isalpha(void)
{
	tlib_print_test("1", ft_isalpha('a'), FALSE);
	tlib_print_test("2", ft_isalpha('F'), FALSE);
	tlib_print_test("3", !ft_isalpha('3'), FALSE);
	tlib_print_test("4", !ft_isalpha(' '), FALSE);
	tlib_print_test("5", !ft_isalpha('.'), FALSE);
	tlib_print_test("6", !ft_isalpha(127), FALSE);
	tlib_print_test("7", tlib_alloc_count() == 0, TRUE);
	tlib_alloc_reset();
}

void	test_isdigit(void)
{
	tlib_print_test("1", ft_isdigit('5'), FALSE);
	tlib_print_test("2", !ft_isdigit('d'), FALSE);
	tlib_print_test("3", !ft_isdigit(' '), FALSE);
	tlib_print_test("4", !ft_isdigit(5), FALSE);
	tlib_print_test("5", tlib_alloc_count() == 0, TRUE);
	tlib_alloc_reset();
}

void	test_isalnum(void)
{
	tlib_print_test("1", ft_isalnum('5'), FALSE);
	tlib_print_test("2", ft_isalnum('d'), FALSE);
	tlib_print_test("3", ft_isalnum('J'), FALSE);
	tlib_print_test("4", !ft_isalnum(' '), FALSE);
	tlib_print_test("5", !ft_isalnum(5), FALSE);
	tlib_print_test("6", tlib_alloc_count() == 0, TRUE);
	tlib_alloc_reset();
}

void	test_isascii(void)
{
	tlib_print_test("1", ft_isascii('0'), FALSE);
	tlib_print_test("2", ft_isascii(0x00), FALSE);
	tlib_print_test("3", ft_isascii(0x7F), FALSE);
	tlib_print_test("4", !ft_isascii(0x80), FALSE);
	tlib_print_test("5", !ft_isascii(0x100), FALSE);
	tlib_print_test("6", tlib_alloc_count() == 0, TRUE);
	tlib_alloc_reset();
}

void	test_isprint(void)
{
	tlib_print_test("1", !ft_isprint(0), FALSE);
	tlib_print_test("2", !ft_isprint('\n'), FALSE);
	tlib_print_test("3", ft_isprint(' '), FALSE);
	tlib_print_test("4", ft_isprint('5'), FALSE);
	tlib_print_test("5", ft_isprint('A'), FALSE);
	tlib_print_test("6", ft_isprint('a'), FALSE);
	tlib_print_test("7", ft_isprint('~'), FALSE);
	tlib_print_test("8", !ft_isprint(0x7F), FALSE);
	tlib_print_test("9", !ft_isprint(0x100), FALSE);
	tlib_print_test("10", tlib_alloc_count() == 0, TRUE);
	tlib_alloc_reset();
}
