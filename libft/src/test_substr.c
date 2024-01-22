/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_substr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:20:57 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/22 20:06:04 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	test_substr_crash1(void *ctx)
{
	char	*str;
	int		status;

	(void)ctx;
	str = ft_substr(NULL, 0, 4);
	if (str == NULL)
		status = 0;
	else
		status = 1;
	free(str);
	return (status);
}

static int	test_substr_crash2(void *ctx)
{
	char	*str;
	int		status;

	(void)ctx;
	tlib_alloc_setmock(1);
	str = ft_substr("HOLA MUNDO", 0, 4);
	if (str == NULL)
		status = 0;
	else
		status = 1;
	free(str);
	return (status);
}

static void	test_substr2(void)
{
	tlib_print_test("13",
		tlib_run_process(&test_substr_crash1, NULL) == 0, FALSE);
	tlib_print_test("14",
		tlib_run_process(&test_substr_crash2, NULL) == 0, FALSE);
	tlib_print_test("15", tlib_alloc_errors() == 0x00, TRUE);
	tlib_alloc_reset();
}

void	test_substr(void)
{
	char	*str;

	str = ft_substr("HOLA MUNDO", 0, 4);
	tlib_print_test("1", str != NULL && !strcmp(str, "HOLA"), FALSE);
	tlib_print_test("2", tlib_alloc_lookup(str) == 5, FALSE);
	tlib_print_test("3", tlib_alloc_count() == 1, FALSE);
	free(str);
	str = ft_substr("HOLA MUNDO", 4, 5);
	tlib_print_test("4", str != NULL && !strcmp(str, " MUND"), FALSE);
	tlib_print_test("5", tlib_alloc_lookup(str) == 6, FALSE);
	tlib_print_test("6", tlib_alloc_count() == 1, FALSE);
	free(str);
	str = ft_substr("HOLA MUNDO", 7, 6);
	tlib_print_test("7", str != NULL && !strcmp(str, "NDO"), FALSE);
	tlib_print_test("8", tlib_alloc_lookup(str) == 4, FALSE);
	tlib_print_test("9", tlib_alloc_count() == 1, FALSE);
	free(str);
	str = ft_substr("HOLA MUNDO", 15, 8);
	tlib_print_test("10", str != NULL && !strcmp(str, ""), FALSE);
	tlib_print_test("11", tlib_alloc_lookup(str) == 1, FALSE);
	tlib_print_test("12", tlib_alloc_count() == 1, FALSE);
	free(str);
	test_substr2();
}
