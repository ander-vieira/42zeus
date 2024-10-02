/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:32:35 by andeviei          #+#    #+#             */
/*   Updated: 2024/10/02 23:46:19 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_memchr_child1(void)
{
	char	buf[5];

	tlib_mockmalloc_reset();
	memcpy(buf, "ASD\0G", 5);
	tlib_testresult_bool(ft_memchr(buf, 'A', 5) == buf);
	tlib_testresult_bool(ft_memchr(buf, '\0', 5) == buf + 3);
	tlib_testresult_bool(ft_memchr(buf, 'G', 5) == buf + 4);
	tlib_testresult_bool(ft_memchr(buf, 'G', 3) == NULL);
	tlib_testresult_bool(ft_memchr(buf, 'H', 5) == NULL);
	tlib_testresult_bool(ft_memchr(buf, 'A', 0) == NULL);
	tlib_testresult_bool(ft_memchr(buf, 'A' + 256, 5) == buf);
	tlib_testresult_bool(ft_memchr(buf, 'H' + 256, 5) == NULL);
	tlib_testmalloc_count(0);
}

static void	test_memchr_child2(void)
{
	tlib_mockmalloc_reset();
	tlib_testresult_bool(ft_memchr(NULL, 'A', 0) == NULL);
	tlib_testmalloc_count(0);
}

static void	test_memchr_child3(void)
{
	ft_memchr(NULL, 'A', 5);
}

void	test_memchr(void)
{
	tlib_test_process(&test_memchr_child1, PRESULT_OK);
	tlib_test_process(&test_memchr_child2, PRESULT_OK);
	tlib_test_process(&test_memchr_child3, PRESULT_SEGFAULT);
}
