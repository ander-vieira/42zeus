/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:18:42 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/20 18:42:13 by andeviei         ###   ########.fr       */
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

static void	test_strmapi(void)
{
	char	*str;

	str = ft_strmapi("HOLAMUNDO", &mapchar);
	tlib_print_test("1", !strcmp(str, "HPNDQZTKW"), TRUE);
	free(str);
	tlib_alloc_reset();
}

static void	test_striteri(void)
{
	char	*str;

	str = ft_strdup("HOLAMUNDO");
	ft_striteri(str, &iterchar);
	tlib_print_test("1", !strcmp(str, "GOMCPYSJV"), TRUE);
	free(str);
	tlib_alloc_reset();
}

void	test_str4(void)
{
	tlib_print_missing(&test_strmapi, &ft_strmapi, "strmapi");
	tlib_print_missing(&test_striteri, &ft_striteri, "striteri");
}
