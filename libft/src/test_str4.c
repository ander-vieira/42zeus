/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:18:42 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 09:39:49 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static char	mapchar(unsigned int index, char c)
{
	return (c + index);
}

static void	iterchar(unsigned int index, char *c)
{
	*c += index - 1;
}

void	test_strmapi(void)
{
	char	*str;

	str = ft_strmapi("HOLAMUNDO", &mapchar);
	tlib_print_test(str != NULL && !strcmp(str, "HPNDQZTKW"));
	tlib_print_test(tlib_alloc_lookup(str) == 10);
	tlib_print_test(tlib_alloc_count() == 1);
	free(str);
	str = ft_strmapi("HHH", &mapchar);
	tlib_print_test(str != NULL && !strcmp(str, "HIJ"));
	tlib_print_test(tlib_alloc_lookup(str) == 4);
	tlib_print_test(tlib_alloc_count() == 1);
	free(str);
	str = ft_strmapi("", &mapchar);
	tlib_print_test(str != NULL && !strcmp(str, ""));
	tlib_print_test(tlib_alloc_lookup(str) == 1);
	tlib_print_test(tlib_alloc_count() == 1);
	free(str);
	tlib_print_test(tlib_alloc_errors() == 0x00);
	tlib_alloc_reset();
}

void	test_striteri(void)
{
	char	*str;

	str = strdup("HOLAMUNDO");
	ft_striteri(str, &iterchar);
	tlib_print_test(!strcmp(str, "GOMCPYSJV"));
	ft_striteri(str, &iterchar);
	tlib_print_test(!strcmp(str, "FONES]XP]"));
	free(str);
	tlib_print_test(tlib_alloc_count() == 0);
	tlib_alloc_reset();
}
