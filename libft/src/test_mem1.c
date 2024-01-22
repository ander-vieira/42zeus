/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mem1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:23:25 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/22 16:01:15 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	test_bzero_crash1(void *ctx)
{
	(void)ctx;
	ft_bzero(NULL, 5);
	return (0);
}

static void	test_bzero(void)
{
	char	buf[5];

	ft_bzero(buf, 5);
	tlib_print_test("1", !memcmp(buf, "\0\0\0\0\0", 5), FALSE);
	tlib_print_test("2", tlib_alloc_count() == 0, FALSE);
	tlib_print_test("3", tlib_run_process(&test_bzero_crash1, NULL) != 0, TRUE);
	tlib_alloc_reset();
}

static int	test_memset_crash1(void *ctx)
{
	(void)ctx;
	ft_memset(NULL, 'p', 5);
	return (0);
}

static void	test_memset(void)
{
	char	buf[5];

	tlib_print_test("1", ft_memset(buf, '\0', 5) == buf, FALSE);
	tlib_print_test("2", !memcmp(buf, "\0\0\0\0\0", 5), FALSE);
	tlib_print_test("3", ft_memset(buf, '5', 5) == buf, FALSE);
	tlib_print_test("4", !memcmp(buf, "55555", 5), FALSE);
	tlib_print_test("5", ft_memset(buf, 256 + '.', 3) == buf, FALSE);
	tlib_print_test("6", !memcmp(buf, "...", 3), FALSE);
	tlib_print_test("7", tlib_alloc_count() == 0, FALSE);
	tlib_print_test("8", tlib_run_process(&test_memset_crash1, NULL) != 0, TRUE);
	tlib_alloc_reset();
}

void	test_mem1(void)
{
	tlib_print_missing(&test_bzero, &ft_bzero, "bzero");
	tlib_print_missing(&test_memset, &ft_memset, "memset");
}
