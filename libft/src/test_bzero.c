/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:23:25 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 10:38:30 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	test_bzero_child1(void *ctx)
{
	char	buf[5];

	(void)ctx;
	tlib_alloc_reset();
	ft_bzero(buf, 5);
	tlib_print_test(!memcmp(buf, "\0\0\0\0\0", 5));
	tlib_print_test(tlib_alloc_count() == 0);
	return (0);
}

static int	test_bzero_child2(void *ctx)
{
	char	buf[5];

	(void)ctx;
	tlib_alloc_reset();
	strcpy(buf, "ASDF");
	ft_bzero(buf, 0);
	tlib_print_test(!memcmp(buf, "ASDF", 5));
	tlib_print_test(tlib_alloc_count() == 0);
	return (0);
}

static int	test_bzero_child3(void *ctx)
{
	(void)ctx;
	ft_bzero(NULL, 0);
	return (0);
}

static int	test_bzero_child4(void *ctx)
{
	(void)ctx;
	ft_bzero(NULL, 5);
	return (0);
}

void	test_bzero(void)
{
	tlib_print_test(tlib_run_process(&test_bzero_child1, NULL) == 0);
	tlib_print_test(tlib_run_process(&test_bzero_child2, NULL) == 0);
	tlib_print_test(tlib_run_process(&test_bzero_child3, NULL) == 0);
	tlib_print_test(tlib_run_process(&test_bzero_child4, NULL) != 0);
}
