/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strmapi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:18:42 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/17 17:14:46 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

//TODO

static char	mapchar(unsigned int index, char c)
{
	return (c + index);
}

void	test_strmapi(void)
{
	char	*str;

	str = ft_strmapi("HOLAMUNDO", &mapchar);
	tlib_test_ok(str != NULL && !strcmp(str, "HPNDQZTKW"));
	tlib_test_ok(tlib_alloc_lookup(str) == 10);
	tlib_test_ok(tlib_alloc_count() == 1);
	free(str);
	str = ft_strmapi("HHH", &mapchar);
	tlib_test_ok(str != NULL && !strcmp(str, "HIJ"));
	tlib_test_ok(tlib_alloc_lookup(str) == 4);
	tlib_test_ok(tlib_alloc_count() == 1);
	free(str);
	str = ft_strmapi("", &mapchar);
	tlib_test_ok(str != NULL && !strcmp(str, ""));
	tlib_test_ok(tlib_alloc_lookup(str) == 1);
	tlib_test_ok(tlib_alloc_count() == 1);
	free(str);
	tlib_alloc_reset();
}
