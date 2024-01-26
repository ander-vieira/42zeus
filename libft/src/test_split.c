/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:42:13 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 09:39:49 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_split(void)
{
	char	**split;

	split = ft_split(" HOLA MUNDO SOY  ANDER  ", ' ');
	tlib_print_test(split != NULL);
	tlib_print_test(tlib_alloc_lookup(split) == sizeof(char *) * 5);
	tlib_print_test(split[0] != NULL && !strcmp(split[0], "HOLA"));
	tlib_print_test(tlib_alloc_lookup(split[0]) == 5);
	tlib_print_test(split[1] != NULL && !strcmp(split[1], "MUNDO"));
	tlib_print_test(tlib_alloc_lookup(split[1]) == 6);
	tlib_print_test(split[2] != NULL && !strcmp(split[2], "SOY"));
	tlib_print_test(tlib_alloc_lookup(split[2]) == 4);
	tlib_print_test(split[3] != NULL && !strcmp(split[3], "ANDER"));
	tlib_print_test(tlib_alloc_lookup(split[3]) == 6);
	tlib_print_test(split[4] == NULL);
	tlib_print_test(tlib_alloc_count() == 5);
	taux_split_free(split);
	tlib_print_test(tlib_alloc_count() == 0);
	tlib_print_test(tlib_alloc_errors() == 0x00);
	tlib_alloc_reset();
}
