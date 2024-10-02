/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:17:08 by andeviei          #+#    #+#             */
/*   Updated: 2024/10/02 23:46:19 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_strlcpy_child1(void)
{
	char	buf[5];

	tlib_mockmalloc_reset();
	tlib_testresult_bool(ft_strlcpy(buf, "", 5) == 0);
	tlib_testresult_bool(!strcmp(buf, ""));
	tlib_testresult_bool(ft_strlcpy(buf, "ABC", 5) == 3);
	tlib_testresult_bool(!strcmp(buf, "ABC"));
	tlib_testresult_bool(ft_strlcpy(buf, "ABCD", 5) == 4);
	tlib_testresult_bool(!strcmp(buf, "ABCD"));
	tlib_testresult_bool(ft_strlcpy(buf, "ABCDE", 5) == 5);
	tlib_testresult_bool(!strcmp(buf, "ABCD"));
	tlib_testresult_bool(ft_strlcpy(buf, "ABCDEFGH", 5) == 8);
	tlib_testresult_bool(!strcmp(buf, "ABCD"));
	tlib_testresult_bool(ft_strlcpy(buf, "", 0) == 0);
	tlib_testresult_bool(buf[0] != '\0');
	tlib_testmalloc_count(0);
}

static void	test_strlcpy_child2(void)
{
	ft_strlcpy(NULL, "ABC", 5);
}

static void	test_strlcpy_child3(void)
{
	ft_strlcpy("ABC", NULL, 5);
}

static void	test_strlcpy_child4(void)
{
	ft_strlcpy(NULL, NULL, 5);
}

void	test_strlcpy(void)
{
	tlib_test_process(&test_strlcpy_child1, PRESULT_OK);
	tlib_test_process(&test_strlcpy_child2, PRESULT_SEGFAULT);
	tlib_test_process(&test_strlcpy_child3, PRESULT_SEGFAULT);
	tlib_test_process(&test_strlcpy_child4, PRESULT_SEGFAULT);
}
