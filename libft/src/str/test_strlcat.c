/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:22:09 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/19 20:23:58 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_strlcat_testone(char *str1, char *str2, char *expected)
{
	char	buf[5];

	tlib_alloc_reset();
	strcpy(buf, str1);
	tlib_test_ok(ft_strlcat(buf, str2, 5) == strlen(str1) + strlen(str2));
	tlib_test_ok(!strcmp(buf, expected));
	tlib_test_ok(tlib_alloc_count() == 0);
}

static void	test_strlcat_child1(void)
{
	test_strlcat_testone("AB", "CD", "ABCD");
	test_strlcat_testone("", "ABC", "ABC");
	test_strlcat_testone("AB", "CDE", "ABCD");
	test_strlcat_testone("", "ABCDE", "ABCD");
}

static void	test_strlcat_child2(void)
{
	char	buf[5];

	tlib_alloc_reset();
	strcpy(buf, "AB");
	tlib_test_ok(ft_strlcat(buf, "C", 1) == 2);
	tlib_test_ok(!strcmp(buf, "AB"));
	strcpy(buf, "AB");
	tlib_test_ok(ft_strlcat(buf, "C", 0) == 1);
	tlib_test_ok(!strcmp(buf, "AB"));
	tlib_test_ok(tlib_alloc_count() == 0);
}

static void	test_strlcat_child3(void)
{
	ft_strlcat(NULL, "HOLA", 5);
}

static void	test_strlcat_child4(void)
{
	ft_strlcat("HOLA", NULL, 5);
}

void	test_strlcat(void)
{
	tlib_test_process(&test_strlcat_child1, PRESULT_OK);
	tlib_test_process(&test_strlcat_child2, PRESULT_OK);
	tlib_test_process(&test_strlcat_child3, PRESULT_SEGFAULT);
	tlib_test_process(&test_strlcat_child4, PRESULT_SEGFAULT);
}
