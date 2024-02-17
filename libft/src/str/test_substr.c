/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_substr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:20:57 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/17 17:35:31 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

//TODO

static void	test_substr_crash1(void)
{
	char	*str;

	str = ft_substr(NULL, 0, 4);
	tlib_test_ok(str == NULL);
}

static void	test_substr_crash2(void)
{
	char	*str;

	tlib_alloc_setmock(1);
	str = ft_substr("HOLA MUNDO", 0, 4);
	tlib_test_ok(str == NULL);
}

void	test_substr(void)
{
	char	*str;

	tlib_alloc_reset();
	str = ft_substr("HOLA MUNDO", 0, 4);
	tlib_test_ok(str != NULL && !strcmp(str, "HOLA"));
	tlib_test_ok(tlib_alloc_lookup(str) == 5);
	tlib_test_ok(tlib_alloc_count() == 1);
	free(str);
	str = ft_substr("HOLA MUNDO", 4, 5);
	tlib_test_ok(str != NULL && !strcmp(str, " MUND"));
	tlib_test_ok(tlib_alloc_lookup(str) == 6);
	tlib_test_ok(tlib_alloc_count() == 1);
	free(str);
	str = ft_substr("HOLA MUNDO", 7, 6);
	tlib_test_ok(str != NULL && !strcmp(str, "NDO"));
	tlib_test_ok(tlib_alloc_lookup(str) == 4);
	tlib_test_ok(tlib_alloc_count() == 1);
	free(str);
	str = ft_substr("HOLA MUNDO", 15, 8);
	tlib_test_ok(str != NULL && !strcmp(str, ""));
	tlib_test_ok(tlib_alloc_lookup(str) == 1);
	tlib_test_ok(tlib_alloc_count() == 1);
	free(str);
	tlib_test_process(&test_substr_crash1, PRESULT_OK);
	tlib_test_process(&test_substr_crash2, PRESULT_OK);
}
