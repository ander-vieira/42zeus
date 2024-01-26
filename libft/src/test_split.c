/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:42:13 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 14:37:49 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_split(void)
{
	char	**split;

	split = ft_split(" HOLA MUNDO SOY  ANDER  ", ' ');
	tlib_test_ok(split != NULL);
	tlib_test_ok(tlib_alloc_lookup(split) == sizeof(char *) * 5);
	tlib_test_ok(split[0] != NULL && !strcmp(split[0], "HOLA"));
	tlib_test_ok(tlib_alloc_lookup(split[0]) == 5);
	tlib_test_ok(split[1] != NULL && !strcmp(split[1], "MUNDO"));
	tlib_test_ok(tlib_alloc_lookup(split[1]) == 6);
	tlib_test_ok(split[2] != NULL && !strcmp(split[2], "SOY"));
	tlib_test_ok(tlib_alloc_lookup(split[2]) == 4);
	tlib_test_ok(split[3] != NULL && !strcmp(split[3], "ANDER"));
	tlib_test_ok(tlib_alloc_lookup(split[3]) == 6);
	tlib_test_ok(split[4] == NULL);
	tlib_test_ok(tlib_alloc_count() == 5);
	taux_split_free(split);
	tlib_test_ok(tlib_alloc_count() == 0);
	tlib_alloc_reset();
}
