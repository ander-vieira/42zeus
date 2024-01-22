/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:32:38 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/22 20:32:47 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	test_itoa_crash1(void *ctx)
{
	char	*str;
	int		status;

	(void)ctx;
	tlib_alloc_setmock(1);
	str = ft_itoa(5);
	if (str == NULL)
		status = 0;
	else
		status = 1;
	free(str);
	return (status);
}

static void	test_itoa2(void)
{
	char	*str;

	str = ft_itoa(-2147483648);
	tlib_print_test("13", !strcmp(str, "-2147483648"), FALSE);
	tlib_print_test("14", tlib_alloc_lookup(str) == 12, FALSE);
	tlib_print_test("15", tlib_alloc_count() == 1, FALSE);
	free(str);
	tlib_print_test("16", tlib_alloc_errors() == 0x00, FALSE);
	tlib_print_test("17", tlib_run_process(&test_itoa_crash1, NULL) == 0, TRUE);
}

void	test_itoa(void)
{
	char	*str;

	str = ft_itoa(50);
	tlib_print_test("1", !strcmp(str, "50"), FALSE);
	tlib_print_test("2", tlib_alloc_lookup(str) == 3, FALSE);
	tlib_print_test("3", tlib_alloc_count() == 1, FALSE);
	free(str);
	str = ft_itoa(0);
	tlib_print_test("4", !strcmp(str, "0"), FALSE);
	tlib_print_test("5", tlib_alloc_lookup(str) == 2, FALSE);
	tlib_print_test("6", tlib_alloc_count() == 1, FALSE);
	free(str);
	str = ft_itoa(-42069);
	tlib_print_test("7", !strcmp(str, "-42069"), FALSE);
	tlib_print_test("8", tlib_alloc_lookup(str) == 7, FALSE);
	tlib_print_test("9", tlib_alloc_count() == 1, FALSE);
	free(str);
	str = ft_itoa(2147483647);
	tlib_print_test("10", !strcmp(str, "2147483647"), FALSE);
	tlib_print_test("11", tlib_alloc_lookup(str) == 11, FALSE);
	tlib_print_test("12", tlib_alloc_count() == 1, FALSE);
	free(str);
	test_itoa2();
	tlib_alloc_reset();
}
