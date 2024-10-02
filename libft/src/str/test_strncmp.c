/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strncmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:09:04 by andeviei          #+#    #+#             */
/*   Updated: 2024/10/02 23:46:19 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_strncmp_child1(void)
{
	tlib_mockmalloc_reset();
	tlib_testresult_bool(!ft_strncmp("ASDFG", "ASDFG", 5));
	tlib_testresult_bool(!ft_strncmp("ASDFG", "ASDFG", 10));
	tlib_testresult_bool(!ft_strncmp("ASDFG", "ASDFG", 3));
	tlib_testresult_bool(ft_strncmp("ASDFG", "ASDFH", 5));
	tlib_testresult_bool(ft_strncmp("ASDFG", "ASDFH", 10));
	tlib_testresult_bool(!ft_strncmp("ASDFG", "ASDFH", 3));
	tlib_testresult_bool(ft_strncmp("ASDFG", "SSDFG", 5));
	tlib_testresult_bool(ft_strncmp("ASDFG", "ASD", 5));
	tlib_testresult_bool(!ft_strncmp("ASDFG", "ASD", 3));
	tlib_testresult_bool(ft_strncmp("ASD", "ASDFG", 5));
	tlib_testresult_bool(!ft_strncmp("ASD", "ASDFG", 3));
	tlib_testresult_bool(ft_strncmp("", "ASDFG", 5));
	tlib_testresult_bool(!ft_strncmp("ASDFG", "SSDFG", 0));
	tlib_testresult_bool(!ft_strncmp("ASDFG", "", 0));
	tlib_testresult_bool(!ft_strncmp("", "ASDFG", 0));
	tlib_testmalloc_count(0);
}

static void	test_strncmp_child2(void)
{
	tlib_mockmalloc_reset();
	tlib_testresult_bool(!ft_strncmp(NULL, "ASDFG", 0));
	tlib_testresult_bool(!ft_strncmp("ASDFG", NULL, 0));
	tlib_testresult_bool(!ft_strncmp(NULL, NULL, 0));
	tlib_testmalloc_count(0);
}

static void	test_strncmp_child3(void)
{
	ft_strncmp("ASDFG", NULL, 5);
}

static void	test_strncmp_child4(void)
{
	ft_strncmp(NULL, "ASDFG", 5);
}

void	test_strncmp(void)
{
	tlib_test_process(&test_strncmp_child1, PRESULT_OK);
	tlib_test_process(&test_strncmp_child2, PRESULT_OK);
	tlib_test_process(&test_strncmp_child3, PRESULT_SEGFAULT);
	tlib_test_process(&test_strncmp_child4, PRESULT_SEGFAULT);
}
