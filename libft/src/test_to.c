/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:14:57 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/22 20:10:24 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_tolower(void)
{
	tlib_print_test("1", ft_tolower('\0') == '\0', FALSE);
	tlib_print_test("2", ft_tolower('\n') == '\n', FALSE);
	tlib_print_test("3", ft_tolower(' ') == ' ', FALSE);
	tlib_print_test("4", ft_tolower('5') == '5', FALSE);
	tlib_print_test("5", ft_tolower('G') == 'g', FALSE);
	tlib_print_test("6", ft_tolower('j') == 'j', FALSE);
	tlib_print_test("7", ft_tolower(0x80) == 0x80, FALSE);
	tlib_print_test("8", tlib_alloc_count() == 0, TRUE);
	tlib_alloc_reset();
}

void	test_toupper(void)
{
	tlib_print_test("1", ft_toupper('\0') == '\0', FALSE);
	tlib_print_test("2", ft_toupper('\n') == '\n', FALSE);
	tlib_print_test("3", ft_toupper(' ') == ' ', FALSE);
	tlib_print_test("4", ft_toupper('5') == '5', FALSE);
	tlib_print_test("5", ft_toupper('G') == 'G', FALSE);
	tlib_print_test("6", ft_toupper('j') == 'J', FALSE);
	tlib_print_test("7", ft_toupper(0x80) == 0x80, FALSE);
	tlib_print_test("8", tlib_alloc_count() == 0, TRUE);
	tlib_alloc_reset();
}
