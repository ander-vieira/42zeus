/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:08:04 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 11:47:41 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	test_memmove_child1(void)
{
	char	buf[5];

	tlib_alloc_reset();
	tlib_print_test(ft_memmove(buf, "ASDFG", 5) == buf);
	tlib_print_test(!memcmp(buf, "ASDFG", 5));
	tlib_print_test(ft_memmove(buf, buf + 3, 2) == buf);
	tlib_print_test(!memcmp(buf, "FGDFG", 5));
	tlib_print_test(ft_memmove(buf + 2, buf, 3) == buf + 2);
	tlib_print_test(!memcmp(buf, "FGFGD", 5));
	tlib_print_test(tlib_alloc_count() == 0);
	return (0);
}

static int	test_memmove_child2(void)
{
	char	buf[5];

	tlib_alloc_reset();
	memcpy(buf, "ASDFG", 5);
	tlib_print_test(ft_memmove(NULL, "ASDFG", 0) == NULL);
	tlib_print_test(ft_memmove(buf, NULL, 0) == buf);
	tlib_print_test(!memcmp(buf, "ASDFG", 5));
	tlib_print_test(ft_memmove(NULL, NULL, 0) == NULL);
	tlib_print_test(ft_memmove(NULL, NULL, 3) == NULL);
	tlib_print_test(tlib_alloc_count() == 0);
	return (0);
}

static int	test_memmove_child3(void)
{
	ft_memmove(NULL, "ASDFG", 5);
	return (0);
}

static int	test_memmove_child4(void)
{
	char	buf[5];

	ft_memmove(buf, NULL, 5);
	return (0);
}

void	test_memmove(void)
{
	tlib_print_test(tlib_run_process(&test_memmove_child1) == 0);
	tlib_print_test(tlib_run_process(&test_memmove_child2) == 0);
	tlib_print_test(tlib_run_process(&test_memmove_child3) != 0);
	tlib_print_test(tlib_run_process(&test_memmove_child4) != 0);
}
