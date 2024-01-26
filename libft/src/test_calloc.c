/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:25:29 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 11:23:31 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	test_calloc_child1(void *ctx)
{
	void	*buf;

	(void)ctx;
	tlib_alloc_reset();
	buf = ft_calloc(3, 2);
	tlib_print_test(buf != NULL);
	tlib_print_test(tlib_alloc_count() == 1);
	tlib_print_test(tlib_alloc_lookup(buf) == 6);
	tlib_print_test(!memcmp(buf, "\0\0\0\0\0\0", 6));
	tlib_print_test(tlib_alloc_errors() == 0x00);
	free(buf);
	return (0);
}

static int	test_calloc_child2(void *ctx)
{
	(void)ctx;
	tlib_alloc_reset();
	tlib_alloc_setmock(1);
	tlib_print_test(ft_calloc(3, 2) == NULL);
	return (0);
}

void	test_calloc(void)
{
	tlib_print_test(tlib_run_process(&test_calloc_child1, NULL) == 0);
	tlib_print_test(tlib_run_process(&test_calloc_child2, NULL) == 0);
}
