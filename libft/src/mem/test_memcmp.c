/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:32:35 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/17 15:05:46 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_memcmp_child1(void)
{
	tlib_alloc_reset();
	tlib_test_ok(!ft_memcmp("ASDFG", "ASDFG", 5));
	tlib_test_ok(ft_memcmp("ASDFG", "ASDFH", 5));
	tlib_test_ok(ft_memcmp("ASDFG", "ASFFG", 5));
	tlib_test_ok(!ft_memcmp("ASDFG", "ASDFH", 4));
	tlib_test_ok(!ft_memcmp("ASDFG", "ASD", 3));
	tlib_test_ok(!ft_memcmp("ASD", "ASDFG", 3));
	tlib_test_ok(ft_memcmp("ASD\0G", "ASD\0H", 5));
	tlib_test_ok(tlib_alloc_count() == 0);
}

static void	test_memcmp_child2(void)
{
	tlib_alloc_reset();
	tlib_test_ok(!ft_memcmp(NULL, "ASDFG", 0));
	tlib_test_ok(!ft_memcmp("ASDFG", NULL, 0));
	tlib_test_ok(!ft_memcmp(NULL, NULL, 0));
	tlib_test_ok(!ft_memcmp(NULL, NULL, 5));
	tlib_test_ok(tlib_alloc_count() == 0);
}

static void	test_memcmp_child3(void)
{
	ft_memcmp(NULL, "ASDFG", 5);
}

static void	test_memcmp_child4(void)
{
	ft_memcmp("ASDFG", NULL, 5);
}

void	test_memcmp(void)
{
	tlib_test_process(&test_memcmp_child1, PRESULT_OK);
	tlib_test_process(&test_memcmp_child2, PRESULT_OK);
	tlib_test_process(&test_memcmp_child3, PRESULT_SEGFAULT);
	tlib_test_process(&test_memcmp_child4, PRESULT_SEGFAULT);
}
