/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:38:54 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/22 20:19:58 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_strjoin(void)
{
	char	*str;

	str = ft_strjoin("HOLA", "MUNDO");
	tlib_print_test("1", str != NULL && !strcmp(str, "HOLAMUNDO"), FALSE);
	tlib_print_test("2", tlib_alloc_lookup(str) == 10, FALSE);
	tlib_print_test("3", tlib_alloc_count() == 1, FALSE);
	free(str);
	str = ft_strjoin("", "MUNDO");
	tlib_print_test("4", str != NULL && !strcmp(str, "MUNDO"), FALSE);
	tlib_print_test("5", tlib_alloc_lookup(str) == 6, FALSE);
	tlib_print_test("6", tlib_alloc_count() == 1, FALSE);
	free(str);
	str = ft_strjoin(" PEPITO ", "");
	tlib_print_test("7", str != NULL && !strcmp(str, " PEPITO "), FALSE);
	tlib_print_test("8", tlib_alloc_lookup(str) == 9, FALSE);
	tlib_print_test("9", tlib_alloc_count() == 1, FALSE);
	free(str);
	str = ft_strjoin("", "");
	tlib_print_test("10", str != NULL && !strcmp(str, ""), FALSE);
	tlib_print_test("11", tlib_alloc_lookup(str) == 1, FALSE);
	tlib_print_test("12", tlib_alloc_count() == 1, FALSE);
	free(str);
	tlib_print_test("13", tlib_alloc_errors() == 0x00, TRUE);
	tlib_alloc_reset();
}

void	test_strtrim(void)
{
	char	*str;

	str = ft_strtrim("HOLA MUNDO", " ");
	tlib_print_test("1", str != NULL && !strcmp(str, "HOLA MUNDO"), FALSE);
	tlib_print_test("2", tlib_alloc_lookup(str) == 11, FALSE);
	tlib_print_test("3", tlib_alloc_count() == 1, FALSE);
	free(str);
	str = ft_strtrim("HOLA MUNDO", "H");
	tlib_print_test("4", str != NULL && !strcmp(str, "OLA MUNDO"), FALSE);
	tlib_print_test("5", tlib_alloc_lookup(str) == 10, FALSE);
	tlib_print_test("6", tlib_alloc_count() == 1, FALSE);
	free(str);
	str = ft_strtrim("   HOLA MUNDO ", " AU");
	tlib_print_test("7", str != NULL && !strcmp(str, "HOLA MUNDO"), FALSE);
	tlib_print_test("8", tlib_alloc_lookup(str) == 11, FALSE);
	tlib_print_test("9", tlib_alloc_count() == 1, FALSE);
	free(str);
	str = ft_strtrim("\n  J K\n ", " \n");
	tlib_print_test("10", str != NULL && !strcmp(str, "J K"), FALSE);
	tlib_print_test("11", tlib_alloc_lookup(str) == 4, FALSE);
	tlib_print_test("12", tlib_alloc_count() == 1, FALSE);
	free(str);
	tlib_print_test("13", tlib_alloc_errors() == 0x00, TRUE);
	tlib_alloc_reset();
}
