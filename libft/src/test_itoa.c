/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:32:38 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/17 15:05:18 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_itoa_testone(int num, char *expected)
{
	char	*str;

	str = ft_itoa(num);
	tlib_test_ok(!strcmp(str, expected));
	tlib_test_ok(tlib_alloc_lookup(str) == strlen(expected) + 1);
	free(str);
}

static void	test_itoa_child1(void)
{
	tlib_alloc_reset();
	test_itoa_testone(314, "314");
	test_itoa_testone(0, "0");
	test_itoa_testone(-4268, "-4268");
	test_itoa_testone(2147483647, "2147483647");
	test_itoa_testone(-2147483648, "-2147483648");
	tlib_test_ok(tlib_alloc_count() == 0);
}

static void	test_itoa_child2(void)
{
	tlib_alloc_setmock(1);
	tlib_test_ok(ft_itoa(5) == NULL);
}

void	test_itoa(void)
{
	tlib_test_process(&test_itoa_child1, PRESULT_OK);
	tlib_test_process(&test_itoa_child2, PRESULT_OK);
}
