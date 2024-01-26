/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:38:54 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 14:37:53 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_strjoin(void)
{
	char	*str;

	str = ft_strjoin("HOLA", "MUNDO");
	tlib_test_ok(str != NULL && !strcmp(str, "HOLAMUNDO"));
	tlib_test_ok(tlib_alloc_lookup(str) == 10);
	tlib_test_ok(tlib_alloc_count() == 1);
	free(str);
	str = ft_strjoin("", "MUNDO");
	tlib_test_ok(str != NULL && !strcmp(str, "MUNDO"));
	tlib_test_ok(tlib_alloc_lookup(str) == 6);
	tlib_test_ok(tlib_alloc_count() == 1);
	free(str);
	str = ft_strjoin(" PEPITO ", "");
	tlib_test_ok(str != NULL && !strcmp(str, " PEPITO "));
	tlib_test_ok(tlib_alloc_lookup(str) == 9);
	tlib_test_ok(tlib_alloc_count() == 1);
	free(str);
	str = ft_strjoin("", "");
	tlib_test_ok(str != NULL && !strcmp(str, ""));
	tlib_test_ok(tlib_alloc_lookup(str) == 1);
	tlib_test_ok(tlib_alloc_count() == 1);
	free(str);
	tlib_alloc_reset();
}

void	test_strtrim(void)
{
	char	*str;

	str = ft_strtrim("HOLA MUNDO", " ");
	tlib_test_ok(str != NULL && !strcmp(str, "HOLA MUNDO"));
	tlib_test_ok(tlib_alloc_lookup(str) == 11);
	tlib_test_ok(tlib_alloc_count() == 1);
	free(str);
	str = ft_strtrim("HOLA MUNDO", "H");
	tlib_test_ok(str != NULL && !strcmp(str, "OLA MUNDO"));
	tlib_test_ok(tlib_alloc_lookup(str) == 10);
	tlib_test_ok(tlib_alloc_count() == 1);
	free(str);
	str = ft_strtrim("   HOLA MUNDO ", " AU");
	tlib_test_ok(str != NULL && !strcmp(str, "HOLA MUNDO"));
	tlib_test_ok(tlib_alloc_lookup(str) == 11);
	tlib_test_ok(tlib_alloc_count() == 1);
	free(str);
	str = ft_strtrim("\n  J K\n ", " \n");
	tlib_test_ok(str != NULL && !strcmp(str, "J K"));
	tlib_test_ok(tlib_alloc_lookup(str) == 4);
	tlib_test_ok(tlib_alloc_count() == 1);
	free(str);
	tlib_alloc_reset();
}
