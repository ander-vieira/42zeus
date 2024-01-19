/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:18:42 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/19 13:26:20 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
		__attribute__((weak));
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
		__attribute__((weak));

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
}

static void	test_striteri(void)
{
	char	*str;

	str = ft_strdup("HOLAMUNDO");
	ft_striteri(str, &iterchar);
	tlib_print_test("1", !strcmp(str, "GOMCPYSJV"), TRUE);
	free(str);
}

void	test_str4(void)
{
	tlib_print_missing(&test_strmapi, &ft_strmapi, "strmapi");
	tlib_print_missing(&test_striteri, &ft_striteri, "striteri");
}
