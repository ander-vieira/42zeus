/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:41:51 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 11:13:25 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_atoi_child1_1(void)
{
	tlib_alloc_reset();
	tlib_print_test(ft_atoi("4") == 4);
	tlib_print_test(ft_atoi("42") == 42);
	tlib_print_test(ft_atoi("4242") == 4242);
	tlib_print_test(ft_atoi("0") == 0);
	tlib_print_test(ft_atoi("+4") == 4);
	tlib_print_test(ft_atoi("+42") == 42);
	tlib_print_test(ft_atoi("+4242") == 4242);
	tlib_print_test(ft_atoi("+0") == 0);
	tlib_print_test(ft_atoi("-6") == -6);
	tlib_print_test(ft_atoi("-777") == -777);
	tlib_print_test(ft_atoi("-4343") == -4343);
	tlib_print_test(ft_atoi("-0") == 0);
	tlib_print_test(ft_atoi("2147483647") == 2147483647);
	tlib_print_test(ft_atoi("+2147483647") == 2147483647);
	tlib_print_test(ft_atoi("-2147483648") == -2147483648);
	tlib_print_test(ft_atoi("2147483648") == -2147483648);
	tlib_print_test(ft_atoi("+2147483648") == -2147483648);
}

static int	test_atoi_child1(void *ctx)
{
	(void)ctx;
	test_atoi_child1_1();
	tlib_print_test(ft_atoi("88aaa") == 88);
	tlib_print_test(ft_atoi("100b.g") == 100);
	tlib_print_test(ft_atoi("f55") == 0);
	tlib_print_test(ft_atoi("500  13") == 500);
	tlib_print_test(ft_atoi(" 34") == 34);
	tlib_print_test(ft_atoi("   51") == 51);
	tlib_print_test(ft_atoi("\n681") == 681);
	tlib_print_test(ft_atoi("  \n \t 7007") == 7007);
	tlib_print_test(ft_atoi("   124aaa5") == 124);
	tlib_print_test(ft_atoi(" +153") == 153);
	tlib_print_test(ft_atoi(" -169") == -169);
	tlib_print_test(ft_atoi("  \n -2147483648  5a7") == -2147483648);
	tlib_print_test(ft_atoi("+-101") == 0);
	tlib_print_test(ft_atoi("-+102") == 0);
	tlib_print_test(ft_atoi("--103") == 0);
	tlib_print_test(ft_atoi("++104") == 0);
	tlib_print_test(ft_atoi("   -+117") == 0);
	tlib_print_test(tlib_alloc_count() == 0);
	return (0);
}

static int	test_atoi_child2(void *ctx)
{
	(void)ctx;
	ft_atoi(NULL);
	return (0);
}

void	test_atoi(void)
{
	tlib_print_test(tlib_run_process(&test_atoi_child1, NULL) == 0);
	tlib_print_test(tlib_run_process(&test_atoi_child2, NULL) != 0);
}
