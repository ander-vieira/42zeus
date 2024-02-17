/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 14:17:08 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/17 17:14:43 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

//TODO

static void	test_strlcpy_child1(void)
{
	char	buf[10];

	tlib_alloc_reset();
	tlib_test_ok(ft_strlcpy(buf, "ASDFG", 10) == 5);
	tlib_test_ok(!strcmp(buf, "ASDFG"));
	tlib_test_ok(ft_strlcpy(buf, "0123456789", 10) == 10);
	tlib_test_ok(!strcmp(buf, "012345678"));
	tlib_test_ok(ft_strlcpy(buf, "", 10) == 0);
	tlib_test_ok(!strcmp(buf, ""));
	tlib_test_ok(tlib_alloc_count() == 0);
}

void	test_strlcpy(void)
{
	tlib_test_process(&test_strlcpy_child1, PRESULT_OK);
}
