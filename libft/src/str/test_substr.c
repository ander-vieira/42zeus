/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_substr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:20:57 by andeviei          #+#    #+#             */
/*   Updated: 2024/10/02 23:46:19 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_substr_testone(char *str, unsigned int start, size_t len,
	char *expected)
{
	char	*result;

	tlib_mockmalloc_reset();
	result = ft_substr(str, start, len);
	tlib_testresult_bool(result != NULL && !strcmp(result, expected));
	tlib_testmalloc_size(result, strlen(expected) + 1);
	tlib_testmalloc_count(1);
	free(result);
}

static void	test_substr_child1(void)
{
	test_substr_testone("ABCDEF", 0, 2, "AB");
	test_substr_testone("ABCDEF", 2, 3, "CDE");
	test_substr_testone("ABCDEF", 3, 3, "DEF");
	test_substr_testone("ABCDEF", 3, 0, "");
	test_substr_testone("ABCDEF", 4, 4, "EF");
	test_substr_testone("ABCDEF", 8, 4, "");
}

static void	test_substr_child2(void)
{
	tlib_mockmalloc_reset();
	tlib_mockmalloc_setmock(1);
	tlib_testresult_bool(ft_substr("ABCDEF", 0, 4) == NULL);
}

static void	test_substr_child3(void)
{
	tlib_testresult_bool(ft_substr(NULL, 0, 4) == NULL);
}

void	test_substr(void)
{
	tlib_test_process(&test_substr_child1, PRESULT_OK);
	tlib_test_process(&test_substr_child2, PRESULT_OK);
	tlib_test_process(&test_substr_child3, PRESULT_OK);
}
