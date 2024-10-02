/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:14:57 by andeviei          #+#    #+#             */
/*   Updated: 2024/10/02 23:46:19 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_tolower(void)
{
	tlib_mockmalloc_reset();
	tlib_testresult_bool(ft_tolower('\0') == '\0');
	tlib_testresult_bool(ft_tolower('\n') == '\n');
	tlib_testresult_bool(ft_tolower(' ') == ' ');
	tlib_testresult_bool(ft_tolower('5') == '5');
	tlib_testresult_bool(ft_tolower('G') == 'g');
	tlib_testresult_bool(ft_tolower('j') == 'j');
	tlib_testresult_bool(ft_tolower(0x80) == 0x80);
	tlib_testmalloc_count(0);
}

void	test_toupper(void)
{
	tlib_mockmalloc_reset();
	tlib_testresult_bool(ft_toupper('\0') == '\0');
	tlib_testresult_bool(ft_toupper('\n') == '\n');
	tlib_testresult_bool(ft_toupper(' ') == ' ');
	tlib_testresult_bool(ft_toupper('5') == '5');
	tlib_testresult_bool(ft_toupper('G') == 'G');
	tlib_testresult_bool(ft_toupper('j') == 'J');
	tlib_testresult_bool(ft_toupper(0x80) == 0x80);
	tlib_testmalloc_count(0);
}
