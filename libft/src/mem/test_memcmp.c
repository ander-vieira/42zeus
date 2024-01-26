/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:32:35 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 11:47:41 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	test_memcmp_child1(void)
{
	tlib_alloc_reset();
	tlib_print_test(!ft_memcmp("ASDFG", "ASDFG", 5));
	tlib_print_test(ft_memcmp("ASDFG", "ASDFH", 5));
	tlib_print_test(ft_memcmp("ASDFG", "ASFFG", 5));
	tlib_print_test(!ft_memcmp("ASDFG", "ASDFH", 4));
	tlib_print_test(!ft_memcmp("ASDFG", "ASD", 3));
	tlib_print_test(!ft_memcmp("ASD", "ASDFG", 3));
	tlib_print_test(ft_memcmp("ASD\0G", "ASD\0H", 5));
	tlib_print_test(tlib_alloc_count() == 0);
	return (0);
}

static int	test_memcmp_child2(void)
{
	tlib_alloc_reset();
	tlib_print_test(!ft_memcmp(NULL, "ASDFG", 0));
	tlib_print_test(!ft_memcmp("ASDFG", NULL, 0));
	tlib_print_test(!ft_memcmp(NULL, NULL, 0));
	tlib_print_test(!ft_memcmp(NULL, NULL, 5));
	tlib_print_test(tlib_alloc_count() == 0);
	return (0);
}

static int	test_memcmp_child3(void)
{
	ft_memcmp(NULL, "ASDFG", 5);
	return (0);
}

static int	test_memcmp_child4(void)
{
	ft_memcmp("ASDFG", NULL, 5);
	return (0);
}

void	test_memcmp(void)
{
	tlib_print_test(tlib_run_process(&test_memcmp_child1) == 0);
	tlib_print_test(tlib_run_process(&test_memcmp_child2) == 0);
	tlib_print_test(tlib_run_process(&test_memcmp_child3) != 0);
	tlib_print_test(tlib_run_process(&test_memcmp_child4) != 0);
}
