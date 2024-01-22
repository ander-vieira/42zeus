/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:22:09 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/22 20:18:53 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_strdup(void)
{
	char	*str;

	str = ft_strdup("HOLA");
	tlib_print_test("1", !strcmp(str, "HOLA"), FALSE);
	tlib_print_test("2", tlib_alloc_lookup(str) == 5, FALSE);
	tlib_print_test("3", tlib_alloc_count() == 1, FALSE);
	free(str);
	str = ft_strdup("");
	tlib_print_test("4", !strcmp(str, ""), FALSE);
	tlib_print_test("5", tlib_alloc_lookup(str) == 1, FALSE);
	tlib_print_test("6", tlib_alloc_count() == 1, FALSE);
	free(str);
	tlib_print_test("7", tlib_alloc_errors() == 0x00, TRUE);
	tlib_alloc_reset();
}

void	test_strlcpy(void)
{
	char	buf[10];

	tlib_print_test("1", ft_strlcat(buf, "HOLA", 10) == 4, FALSE);
	tlib_print_test("2", !strcmp(buf, "HOLA"), FALSE);
	tlib_print_test("3", ft_strlcpy(buf, "HOLA MUNDO", 10) == 10, FALSE);
	tlib_print_test("4", !strcmp(buf, "HOLA MUND"), FALSE);
	tlib_print_test("5", ft_strlcpy(buf, "", 10) == 0, FALSE);
	tlib_print_test("6", !strcmp(buf, ""), FALSE);
	tlib_print_test("7", tlib_alloc_count() == 0, TRUE);
	tlib_alloc_reset();
}

void	test_strlcat(void)
{
	char	buf[10];

	strcpy(buf, "");
	tlib_print_test("1", ft_strlcat(buf, "HOLA", 10) == 4, FALSE);
	tlib_print_test("2", !strcmp(buf, "HOLA"), FALSE);
	tlib_print_test("3", ft_strlcat(buf, " ", 10) == 5, FALSE);
	tlib_print_test("4", !strcmp(buf, "HOLA "), FALSE);
	tlib_print_test("5", ft_strlcat(buf, "MUNDO", 10) == 10, FALSE);
	tlib_print_test("6", !strcmp(buf, "HOLA MUND"), FALSE);
	strcpy(buf, "AB");
	tlib_print_test("7", ft_strlcat(buf, "CDE", 4) == 5, FALSE);
	tlib_print_test("8", !strcmp(buf, "ABC"), FALSE);
	strcpy(buf, "ABC");
	tlib_print_test("9", ft_strlcat(buf, "DE", 2) == 4, FALSE);
	tlib_print_test("10", !strcmp(buf, "ABC"), FALSE);
	tlib_print_test("11", tlib_alloc_count() == 0, TRUE);
	tlib_alloc_reset();
}

void	test_strnstr(void)
{
	char	*str;

	str = "HOLA MUNDO";
	tlib_print_test("1", ft_strnstr(str, "HOLA", 10) == str, FALSE);
	tlib_print_test("2", ft_strnstr(str, "MUN", 10) == str + 5, FALSE);
	tlib_print_test("3", ft_strnstr(str, " M", 10) == str + 4, FALSE);
	tlib_print_test("4", ft_strnstr(str, " O", 10) == NULL, FALSE);
	tlib_print_test("5", ft_strnstr(str, "MUND", 5) == NULL, FALSE);
	tlib_print_test("6", ft_strnstr(str, "", 10) == str, FALSE);
	tlib_print_test("7", ft_strnstr(str, "", 0) == str, FALSE);
	tlib_print_test("8", tlib_alloc_count() == 0, TRUE);
	tlib_alloc_reset();
}
