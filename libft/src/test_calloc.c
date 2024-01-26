/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:25:29 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 15:09:14 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_calloc_child1(void)
{
	void	*buf;

	tlib_alloc_reset();
	buf = ft_calloc(3, 2);
	tlib_test_ok(buf != NULL);
	tlib_test_ok(tlib_alloc_count() == 1);
	tlib_test_ok(tlib_alloc_lookup(buf) == 6);
	tlib_test_ok(!memcmp(buf, "\0\0\0\0\0\0", 6));
	free(buf);
}

static void	test_calloc_child2(void)
{
	tlib_alloc_reset();
	tlib_alloc_setmock(1);
	tlib_test_ok(ft_calloc(3, 2) == NULL);
}

void	test_calloc(void)
{
	tlib_test_process(&test_calloc_child1, STATUS_OK);
	tlib_test_process(&test_calloc_child2, STATUS_OK);
}
