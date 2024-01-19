/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:38:54 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/19 13:26:20 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
		__attribute__((weak));
char	*ft_strjoin(char const *s1, char const *s2) __attribute__((weak));
char	*ft_strtrim(char const *s, char const *set) __attribute__((weak));

static void	test_substr(void)
{
	char	*str;

	str = ft_substr("HOLA MUNDO", 0, 4);
	tlib_print_test("1", !strncmp(str, "HOLA", 5), FALSE);
	free(str);
	str = ft_substr("HOLA MUNDO", 5, 3);
	tlib_print_test("2", !strncmp(str, "MUN", 4), FALSE);
	free(str);
	str = ft_substr("HOLA MUNDO", 7, 5);
	tlib_print_test("3", !strncmp(str, "NDO", 4), FALSE);
	free(str);
	str = ft_substr("HOLA MUNDO", 15, 2);
	tlib_print_test("4", !strncmp(str, "", 1), TRUE);
	free(str);
}

static void	test_strjoin(void)
{
	char	*str;

	str = ft_strjoin("HOLA", "MUNDO");
	tlib_print_test("1", !strcmp(str, "HOLAMUNDO"), FALSE);
	free(str);
	str = ft_strjoin("", "MUNDO");
	tlib_print_test("2", !strcmp(str, "MUNDO"), FALSE);
	free(str);
	str = ft_strjoin("PEPITO ", "EL DE LOS ");
	tlib_print_test("3", !strcmp(str, "PEPITO EL DE LOS "), FALSE);
	free(str);
	str = ft_strjoin("", "");
	tlib_print_test("4", !strcmp(str, ""), TRUE);
	free(str);
}

static void	test_strtrim(void)
{
	char	*str;

	str = ft_strtrim("HOLA MUNDO", " ");
	tlib_print_test("1", !strcmp(str, "HOLA MUNDO"), FALSE);
	free(str);
	str = ft_strtrim("HOLA MUNDO", "H");
	tlib_print_test("2", !strcmp(str, "OLA MUNDO"), FALSE);
	free(str);
	str = ft_strtrim("   HOLA MUNDO ", " ");
	tlib_print_test("3", !strcmp(str, "HOLA MUNDO"), FALSE);
	free(str);
	str = ft_strtrim("   \n ", " \n");
	tlib_print_test("4", !strcmp(str, ""), FALSE);
	free(str);
	str = ft_strtrim("   \n ", "\n ");
	tlib_print_test("5", !strcmp(str, ""), FALSE);
	free(str);
	str = ft_strtrim("", " ");
	tlib_print_test("6", !strcmp(str, ""), TRUE);
	free(str);
}

void	test_str3(void)
{
	tlib_print_missing(&test_substr, &ft_substr, "substr");
	tlib_print_missing(&test_strjoin, &ft_strjoin, "strjoin");
	tlib_print_missing(&test_strtrim, &ft_strtrim, "strtrim");
}
