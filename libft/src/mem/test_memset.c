/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:23:25 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 10:35:48 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	test_memset_child1(void *ctx)
{
	char	buf[5];

	(void)ctx;
	tlib_alloc_reset();
	tlib_print_test(ft_memset(buf, 'A', 5) == buf);
	tlib_print_test(!memcmp(buf, "AAAAA", 5));
	tlib_print_test(ft_memset(buf, 'B', 2) == buf);
	tlib_print_test(!memcmp(buf, "BBAAA", 5));
	tlib_print_test(ft_memset(buf, 'C' + 256, 4) == buf);
	tlib_print_test(!memcmp(buf, "CCCCA", 5));
	tlib_print_test(ft_memset(buf + 3, '\0', 1) == buf + 3);
	tlib_print_test(!memcmp(buf, "CCC\0A", 5));
	tlib_print_test(tlib_alloc_count() == 0);
	return (0);
}

static int	test_memset_child2(void *ctx)
{
	char	buf[5];

	(void)ctx;
	tlib_alloc_reset();
	memset(buf, 'A', 5);
	tlib_print_test(ft_memset(NULL, 'A', 0) == NULL);
	tlib_print_test(ft_memset(buf, 'B', 0) == buf);
	tlib_print_test(!memcmp(buf, "AAAAA", 5));
	tlib_print_test(tlib_alloc_count() == 0);
	return (0);
}

static int	test_memset_child3(void *ctx)
{
	(void)ctx;
	ft_memset(NULL, 'A', 5);
	return (0);
}

void	test_memset(void)
{
	tlib_print_test(tlib_run_process(&test_memset_child1, NULL) == 0);
	tlib_print_test(tlib_run_process(&test_memset_child2, NULL) == 0);
	tlib_print_test(tlib_run_process(&test_memset_child3, NULL) != 0);
	tlib_alloc_reset();
}
