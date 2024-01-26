/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:14:57 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 12:25:33 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_tolower(void)
{
	tlib_alloc_reset();
	tlib_test_ok(ft_tolower('\0') == '\0');
	tlib_test_ok(ft_tolower('\n') == '\n');
	tlib_test_ok(ft_tolower(' ') == ' ');
	tlib_test_ok(ft_tolower('5') == '5');
	tlib_test_ok(ft_tolower('G') == 'g');
	tlib_test_ok(ft_tolower('j') == 'j');
	tlib_test_ok(ft_tolower(0x80) == 0x80);
	tlib_test_ok(tlib_alloc_count() == 0);
}

void	test_toupper(void)
{
	tlib_alloc_reset();
	tlib_test_ok(ft_toupper('\0') == '\0');
	tlib_test_ok(ft_toupper('\n') == '\n');
	tlib_test_ok(ft_toupper(' ') == ' ');
	tlib_test_ok(ft_toupper('5') == '5');
	tlib_test_ok(ft_toupper('G') == 'G');
	tlib_test_ok(ft_toupper('j') == 'J');
	tlib_test_ok(ft_toupper(0x80) == 0x80);
	tlib_test_ok(tlib_alloc_count() == 0);
}
