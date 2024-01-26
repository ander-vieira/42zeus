/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:32:35 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 10:33:29 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	test_memchr_child1(void *ctx)
{
	char	buf[5];

	(void)ctx;
	tlib_alloc_reset();
	memcpy(buf, "ASD\0G", 5);
	tlib_print_test(ft_memchr(buf, 'A', 5) == buf);
	tlib_print_test(ft_memchr(buf, '\0', 5) == buf + 3);
	tlib_print_test(ft_memchr(buf, 'G', 5) == buf + 4);
	tlib_print_test(ft_memchr(buf, 'G', 3) == NULL);
	tlib_print_test(ft_memchr(buf, 'H', 5) == NULL);
	tlib_print_test(ft_memchr(buf, 'A', 0) == NULL);
	tlib_print_test(ft_memchr(buf, 'A' + 256, 5) == buf);
	tlib_print_test(ft_memchr(buf, 'H' + 256, 5) == NULL);
	tlib_print_test(tlib_alloc_count() == 0);
	return (0);
}

static int	test_memchr_child2(void *ctx)
{
	(void)ctx;
	tlib_alloc_reset();
	tlib_print_test(ft_memchr(NULL, 'A', 0) == NULL);
	tlib_print_test(tlib_alloc_count() == 0);
	return (0);
}

static int	test_memchr_child3(void *ctx)
{
	(void)ctx;
	ft_memchr(NULL, 'A', 5);
	return (0);
}

void	test_memchr(void)
{
	tlib_print_test(tlib_run_process(&test_memchr_child1, NULL) == 0);
	tlib_print_test(tlib_run_process(&test_memchr_child2, NULL) == 0);
	tlib_print_test(tlib_run_process(&test_memchr_child3, NULL) != 0);
}
