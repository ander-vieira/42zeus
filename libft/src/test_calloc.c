/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:25:29 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 09:39:14 by andeviei         ###   ########.fr       */
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

void	test_calloc(void)
{
	void	*buf;

	buf = ft_calloc(3, 2);
	tlib_print_test(buf != NULL);
	tlib_print_test(tlib_alloc_count() == 1);
	tlib_print_test(tlib_alloc_lookup(buf) == 6);
	tlib_print_test(!memcmp(buf, "\0\0\0\0\0\0", 6));
	tlib_print_test(tlib_alloc_errors() == 0x00);
	if (tlib_alloc_lookup(buf) != 0)
		free(buf);
	tlib_print_test(tlib_run_process(&test_calloc_crash1, NULL) == 0);
}
