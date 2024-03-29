/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:38:54 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/19 14:36:29 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_strjoin_testone(char *str1, char *str2, char *expected)
{
	char	*result;

	tlib_alloc_reset();
	result = ft_strjoin(str1, str2);
	tlib_test_ok(result != NULL && !strcmp(result, expected));
	tlib_test_ok(tlib_alloc_lookup(result) == strlen(expected) + 1);
	tlib_test_ok(tlib_alloc_count() == 1);
	free(result);
}

static void	test_strjoin_child1(void)
{
	test_strjoin_testone("HOLA", "MUNDO", "HOLAMUNDO");
	test_strjoin_testone("HOLA", "", "HOLA");
	test_strjoin_testone("", "MUNDO", "MUNDO");
	test_strjoin_testone("", "", "");
}

static void	test_strjoin_child2(void)
{
	tlib_alloc_reset();
	tlib_alloc_setmock(1);
	tlib_test_ok(ft_strjoin("HOLA", "MUNDO") == NULL);
}

static void	test_strjoin_child3(void)
{
	tlib_test_ok(ft_strjoin(NULL, "MUNDO") == NULL);
}

static void	test_strjoin_child4(void)
{
	tlib_test_ok(ft_strjoin("HOLA", NULL) == NULL);
}

void	test_strjoin(void)
{
	tlib_test_process(&test_strjoin_child1, PRESULT_OK);
	tlib_test_process(&test_strjoin_child2, PRESULT_OK);
	tlib_test_process(&test_strjoin_child3, PRESULT_OK);
	tlib_test_process(&test_strjoin_child4, PRESULT_OK);
}
