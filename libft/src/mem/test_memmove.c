/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:08:04 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 15:10:44 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_memmove_child1(void)
{
	char	buf[5];

	tlib_alloc_reset();
	tlib_test_ok(ft_memmove(buf, "ASDFG", 5) == buf);
	tlib_test_ok(!memcmp(buf, "ASDFG", 5));
	tlib_test_ok(ft_memmove(buf, buf + 3, 2) == buf);
	tlib_test_ok(!memcmp(buf, "FGDFG", 5));
	tlib_test_ok(ft_memmove(buf + 2, buf, 3) == buf + 2);
	tlib_test_ok(!memcmp(buf, "FGFGD", 5));
	tlib_test_ok(tlib_alloc_count() == 0);
}

static void	test_memmove_child2(void)
{
	char	buf[5];

	tlib_alloc_reset();
	memcpy(buf, "ASDFG", 5);
	tlib_test_ok(ft_memmove(NULL, "ASDFG", 0) == NULL);
	tlib_test_ok(ft_memmove(buf, NULL, 0) == buf);
	tlib_test_ok(!memcmp(buf, "ASDFG", 5));
	tlib_test_ok(ft_memmove(NULL, NULL, 0) == NULL);
	tlib_test_ok(ft_memmove(NULL, NULL, 3) == NULL);
	tlib_test_ok(tlib_alloc_count() == 0);
}

static void	test_memmove_child3(void)
{
	ft_memmove(NULL, "ASDFG", 5);
}

static void	test_memmove_child4(void)
{
	char	buf[5];

	ft_memmove(buf, NULL, 5);
}

void	test_memmove(void)
{
	tlib_test_process(&test_memmove_child1, STATUS_OK);
	tlib_test_process(&test_memmove_child2, STATUS_OK);
	tlib_test_process(&test_memmove_child3, STATUS_SEGFAULT);
	tlib_test_process(&test_memmove_child4, STATUS_SEGFAULT);
}
