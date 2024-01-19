/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:42:13 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/19 13:26:20 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

char	**ft_split(char const *str, char c) __attribute__((weak));

static void	test_split1(void)
{
	char	**split;
	size_t	i;

	split = ft_split(" HOLA MUNDO SOY  ANDER  ", ' ');
	tlib_print_test("1", split != NULL, FALSE);
	tlib_print_test("2", split[0] != NULL && !strcmp(split[0], "HOLA"), FALSE);
	tlib_print_test("3", split[1] != NULL && !strcmp(split[1], "MUNDO"), FALSE);
	tlib_print_test("4", split[2] != NULL && !strcmp(split[2], "SOY"), FALSE);
	tlib_print_test("5", split[3] != NULL && !strcmp(split[3], "ANDER"), FALSE);
	tlib_print_test("6", split[4] == NULL, TRUE);
	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	test_split(void)
{
	tlib_print_missing(&test_split1, &ft_split, "split");
}
