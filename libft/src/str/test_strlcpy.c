/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:17:08 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/19 20:21:13 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_strlcpy_child1(void)
{
	char	buf[5];

	tlib_alloc_reset();
	tlib_test_ok(ft_strlcpy(buf, "", 5) == 0);
	tlib_test_ok(!strcmp(buf, ""));
	tlib_test_ok(ft_strlcpy(buf, "ABC", 5) == 3);
	tlib_test_ok(!strcmp(buf, "ABC"));
	tlib_test_ok(ft_strlcpy(buf, "ABCD", 5) == 4);
	tlib_test_ok(!strcmp(buf, "ABCD"));
	tlib_test_ok(ft_strlcpy(buf, "ABCDE", 5) == 5);
	tlib_test_ok(!strcmp(buf, "ABCD"));
	tlib_test_ok(ft_strlcpy(buf, "ABCDEFGH", 5) == 8);
	tlib_test_ok(!strcmp(buf, "ABCD"));
	tlib_test_ok(ft_strlcpy(buf, "", 0) == 0);
	tlib_test_ok(buf[0] != '\0');
	tlib_test_ok(tlib_alloc_count() == 0);
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
