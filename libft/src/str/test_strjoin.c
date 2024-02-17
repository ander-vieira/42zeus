/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:38:54 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/17 17:16:15 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

//TODO

void	test_strjoin(void)
{
	char	*str;

	str = ft_strjoin("HOLA", "MUNDO");
	tlib_test_ok(str != NULL && !strcmp(str, "HOLAMUNDO"));
	tlib_test_ok(tlib_alloc_lookup(str) == 10);
	tlib_test_ok(tlib_alloc_count() == 1);
	free(str);
	str = ft_strjoin("", "MUNDO");
	tlib_test_ok(str != NULL && !strcmp(str, "MUNDO"));
	tlib_test_ok(tlib_alloc_lookup(str) == 6);
	tlib_test_ok(tlib_alloc_count() == 1);
	free(str);
	str = ft_strjoin(" PEPITO ", "");
	tlib_test_ok(str != NULL && !strcmp(str, " PEPITO "));
	tlib_test_ok(tlib_alloc_lookup(str) == 9);
	tlib_test_ok(tlib_alloc_count() == 1);
	free(str);
	str = ft_strjoin("", "");
	tlib_test_ok(str != NULL && !strcmp(str, ""));
	tlib_test_ok(tlib_alloc_lookup(str) == 1);
	tlib_test_ok(tlib_alloc_count() == 1);
	free(str);
	tlib_alloc_reset();
}
