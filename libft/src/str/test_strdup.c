/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strdup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:12:10 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 15:11:35 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_strdup_child1(void)
{
	char	*str;

	tlib_alloc_reset();
	str = ft_strdup("ASDFG");
	tlib_test_ok(!strcmp(str, "ASDFG"));
	tlib_test_ok(tlib_alloc_count() == 1);
	tlib_test_ok(tlib_alloc_lookup(str) == 6);
	free(str);
	str = ft_strdup("");
	tlib_test_ok(!strcmp(str, ""));
	tlib_test_ok(tlib_alloc_count() == 1);
	tlib_test_ok(tlib_alloc_lookup(str) == 1);
	free(str);
}

static void	test_strdup_child2(void)
{
	ft_strdup(NULL);
}

void	test_strdup(void)
{
	tlib_test_process(&test_strdup_child1, STATUS_OK);
	tlib_test_process(&test_strdup_child2, STATUS_SEGFAULT);
}