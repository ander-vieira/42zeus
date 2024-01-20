/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:25:29 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/20 18:39:20 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_calloc1(void)
{
	char	*buf;

	buf = ft_calloc(3, 2);
	tlib_print_test("1", buf != NULL, FALSE);
	tlib_print_test("2", tlib_alloc_count() == 1, FALSE);
	tlib_print_test("3", tlib_alloc_lookup(buf) == 6, FALSE);
	tlib_print_test("4", !memcmp(buf, "\0\0\0\0\0\0", 6), FALSE);
	tlib_print_test("5", tlib_alloc_errors() == 0x00, FALSE);
	if (tlib_alloc_lookup(buf) != 0)
		free(buf);
	buf = ft_calloc(0, 2);
	tlib_print_test("6", buf == NULL, FALSE);
	tlib_print_test("7", tlib_alloc_count() == 0, FALSE);
	tlib_print_test("8", tlib_alloc_errors() == ERRMALLOC_ZERO, TRUE);
	tlib_alloc_reset();
}

void	test_calloc(void)
{
	tlib_print_missing(&test_calloc1, &ft_calloc, "calloc");
}