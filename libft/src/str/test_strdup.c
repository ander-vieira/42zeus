/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:12:10 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/19 14:52:10 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_strdup_testone(char *str)
{
	char	*result;

	tlib_alloc_reset();
	result = ft_strdup(str);
	tlib_test_ok(!strcmp(result, str));
	tlib_test_ok(tlib_alloc_lookup(result) == strlen(str) + 1);
	tlib_test_ok(tlib_alloc_count() == 1);
	free(str);
}

static void	test_strdup_child1(void)
{
	test_strdup_testone("ABCDE");
	test_strdup_testone("");
}

static void	test_strdup_child2(void)
{
	tlib_alloc_reset();
	tlib_alloc_setmock(1);
	tlib_test_ok(ft_strdup("HOLA") == NULL);
}

static void	test_strdup_child3(void)
{
	tlib_test_ok(ft_strdup(NULL) == NULL);
}

void	test_strdup(void)
{
	tlib_test_process(&test_strdup_child1, PRESULT_OK);
	tlib_test_process(&test_strdup_child2, PRESULT_OK);
	tlib_test_process(&test_strdup_child3, PRESULT_SEGFAULT);
}
