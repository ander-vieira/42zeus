/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:25:29 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/22 15:42:37 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	test_calloc_crash1(void *ctx)
{
	void	*buf;
	int		status;

	(void)ctx;
	tlib_alloc_setmock(1);
	buf = ft_calloc(3, 2);
	if (buf == NULL)
		status = 0;
	else
		status = 1;
	free(buf);
	return (status);
}

static void	test_calloc1(void)
{
	void	*buf;

	buf = ft_calloc(3, 2);
	tlib_print_test("1", buf != NULL, FALSE);
	tlib_print_test("2", tlib_alloc_count() == 1, FALSE);
	tlib_print_test("3", tlib_alloc_lookup(buf) == 6, FALSE);
	tlib_print_test("4", !memcmp(buf, "\0\0\0\0\0\0", 6), FALSE);
	tlib_print_test("5", tlib_alloc_errors() == 0x00, FALSE);
	if (tlib_alloc_lookup(buf) != 0)
		free(buf);
	tlib_print_test("6",
		tlib_run_process(&test_calloc_crash1, NULL) == 0, TRUE);
}

void	test_calloc(void)
{
	tlib_print_missing(&test_calloc1, &ft_calloc, "calloc");
}
