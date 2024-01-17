/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:15:49 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/17 16:32:02 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int		ft_isalnum(int c) __attribute__((weak));
int		ft_isalpha(int c) __attribute__((weak));
int		ft_isascii(int c) __attribute__((weak));
int		ft_isdigit(int c) __attribute__((weak));

static void	test_isalpha(void)
{
	print_test("1", ft_isalpha('a'), FALSE);
	print_test("2", ft_isalpha('F'), FALSE);
	print_test("3", !ft_isalpha('3'), FALSE);
	print_test("4", !ft_isalpha(' '), FALSE);
	print_test("5", !ft_isalpha('.'), FALSE);
	print_test("6", !ft_isalpha(127), TRUE);
}

static void	test_isdigit(void)
{
	print_test("1", ft_isdigit('5'), FALSE);
	print_test("2", !ft_isdigit('d'), FALSE);
	print_test("3", !ft_isdigit(' '), FALSE);
	print_test("4", !ft_isdigit(5), TRUE);
}

static void	test_isalnum(void)
{
	print_test("1", ft_isalnum('5'), FALSE);
	print_test("2", ft_isalnum('d'), FALSE);
	print_test("3", ft_isalnum('J'), FALSE);
	print_test("4", !ft_isalnum(' '), FALSE);
	print_test("5", !ft_isalnum(5), TRUE);
}

static void	test_isascii(void)
{
	print_test("1", ft_isascii('0'), FALSE);
	print_test("2", ft_isascii(0x00), FALSE);
	print_test("3", ft_isascii(0x7F), FALSE);
	print_test("4", !ft_isascii(0x80), FALSE);
	print_test("5", !ft_isascii(0x100), TRUE);
}

void	test_is1(void)
{
	test_if_exists(&test_isalpha, &ft_isalpha, "isalpha");
	test_if_exists(&test_isdigit, &ft_isdigit, "isdigit");
	test_if_exists(&test_isalnum, &ft_isalnum, "isalnum");
	test_if_exists(&test_isascii, &ft_isascii, "isascii");
}
