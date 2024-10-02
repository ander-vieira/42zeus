/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strtrim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:38:54 by andeviei          #+#    #+#             */
/*   Updated: 2024/10/02 23:46:19 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_strtrim_testone(char *str, char *set, char *expected)
{
	char	*result;

	tlib_mockmalloc_reset();
	result = ft_strtrim(str, set);
	tlib_testresult_bool(result != NULL && !strcmp(result, expected));
	tlib_testmalloc_size(result, strlen(expected) + 1);
	tlib_testmalloc_count(1);
	free(result);
}

static void	test_strtrim_child1(void)
{
	test_strtrim_testone("A B", " ", "A B");
	test_strtrim_testone(" A B  ", " ", "A B");
	test_strtrim_testone("C ACBCC", "C", " ACB");
	test_strtrim_testone(" . A .B.. .", " .", "A .B");
	test_strtrim_testone("    ", " ", "");
	test_strtrim_testone(" . .. .", " .", "");
	test_strtrim_testone("", " ", "");
	test_strtrim_testone(" A B ", "", " A B ");
}

static void	test_strtrim_child2(void)
{
	tlib_mockmalloc_reset();
	tlib_mockmalloc_setmock(1);
	tlib_testresult_bool(ft_strtrim(" A ", " ") == NULL);
}

static void	test_strtrim_child3(void)
{
	tlib_testresult_bool(ft_strtrim(NULL, " ") == NULL);
}

static void	test_strtrim_child4(void)
{
	tlib_testresult_bool(ft_strtrim(" ", NULL) == NULL);
}

void	test_strtrim(void)
{
	tlib_test_process(&test_strtrim_child1, PRESULT_OK);
	tlib_test_process(&test_strtrim_child2, PRESULT_OK);
	tlib_test_process(&test_strtrim_child3, PRESULT_OK);
	tlib_test_process(&test_strtrim_child4, PRESULT_OK);
}
