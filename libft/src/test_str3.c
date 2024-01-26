/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:38:54 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 09:39:49 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_strjoin(void)
{
	char	*str;

	str = ft_strjoin("HOLA", "MUNDO");
	tlib_print_test(str != NULL && !strcmp(str, "HOLAMUNDO"));
	tlib_print_test(tlib_alloc_lookup(str) == 10);
	tlib_print_test(tlib_alloc_count() == 1);
	free(str);
	str = ft_strjoin("", "MUNDO");
	tlib_print_test(str != NULL && !strcmp(str, "MUNDO"));
	tlib_print_test(tlib_alloc_lookup(str) == 6);
	tlib_print_test(tlib_alloc_count() == 1);
	free(str);
	str = ft_strjoin(" PEPITO ", "");
	tlib_print_test(str != NULL && !strcmp(str, " PEPITO "));
	tlib_print_test(tlib_alloc_lookup(str) == 9);
	tlib_print_test(tlib_alloc_count() == 1);
	free(str);
	str = ft_strjoin("", "");
	tlib_print_test(str != NULL && !strcmp(str, ""));
	tlib_print_test(tlib_alloc_lookup(str) == 1);
	tlib_print_test(tlib_alloc_count() == 1);
	free(str);
	tlib_print_test(tlib_alloc_errors() == 0x00);
	tlib_alloc_reset();
}

void	test_strtrim(void)
{
	char	*str;

	str = ft_strtrim("HOLA MUNDO", " ");
	tlib_print_test(str != NULL && !strcmp(str, "HOLA MUNDO"));
	tlib_print_test(tlib_alloc_lookup(str) == 11);
	tlib_print_test(tlib_alloc_count() == 1);
	free(str);
	str = ft_strtrim("HOLA MUNDO", "H");
	tlib_print_test(str != NULL && !strcmp(str, "OLA MUNDO"));
	tlib_print_test(tlib_alloc_lookup(str) == 10);
	tlib_print_test(tlib_alloc_count() == 1);
	free(str);
	str = ft_strtrim("   HOLA MUNDO ", " AU");
	tlib_print_test(str != NULL && !strcmp(str, "HOLA MUNDO"));
	tlib_print_test(tlib_alloc_lookup(str) == 11);
	tlib_print_test(tlib_alloc_count() == 1);
	free(str);
	str = ft_strtrim("\n  J K\n ", " \n");
	tlib_print_test(str != NULL && !strcmp(str, "J K"));
	tlib_print_test(tlib_alloc_lookup(str) == 4);
	tlib_print_test(tlib_alloc_count() == 1);
	free(str);
	tlib_print_test(tlib_alloc_errors() == 0x00);
	tlib_alloc_reset();
}
