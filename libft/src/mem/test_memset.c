/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:23:25 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/17 15:05:46 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_memset_child1(void)
{
	char	buf[5];

	tlib_alloc_reset();
	tlib_test_ok(ft_memset(buf, 'A', 5) == buf);
	tlib_test_ok(!memcmp(buf, "AAAAA", 5));
	tlib_test_ok(ft_memset(buf, 'B', 2) == buf);
	tlib_test_ok(!memcmp(buf, "BBAAA", 5));
	tlib_test_ok(ft_memset(buf, 'C' + 256, 4) == buf);
	tlib_test_ok(!memcmp(buf, "CCCCA", 5));
	tlib_test_ok(ft_memset(buf + 3, '\0', 1) == buf + 3);
	tlib_test_ok(!memcmp(buf, "CCC\0A", 5));
	tlib_test_ok(ft_memset(buf, 'A' + 256, 2) == buf);
	tlib_test_ok(!memcmp(buf, "AAC\0A", 5));
	tlib_test_ok(tlib_alloc_count() == 0);
}

static void	test_memset_child2(void)
{
	char	buf[5];

	tlib_alloc_reset();
	memset(buf, 'A', 5);
	tlib_test_ok(ft_memset(NULL, 'A', 0) == NULL);
	tlib_test_ok(ft_memset(buf, 'B', 0) == buf);
	tlib_test_ok(!memcmp(buf, "AAAAA", 5));
	tlib_test_ok(tlib_alloc_count() == 0);
}

static void	test_memset_child3(void)
{
	ft_memset(NULL, 'A', 5);
}

void	test_memset(void)
{
	tlib_test_process(&test_memset_child1, PRESULT_OK);
	tlib_test_process(&test_memset_child2, PRESULT_OK);
	tlib_test_process(&test_memset_child3, PRESULT_SEGFAULT);
	tlib_alloc_reset();
}
