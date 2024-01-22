/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:18:42 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/22 20:20:48 by andeviei         ###   ########.fr       */
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
	tlib_print_test("1", str != NULL && !strcmp(str, "HPNDQZTKW"), FALSE);
	tlib_print_test("2", tlib_alloc_lookup(str) == 10, FALSE);
	tlib_print_test("3", tlib_alloc_count() == 1, FALSE);
	free(str);
	str = ft_strmapi("HHH", &mapchar);
	tlib_print_test("4", str != NULL && !strcmp(str, "HIJ"), FALSE);
	tlib_print_test("5", tlib_alloc_lookup(str) == 4, FALSE);
	tlib_print_test("6", tlib_alloc_count() == 1, FALSE);
	free(str);
	str = ft_strmapi("", &mapchar);
	tlib_print_test("7", str != NULL && !strcmp(str, ""), FALSE);
	tlib_print_test("8", tlib_alloc_lookup(str) == 1, FALSE);
	tlib_print_test("9", tlib_alloc_count() == 1, FALSE);
	free(str);
	tlib_print_test("10", tlib_alloc_errors() == 0x00, TRUE);
	tlib_alloc_reset();
}

void	test_striteri(void)
{
	char	*str;

	str = strdup("HOLAMUNDO");
	ft_striteri(str, &iterchar);
	tlib_print_test("1", !strcmp(str, "GOMCPYSJV"), FALSE);
	ft_striteri(str, &iterchar);
	tlib_print_test("2", !strcmp(str, "FONES]XP]"), FALSE);
	free(str);
	tlib_print_test("3", tlib_alloc_count() == 0, TRUE);
	tlib_alloc_reset();
}
