/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strrchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:47:39 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 15:11:21 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_strrchr_child1(void)
{
	char	*str;

	tlib_alloc_reset();
	str = "ASDFA";
	tlib_test_ok(ft_strrchr(str, 'A') == str + 4);
	tlib_test_ok(ft_strrchr(str, 'D') == str + 2);
	tlib_test_ok(ft_strrchr(str, '\0') == str + 5);
	tlib_test_ok(ft_strrchr(str, 'H') == NULL);
	tlib_test_ok(ft_strrchr(str, 'A' + 256) == str + 4);
	tlib_test_ok(ft_strrchr(str, 'H' + 256) == NULL);
	tlib_test_ok(tlib_alloc_count() == 0);
}

static void	test_strrchr_child2(void)
{
	ft_strrchr(NULL, 'A');
}

void	test_strrchr(void)
{
	tlib_test_process(&test_strrchr_child1, STATUS_OK);
	tlib_test_process(&test_strrchr_child2, STATUS_SEGFAULT);
}
