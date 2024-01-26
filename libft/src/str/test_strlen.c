/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:22:08 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 13:30:21 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	test_strlen_child1(void)
{
	tlib_alloc_reset();
	tlib_test_ok(ft_strlen("ASDFG") == 5);
	tlib_test_ok(ft_strlen("AAA BBB CCC") == 11);
	tlib_test_ok(ft_strlen("") == 0);
	tlib_test_ok(tlib_alloc_count() == 0);
	return (0);
}

static int	test_strlen_child2(void)
{
	ft_strlen(NULL);
	return (0);
}

void	test_strlen(void)
{
	tlib_test_ok(tlib_run_process(&test_strlen_child1) == 0);
	tlib_test_ok(tlib_run_process(&test_strlen_child2) != 0);
}