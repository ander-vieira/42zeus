/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_striteri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:18:42 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/17 17:14:51 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

//TODO

static void	iterchar(unsigned int index, char *c)
{
	*c += index - 1;
}

void	test_striteri(void)
{
	char	*str;

	str = strdup("HOLAMUNDO");
	ft_striteri(str, &iterchar);
	tlib_test_ok(!strcmp(str, "GOMCPYSJV"));
	ft_striteri(str, &iterchar);
	tlib_test_ok(!strcmp(str, "FONES]XP]"));
	free(str);
	tlib_test_ok(tlib_alloc_count() == 0);
	tlib_alloc_reset();
}
