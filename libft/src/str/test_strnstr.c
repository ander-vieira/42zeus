/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:22:09 by andeviei          #+#    #+#             */
/*   Updated: 2024/10/02 23:46:19 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

//TODO

static void	test_strnstr_child1(void)
{
	char	*str;

	tlib_mockmalloc_reset();
	str = "ABCDE";
	tlib_testresult_bool(ft_strnstr(str, "", 5) == str);
	tlib_testresult_bool(ft_strnstr(str, "A", 5) == str);
	tlib_testresult_bool(ft_strnstr(str, "ABC", 5) == str);
	tlib_testresult_bool(ft_strnstr(str, "ABCDE", 5) == str);
	tlib_testresult_bool(ft_strnstr(str, "C", 5) == str + 2);
	tlib_testresult_bool(ft_strnstr(str, "BCD", 5) == str + 1);
	tlib_testresult_bool(ft_strnstr(str, "F", 5) == NULL);
	tlib_testresult_bool(ft_strnstr(str, "CB", 5) == NULL);
	tlib_testresult_bool(ft_strnstr(str, "C", 2) == NULL);
	tlib_testresult_bool(ft_strnstr(str, "ABC", 2) == NULL);
	tlib_testresult_bool(ft_strnstr(str, "", 0) == str);
	tlib_testresult_bool(ft_strnstr(str, "ABC", 0) == NULL);
	tlib_testmalloc_count(0);
}

static void	test_strnstr_child2(void)
{
	char	*str;

	tlib_mockmalloc_reset();
	str = "ABCDE";
	tlib_testresult_bool(ft_strnstr(str, "", 10) == str);
	tlib_testresult_bool(ft_strnstr(str, "BCD", 10) == str + 1);
	tlib_testmalloc_count(0);
}

void	test_strnstr(void)
{
	tlib_test_process(&test_strnstr_child1, PRESULT_OK);
	tlib_test_process(&test_strnstr_child2, PRESULT_OK);
}
