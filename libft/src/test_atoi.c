/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:41:51 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/19 13:26:20 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int		ft_atoi(const char *str) __attribute__((weak));

static void	test_atoi1(void)
{
	tlib_print_test("1", ft_atoi("53") == 53, FALSE);
	tlib_print_test("2", ft_atoi("-417") == -417, FALSE);
	tlib_print_test("3", ft_atoi("0") == 0, FALSE);
	tlib_print_test("4", ft_atoi("+0") == 0, FALSE);
	tlib_print_test("5", ft_atoi("-0") == 0, FALSE);
	tlib_print_test("6", ft_atoi("+53") == 53, FALSE);
	tlib_print_test("7", ft_atoi("2147483647") == 2147483647, FALSE);
	tlib_print_test("8", ft_atoi("+2147483647") == 2147483647, FALSE);
	tlib_print_test("9", ft_atoi("-2147483648") == -2147483648, FALSE);
	tlib_print_test("10", ft_atoi("   53") == 53, FALSE);
	tlib_print_test("11", ft_atoi("   +53") == 53, FALSE);
	tlib_print_test("12", ft_atoi("   -5198") == -5198, FALSE);
	tlib_print_test("13", ft_atoi(" \n3") == 3, FALSE);
	tlib_print_test("14", ft_atoi("0.5") == 0, FALSE);
	tlib_print_test("15", ft_atoi("0,5") == 0, FALSE);
	tlib_print_test("16", ft_atoi("13aaagh764") == 13, FALSE);
	tlib_print_test("17", ft_atoi("aaa  13aaagh764") == 0, FALSE);
	tlib_print_test("18", ft_atoi("  153aaagh764") == 153, FALSE);
	tlib_print_test("19", ft_atoi("   -2147483648aaa5") == -2147483648, FALSE);
	tlib_print_test("20", ft_atoi("+-69") == 0, FALSE);
	tlib_print_test("21", ft_atoi("-+69") == 0, FALSE);
	tlib_print_test("22", ft_atoi("   -+69") == 0, TRUE);
}

void	test_atoi(void)
{
	tlib_print_missing(&test_atoi1, &ft_atoi, "atoi");
}
