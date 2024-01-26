/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:46:07 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 12:25:33 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	test_memcpy_child1(void)
{
	char	buf[5];

	tlib_alloc_reset();
	tlib_test_ok(ft_memcpy(buf, "ASDFG", 5) == buf);
	tlib_test_ok(!memcmp(buf, "ASDFG", 5));
	tlib_test_ok(ft_memcpy(buf, "JJ", 2) == buf);
	tlib_test_ok(!memcmp(buf, "JJDFG", 5));
	tlib_test_ok(ft_memcpy(buf, "JJ", 2) == buf);
	tlib_test_ok(!memcmp(buf, "JJDFG", 5));
	tlib_test_ok(tlib_alloc_count() == 0);
	return (0);
}

static int	test_memcpy_child2(void)
{
	char	buf[5];

	tlib_alloc_reset();
	memcpy(buf, "ASDFG", 5);
	tlib_test_ok(ft_memcpy(NULL, NULL, 3) == NULL);
	tlib_test_ok(ft_memcpy(NULL, "ASDFG", 0) == NULL);
	tlib_test_ok(ft_memcpy(buf, NULL, 0) == buf);
	tlib_test_ok(!memcmp(buf, "ASDFG", 5));
	tlib_test_ok(tlib_alloc_count() == 0);
	return (0);
}

static int	test_memcpy_child3(void)
{
	ft_memcpy(NULL, "ASDFG", 5);
	return (0);
}

static int	test_memcpy_child4(void)
{
	char	buf[5];

	ft_memcpy(buf, NULL, 5);
	return (0);
}

void	test_memcpy(void)
{
	tlib_test_ok(tlib_run_process(&test_memcpy_child1) == 0);
	tlib_test_ok(tlib_run_process(&test_memcpy_child2) == 0);
	tlib_test_ok(tlib_run_process(&test_memcpy_child3) != 0);
	tlib_test_ok(tlib_run_process(&test_memcpy_child4) != 0);
}
