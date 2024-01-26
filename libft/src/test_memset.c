/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:23:25 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 09:26:46 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	test_memset_child1(void *ctx)
{
	char	buf[5];

	(void)ctx;
	tlib_print_test("1", ft_memset(buf, 'A', 5) == buf, FALSE);
	tlib_print_test("2", !memcmp(buf, "AAAAA", 5), FALSE);
	tlib_print_test("3", ft_memset(buf, 'B', 2) == buf, FALSE);
	tlib_print_test("4", !memcmp(buf, "BBAAA", 5), FALSE);
	tlib_print_test("5", ft_memset(buf, 256 + '.', 4) == buf, FALSE);
	tlib_print_test("6", !memcmp(buf, "....A", 5), FALSE);
	tlib_print_test("7", ft_memset(buf, '\0', 1) == buf, FALSE);
	tlib_print_test("8", !memcmp(buf, "\0...A", 5), FALSE);
	tlib_print_test("9", tlib_alloc_count() == 0, FALSE);
	return (0);
}

static int	test_memset_child2(void *ctx)
{
	char	buf[5];

	(void)ctx;
	memset(buf, 'A', 5);
	ft_memset(buf, 'B', 0);
	tlib_print_test("11", !memcmp(buf, "AAAAA", 5), FALSE);
	tlib_print_test("12", tlib_alloc_count() == 0, FALSE);
	return (0);
}

static int	test_memset_child3(void *ctx)
{
	(void)ctx;
	ft_memset(NULL, 'p', 5);
	return (0);
}

void	test_memset(void)
{
	tlib_print_test("10",
		tlib_run_process(&test_memset_child1, NULL) == 0, FALSE);
	tlib_print_test("13",
		tlib_run_process(&test_memset_child2, NULL) == 0, FALSE);
	tlib_print_test("14",
		tlib_run_process(&test_memset_child3, NULL) != 0, TRUE);
	tlib_alloc_reset();
}