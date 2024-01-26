/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:32:38 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 12:25:33 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	test_itoa_crash1(void)
{
	char	*str;
	int		status;

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
	tlib_test_ok(!strcmp(str, "-2147483648"));
	tlib_test_ok(tlib_alloc_lookup(str) == 12);
	tlib_test_ok(tlib_alloc_count() == 1);
	free(str);
	tlib_test_ok(tlib_alloc_errors() == 0x00);
	tlib_test_ok(tlib_run_process(&test_itoa_crash1) == 0);
}

void	test_itoa(void)
{
	char	*str;

	str = ft_itoa(50);
	tlib_test_ok(!strcmp(str, "50"));
	tlib_test_ok(tlib_alloc_lookup(str) == 3);
	tlib_test_ok(tlib_alloc_count() == 1);
	free(str);
	str = ft_itoa(0);
	tlib_test_ok(!strcmp(str, "0"));
	tlib_test_ok(tlib_alloc_lookup(str) == 2);
	tlib_test_ok(tlib_alloc_count() == 1);
	free(str);
	str = ft_itoa(-42069);
	tlib_test_ok(!strcmp(str, "-42069"));
	tlib_test_ok(tlib_alloc_lookup(str) == 7);
	tlib_test_ok(tlib_alloc_count() == 1);
	free(str);
	str = ft_itoa(2147483647);
	tlib_test_ok(!strcmp(str, "2147483647"));
	tlib_test_ok(tlib_alloc_lookup(str) == 11);
	tlib_test_ok(tlib_alloc_count() == 1);
	free(str);
	test_itoa2();
	tlib_alloc_reset();
}
