/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strrchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:47:39 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 13:54:32 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	test_strrchr_child1(void)
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
	return (0);
}

static int	test_strrchr_child2(void)
{
	ft_strrchr(NULL, 'A');
	return (0);
}

void	test_strrchr(void)
{
	tlib_test_ok(tlib_run_process(&test_strrchr_child1) == 0);
	tlib_test_ok(tlib_run_process(&test_strrchr_child2) != 0);
}
