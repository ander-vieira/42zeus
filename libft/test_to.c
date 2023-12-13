/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:14:57 by andeviei          #+#    #+#             */
/*   Updated: 2023/12/13 14:18:21 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_tolower(void)
{
	print_title("tolower");
	print_test("1", ft_tolower('\0') == '\0', FALSE);
	print_test("2", ft_tolower('\n') == '\n', FALSE);
	print_test("3", ft_tolower(' ') == ' ', FALSE);
	print_test("4", ft_tolower('5') == '5', FALSE);
	print_test("5", ft_tolower('G') == 'g', FALSE);
	print_test("6", ft_tolower('j') == 'j', FALSE);
	print_test("7", ft_tolower(0x80) == 0x80, TRUE);
}

void	test_toupper(void)
{
	print_title("toupper");
	print_test("1", ft_toupper('\0') == '\0', FALSE);
	print_test("2", ft_toupper('\n') == '\n', FALSE);
	print_test("3", ft_toupper(' ') == ' ', FALSE);
	print_test("4", ft_toupper('5') == '5', FALSE);
	print_test("5", ft_toupper('G') == 'G', FALSE);
	print_test("6", ft_toupper('j') == 'J', FALSE);
	print_test("7", ft_toupper(0x80) == 0x80, TRUE);
}

void	test_to(void)
{
	test_tolower();
	test_toupper();
}