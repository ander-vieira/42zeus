/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:15:49 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/20 17:03:06 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_isalpha(void)
{
	tlib_print_test("1", ft_isalpha('a'), FALSE);
	tlib_print_test("2", ft_isalpha('F'), FALSE);
	tlib_print_test("3", !ft_isalpha('3'), FALSE);
	tlib_print_test("4", !ft_isalpha(' '), FALSE);
	tlib_print_test("5", !ft_isalpha('.'), FALSE);
	tlib_print_test("6", !ft_isalpha(127), TRUE);
}

static void	test_isdigit(void)
{
	tlib_print_test("1", ft_isdigit('5'), FALSE);
	tlib_print_test("2", !ft_isdigit('d'), FALSE);
	tlib_print_test("3", !ft_isdigit(' '), FALSE);
	tlib_print_test("4", !ft_isdigit(5), TRUE);
}

static void	test_isalnum(void)
{
	tlib_print_test("1", ft_isalnum('5'), FALSE);
	tlib_print_test("2", ft_isalnum('d'), FALSE);
	tlib_print_test("3", ft_isalnum('J'), FALSE);
	tlib_print_test("4", !ft_isalnum(' '), FALSE);
	tlib_print_test("5", !ft_isalnum(5), TRUE);
}

static void	test_isascii(void)
{
	tlib_print_test("1", ft_isascii('0'), FALSE);
	tlib_print_test("2", ft_isascii(0x00), FALSE);
	tlib_print_test("3", ft_isascii(0x7F), FALSE);
	tlib_print_test("4", !ft_isascii(0x80), FALSE);
	tlib_print_test("5", !ft_isascii(0x100), TRUE);
}

void	test_is1(void)
{
	tlib_print_missing(&test_isalpha, &ft_isalpha, "isalpha");
	tlib_print_missing(&test_isdigit, &ft_isdigit, "isdigit");
	tlib_print_missing(&test_isalnum, &ft_isalnum, "isalnum");
	tlib_print_missing(&test_isascii, &ft_isascii, "isascii");
}
