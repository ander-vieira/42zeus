/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:41:51 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 09:32:59 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	test_atoi_crash1(void *ctx)
{
	(void)ctx;
	ft_atoi(NULL);
	return (0);
}

void	test_atoi(void)
{
	tlib_print_test(ft_atoi("53") == 53);
	tlib_print_test(ft_atoi("-417") == -417);
	tlib_print_test(ft_atoi("0") == 0);
	tlib_print_test(ft_atoi("+0") == 0);
	tlib_print_test(ft_atoi("-0") == 0);
	tlib_print_test(ft_atoi("+53") == 53);
	tlib_print_test(ft_atoi("2147483647") == 2147483647);
	tlib_print_test(ft_atoi("+2147483647") == 2147483647);
	tlib_print_test(ft_atoi("-2147483648") == -2147483648);
	tlib_print_test(ft_atoi("   53") == 53);
	tlib_print_test(ft_atoi("   +53") == 53);
	tlib_print_test(ft_atoi("   -5198") == -5198);
	tlib_print_test(ft_atoi(" \n3") == 3);
	tlib_print_test(ft_atoi("0.5") == 0);
	tlib_print_test(ft_atoi("0,5") == 0);
	tlib_print_test(ft_atoi("13aaagh764") == 13);
	tlib_print_test(ft_atoi("aaa  13aaagh764") == 0);
	tlib_print_test(ft_atoi("  153aaagh764") == 153);
	tlib_print_test(ft_atoi("   -2147483648aaa5") == -2147483648);
	tlib_print_test(ft_atoi("+-69") == 0);
	tlib_print_test(ft_atoi("-+69") == 0);
	tlib_print_test(ft_atoi("   -+69") == 0);
	tlib_print_test(tlib_alloc_count() == 0);
	tlib_print_test(tlib_run_process(&test_atoi_crash1, NULL));
	tlib_alloc_reset();
}
