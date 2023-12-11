/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:15:49 by andeviei          #+#    #+#             */
/*   Updated: 2023/12/11 17:43:28 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_isalpha(void)
{
	print_title("isalpha");
	print_test("1", ft_isalpha('a'), FALSE);
	print_test("2", ft_isalpha('F'), FALSE);
	print_test("3", !ft_isalpha('3'), FALSE);
	print_test("4", !ft_isalpha(' '), FALSE);
	print_test("5", !ft_isalpha('.'), FALSE);
	print_test("6", !ft_isalpha(127), TRUE);
}

void	test_isdigit(void)
{
	print_title("isdigit");
	print_test("1", ft_isdigit('5'), FALSE);
	print_test("2", !ft_isdigit('d'), FALSE);
	print_test("3", !ft_isdigit(' '), FALSE);
	print_test("4", !ft_isdigit(5), TRUE);
}

void	test_isalnum(void)
{
	print_title("isalnum");
	print_test("1", ft_isalnum('5'), FALSE);
	print_test("2", ft_isalnum('d'), FALSE);
	print_test("3", ft_isalnum('J'), FALSE);
	print_test("4", !ft_isalnum(' '), FALSE);
	print_test("5", !ft_isalnum(5), TRUE);
}

void	test_isascii_isprint(void)
{
	print_title("isascii");
	print_test("1", ft_isascii('5'), TRUE);
	print_title("isprint");
	print_test("1", ft_isprint('5'), TRUE);
}

void	test_is(void)
{
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii_isprint();
}
