/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:14:57 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 10:46:20 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_tolower(void)
{
	tlib_alloc_reset();
	tlib_print_test(ft_tolower('\0') == '\0');
	tlib_print_test(ft_tolower('\n') == '\n');
	tlib_print_test(ft_tolower(' ') == ' ');
	tlib_print_test(ft_tolower('5') == '5');
	tlib_print_test(ft_tolower('G') == 'g');
	tlib_print_test(ft_tolower('j') == 'j');
	tlib_print_test(ft_tolower(0x80) == 0x80);
	tlib_print_test(tlib_alloc_count() == 0);
}

void	test_toupper(void)
{
	tlib_alloc_reset();
	tlib_print_test(ft_toupper('\0') == '\0');
	tlib_print_test(ft_toupper('\n') == '\n');
	tlib_print_test(ft_toupper(' ') == ' ');
	tlib_print_test(ft_toupper('5') == '5');
	tlib_print_test(ft_toupper('G') == 'G');
	tlib_print_test(ft_toupper('j') == 'J');
	tlib_print_test(ft_toupper(0x80) == 0x80);
	tlib_print_test(tlib_alloc_count() == 0);
}
