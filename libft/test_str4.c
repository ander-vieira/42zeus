/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:18:42 by andeviei          #+#    #+#             */
/*   Updated: 2023/12/18 17:25:31 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

char	mapchar(unsigned int index, char c)
{
	return (c + index);
}

void	iterchar(unsigned int index, char *c)
{
	*c += index - 1;
}

static void	test_strmapi(void)
{
	char	*str;

	print_title("strmapi");
	str = ft_strmapi("HOLAMUNDO", &mapchar);
	print_test("1", !strcmp(str, "HPNDQZTKW"), TRUE);
	free(str);
}

static void	test_striteri(void)
{
	char	*str;

	print_title("striteri");
	str = ft_strdup("HOLAMUNDO");
	ft_striteri(str, &iterchar);
	print_test("1", !strcmp(str, "GOMCPYSJV"), TRUE);
	free(str);
}

void	test_str4(void)
{
	test_strmapi();
	test_striteri();
}
