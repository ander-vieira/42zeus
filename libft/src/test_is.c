/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:15:49 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 12:25:33 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_isalpha(void)
{
	tlib_alloc_reset();
	tlib_test_ok(ft_isalpha('a'));
	tlib_test_ok(ft_isalpha('F'));
	tlib_test_ok(!ft_isalpha('3'));
	tlib_test_ok(!ft_isalpha(' '));
	tlib_test_ok(!ft_isalpha('.'));
	tlib_test_ok(!ft_isalpha(127));
	tlib_test_ok(tlib_alloc_count() == 0);
}

void	test_isdigit(void)
{
	tlib_alloc_reset();
	tlib_test_ok(ft_isdigit('5'));
	tlib_test_ok(!ft_isdigit('d'));
	tlib_test_ok(!ft_isdigit(' '));
	tlib_test_ok(!ft_isdigit(5));
	tlib_test_ok(tlib_alloc_count() == 0);
}

void	test_isalnum(void)
{
	tlib_alloc_reset();
	tlib_test_ok(ft_isalnum('5'));
	tlib_test_ok(ft_isalnum('d'));
	tlib_test_ok(ft_isalnum('J'));
	tlib_test_ok(!ft_isalnum(' '));
	tlib_test_ok(!ft_isalnum(5));
	tlib_test_ok(tlib_alloc_count() == 0);
}

void	test_isascii(void)
{
	tlib_alloc_reset();
	tlib_test_ok(ft_isascii('0'));
	tlib_test_ok(ft_isascii(0x00));
	tlib_test_ok(ft_isascii(0x7F));
	tlib_test_ok(!ft_isascii(0x80));
	tlib_test_ok(!ft_isascii(0x100));
	tlib_test_ok(tlib_alloc_count() == 0);
}

void	test_isprint(void)
{
	tlib_alloc_reset();
	tlib_test_ok(!ft_isprint(0));
	tlib_test_ok(!ft_isprint('\n'));
	tlib_test_ok(ft_isprint(' '));
	tlib_test_ok(ft_isprint('5'));
	tlib_test_ok(ft_isprint('A'));
	tlib_test_ok(ft_isprint('a'));
	tlib_test_ok(ft_isprint('~'));
	tlib_test_ok(!ft_isprint(0x7F));
	tlib_test_ok(!ft_isprint(0x100));
	tlib_test_ok(tlib_alloc_count() == 0);
}
