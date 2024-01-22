/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:42:13 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/22 20:08:00 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_split(void)
{
	char	**split;

	split = ft_split(" HOLA MUNDO SOY  ANDER  ", ' ');
	tlib_print_test("1", split != NULL, FALSE);
	tlib_print_test("2", tlib_alloc_lookup(split) == sizeof(char *) * 5, FALSE);
	tlib_print_test("3", split[0] != NULL && !strcmp(split[0], "HOLA"), FALSE);
	tlib_print_test("4", tlib_alloc_lookup(split[0]) == 5, FALSE);
	tlib_print_test("5", split[1] != NULL && !strcmp(split[1], "MUNDO"), FALSE);
	tlib_print_test("6", tlib_alloc_lookup(split[1]) == 6, FALSE);
	tlib_print_test("7", split[2] != NULL && !strcmp(split[2], "SOY"), FALSE);
	tlib_print_test("8", tlib_alloc_lookup(split[2]) == 4, FALSE);
	tlib_print_test("9", split[3] != NULL && !strcmp(split[3], "ANDER"), FALSE);
	tlib_print_test("10", tlib_alloc_lookup(split[3]) == 6, FALSE);
	tlib_print_test("11", split[4] == NULL, FALSE);
	tlib_print_test("12", tlib_alloc_count() == 5, FALSE);
	taux_split_free(split);
	tlib_print_test("13", tlib_alloc_count() == 0, FALSE);
	tlib_print_test("14", tlib_alloc_errors() == 0x00, TRUE);
	tlib_alloc_reset();
}
