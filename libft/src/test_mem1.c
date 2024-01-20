/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mem1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:23:25 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/20 18:39:41 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_bzero(void)
{
	char	buf[5];

	ft_bzero(buf, 5);
	tlib_print_test("1", !memcmp(buf, "\0\0\0\0\0", 5), FALSE);
	tlib_print_test("2", tlib_alloc_count() == 0, TRUE);
	tlib_alloc_reset();
}

static void	test_memset(void)
{
	char	buf[5];

	tlib_print_test("1", ft_memset(buf, '\0', 5) == buf, FALSE);
	tlib_print_test("2", !memcmp(buf, "\0\0\0\0\0", 5), FALSE);
	tlib_print_test("3", ft_memset(buf, '5', 5) == buf, FALSE);
	tlib_print_test("4", !memcmp(buf, "55555", 5), FALSE);
	tlib_print_test("5", tlib_alloc_count() == 0, TRUE);
	tlib_alloc_reset();
}

static void	test_memcpy(void)
{
	char	buf[5];

	tlib_print_test("1", ft_memcpy(buf, "AS DF", 5) == buf, FALSE);
	tlib_print_test("2", !memcmp(buf, "AS DF", 5), FALSE);
	tlib_print_test("3", tlib_alloc_count() == 0, TRUE);
	tlib_alloc_reset();
}

static void	test_memmove(void)
{
	char	buf[5];

	tlib_print_test("1", ft_memmove(buf, "AS DF", 5) == buf, FALSE);
	tlib_print_test("2", !memcmp(buf, "AS DF", 5), FALSE);
	tlib_print_test("3", ft_memmove(buf, buf + 3, 2) == buf, FALSE);
	tlib_print_test("4", !memcmp(buf, "DF DF", 5), FALSE);
	tlib_print_test("5", ft_memmove(buf + 2, buf, 3) == buf + 2, FALSE);
	tlib_print_test("6", !memcmp(buf, "DFDF ", 5), FALSE);
	tlib_print_test("7", tlib_alloc_count() == 0, TRUE);
	tlib_alloc_reset();
}

void	test_mem1(void)
{
	tlib_print_missing(&test_bzero, &ft_bzero, "bzero");
	tlib_print_missing(&test_memset, &ft_memset, "memset");
	tlib_print_missing(&test_memcpy, &ft_memcpy, "memcpy");
	tlib_print_missing(&test_memmove, &ft_memmove, "memmove");
}
