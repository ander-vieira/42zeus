/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:42:13 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/17 15:05:18 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_split_free(char **split)
{
	size_t	i;

	if (split != NULL)
	{
		i = 0;
		while (split[i] != NULL)
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
}

static void	test_split_testone(char *str, char c, size_t len, ...)
{
	va_list	args;
	char	**split;
	char	*expected;
	size_t	i;

	va_start(args, len);
	tlib_alloc_reset();
	split = ft_split(str, c);
	tlib_test_ok(split != NULL);
	tlib_test_ok(tlib_alloc_lookup(split) == sizeof(char *) * (len + 1));
	i = 0;
	while (i < len)
	{
		expected = va_arg(args, char *);
		tlib_test_ok(split[i] != NULL && !strcmp(split[i], expected) && tlib_alloc_lookup(split[i]) == strlen(expected) + 1);
		i++;
	}
	tlib_test_ok(split[len] == NULL);
	tlib_test_ok(tlib_alloc_count() == len + 1);
	test_split_free(split);
	va_end(args);
}

static void	test_split_child1(void)
{
	test_split_testone("AB CDE F", ' ', 3, "AB", "CDE", "F");
	test_split_testone("   AB  CDE F  ", ' ', 3, "AB", "CDE", "F");
	test_split_testone("     ", ' ', 0);
	test_split_testone("AABABBACAA", 'A', 3, "B", "BB", "C");
}

static void	test_split_child2(void)
{
	test_split_testone("ABC DE", '\0', 1, "ABC DE");
	test_split_testone("", ' ', 0);
	test_split_testone("", '\0', 0);
}

static void	test_split_child3(void)
{
	tlib_test_ok(ft_split(NULL, ' ') == NULL);
}

static void	test_split_child4(void)
{
	tlib_alloc_setmock(1);
	tlib_test_ok(ft_split("AB CD", ' ') == NULL);
}

static void	test_split_child5(void)
{
	tlib_alloc_setmock(2);
	tlib_test_ok(ft_split("AB CD", ' ') == NULL);
}

void	test_split(void)
{
	tlib_test_process(&test_split_child1, PRESULT_OK);
	tlib_test_process(&test_split_child2, PRESULT_OK);
	tlib_test_process(&test_split_child3, PRESULT_OK);
	tlib_test_process(&test_split_child4, PRESULT_OK);
	tlib_test_process(&test_split_child5, PRESULT_OK);
}
