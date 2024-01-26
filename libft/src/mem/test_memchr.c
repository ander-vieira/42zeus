/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:32:35 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 12:25:33 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	test_memchr_child1(void)
{
	char	buf[5];

	tlib_alloc_reset();
	memcpy(buf, "ASD\0G", 5);
	tlib_test_ok(ft_memchr(buf, 'A', 5) == buf);
	tlib_test_ok(ft_memchr(buf, '\0', 5) == buf + 3);
	tlib_test_ok(ft_memchr(buf, 'G', 5) == buf + 4);
	tlib_test_ok(ft_memchr(buf, 'G', 3) == NULL);
	tlib_test_ok(ft_memchr(buf, 'H', 5) == NULL);
	tlib_test_ok(ft_memchr(buf, 'A', 0) == NULL);
	tlib_test_ok(ft_memchr(buf, 'A' + 256, 5) == buf);
	tlib_test_ok(ft_memchr(buf, 'H' + 256, 5) == NULL);
	tlib_test_ok(tlib_alloc_count() == 0);
	return (0);
}

static int	test_memchr_child2(void)
{
	tlib_alloc_reset();
	tlib_test_ok(ft_memchr(NULL, 'A', 0) == NULL);
	tlib_test_ok(tlib_alloc_count() == 0);
	return (0);
}

static int	test_memchr_child3(void)
{
	ft_memchr(NULL, 'A', 5);
	return (0);
}

void	test_memchr(void)
{
	tlib_test_ok(tlib_run_process(&test_memchr_child1) == 0);
	tlib_test_ok(tlib_run_process(&test_memchr_child2) == 0);
	tlib_test_ok(tlib_run_process(&test_memchr_child3) != 0);
}
