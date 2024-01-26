/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:25:29 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 12:25:33 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	test_calloc_child1(void)
{
	void	*buf;

	tlib_alloc_reset();
	buf = ft_calloc(3, 2);
	tlib_test_ok(buf != NULL);
	tlib_test_ok(tlib_alloc_count() == 1);
	tlib_test_ok(tlib_alloc_lookup(buf) == 6);
	tlib_test_ok(!memcmp(buf, "\0\0\0\0\0\0", 6));
	tlib_test_ok(tlib_alloc_errors() == 0x00);
	free(buf);
	return (0);
}

static int	test_calloc_child2(void)
{
	tlib_alloc_reset();
	tlib_alloc_setmock(1);
	tlib_test_ok(ft_calloc(3, 2) == NULL);
	return (0);
}

void	test_calloc(void)
{
	tlib_test_ok(tlib_run_process(&test_calloc_child1) == 0);
	tlib_test_ok(tlib_run_process(&test_calloc_child2) == 0);
}
