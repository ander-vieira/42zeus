/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:15:49 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 09:39:33 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_isalpha(void)
{
	tlib_print_test(ft_isalpha('a'));
	tlib_print_test(ft_isalpha('F'));
	tlib_print_test(!ft_isalpha('3'));
	tlib_print_test(!ft_isalpha(' '));
	tlib_print_test(!ft_isalpha('.'));
	tlib_print_test(!ft_isalpha(127));
	tlib_print_test(tlib_alloc_count() == 0);
	tlib_alloc_reset();
}

void	test_isdigit(void)
{
	tlib_print_test(ft_isdigit('5'));
	tlib_print_test(!ft_isdigit('d'));
	tlib_print_test(!ft_isdigit(' '));
	tlib_print_test(!ft_isdigit(5));
	tlib_print_test(tlib_alloc_count() == 0);
	tlib_alloc_reset();
}

void	test_isalnum(void)
{
	tlib_print_test(ft_isalnum('5'));
	tlib_print_test(ft_isalnum('d'));
	tlib_print_test(ft_isalnum('J'));
	tlib_print_test(!ft_isalnum(' '));
	tlib_print_test(!ft_isalnum(5));
	tlib_print_test(tlib_alloc_count() == 0);
	tlib_alloc_reset();
}

void	test_isascii(void)
{
	tlib_print_test(ft_isascii('0'));
	tlib_print_test(ft_isascii(0x00));
	tlib_print_test(ft_isascii(0x7F));
	tlib_print_test(!ft_isascii(0x80));
	tlib_print_test(!ft_isascii(0x100));
	tlib_print_test(tlib_alloc_count() == 0);
	tlib_alloc_reset();
}

void	test_isprint(void)
{
	tlib_print_test(!ft_isprint(0));
	tlib_print_test(!ft_isprint('\n'));
	tlib_print_test(ft_isprint(' '));
	tlib_print_test(ft_isprint('5'));
	tlib_print_test(ft_isprint('A'));
	tlib_print_test(ft_isprint('a'));
	tlib_print_test(ft_isprint('~'));
	tlib_print_test(!ft_isprint(0x7F));
	tlib_print_test(!ft_isprint(0x100));
	tlib_print_test(tlib_alloc_count() == 0);
	tlib_alloc_reset();
}
