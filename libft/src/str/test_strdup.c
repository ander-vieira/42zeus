/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:12:10 by andeviei          #+#    #+#             */
/*   Updated: 2024/10/02 23:46:19 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_strdup_testone(char *str)
{
	char	*result;

	tlib_mockmalloc_reset();
	result = ft_strdup(str);
	tlib_testresult_bool(!strcmp(result, str));
	tlib_testmalloc_size(result, strlen(str) + 1);
	tlib_testmalloc_count(1);
	free(str);
}

static void	test_strdup_child1(void)
{
	test_strdup_testone("ABCDE");
	test_strdup_testone("");
}

static void	test_strdup_child2(void)
{
	tlib_mockmalloc_reset();
	tlib_mockmalloc_setmock(1);
	tlib_testresult_bool(ft_strdup("HOLA") == NULL);
}

static void	test_strdup_child3(void)
{
	tlib_testresult_bool(ft_strdup(NULL) == NULL);
}

void	test_strdup(void)
{
	tlib_test_process(&test_strdup_child1, PRESULT_OK);
	tlib_test_process(&test_strdup_child2, PRESULT_OK);
	tlib_test_process(&test_strdup_child3, PRESULT_SEGFAULT);
}
