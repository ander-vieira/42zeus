/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_substr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:20:57 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 11:47:41 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	test_substr_crash1(void)
{
	char	*str;
	int		status;

	str = ft_substr(NULL, 0, 4);
	if (str == NULL)
		status = 0;
	else
		status = 1;
	free(str);
	return (status);
}

static int	test_substr_crash2(void)
{
	char	*str;
	int		status;

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
	tlib_print_test(tlib_run_process(&test_substr_crash1) == 0);
	tlib_print_test(tlib_run_process(&test_substr_crash2) == 0);
	tlib_print_test(tlib_alloc_errors() == 0x00);
	tlib_alloc_reset();
}

void	test_substr(void)
{
	char	*str;

	str = ft_substr("HOLA MUNDO", 0, 4);
	tlib_print_test(str != NULL && !strcmp(str, "HOLA"));
	tlib_print_test(tlib_alloc_lookup(str) == 5);
	tlib_print_test(tlib_alloc_count() == 1);
	free(str);
	str = ft_substr("HOLA MUNDO", 4, 5);
	tlib_print_test(str != NULL && !strcmp(str, " MUND"));
	tlib_print_test(tlib_alloc_lookup(str) == 6);
	tlib_print_test(tlib_alloc_count() == 1);
	free(str);
	str = ft_substr("HOLA MUNDO", 7, 6);
	tlib_print_test(str != NULL && !strcmp(str, "NDO"));
	tlib_print_test(tlib_alloc_lookup(str) == 4);
	tlib_print_test(tlib_alloc_count() == 1);
	free(str);
	str = ft_substr("HOLA MUNDO", 15, 8);
	tlib_print_test(str != NULL && !strcmp(str, ""));
	tlib_print_test(tlib_alloc_lookup(str) == 1);
	tlib_print_test(tlib_alloc_count() == 1);
	free(str);
	test_substr2();
}
