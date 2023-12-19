/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:38:54 by andeviei          #+#    #+#             */
/*   Updated: 2023/12/18 17:31:33 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_substr(void)
{
	char	*str;

	print_title("substr");
	str = ft_substr("HOLA MUNDO", 0, 4);
	print_test("1", !strncmp(str, "HOLA", 5), FALSE);
	free(str);
	str = ft_substr("HOLA MUNDO", 5, 3);
	print_test("2", !strncmp(str, "MUN", 4), FALSE);
	free(str);
	str = ft_substr("HOLA MUNDO", 7, 5);
	print_test("3", !strncmp(str, "NDO", 4), FALSE);
	free(str);
	str = ft_substr("HOLA MUNDO", 15, 2);
	print_test("4", !strncmp(str, "", 1), TRUE);
	free(str);
}

static void	test_strjoin(void)
{
	char	*str;

	print_title("strjoin");
	str = ft_strjoin("HOLA", "MUNDO");
	print_test("1", !strcmp(str, "HOLAMUNDO"), FALSE);
	free(str);
	str = ft_strjoin("", "MUNDO");
	print_test("2", !strcmp(str, "MUNDO"), FALSE);
	free(str);
	str = ft_strjoin("PEPITO ", "EL DE LOS ");
	print_test("3", !strcmp(str, "PEPITO EL DE LOS "), FALSE);
	free(str);
	str = ft_strjoin("", "");
	print_test("4", !strcmp(str, ""), TRUE);
	free(str);
}

static void	test_strtrim(void)
{
	char	*str;

	print_title("strtrim");
	str = ft_strtrim("HOLA MUNDO", " ");
	print_test("1", !strcmp(str, "HOLA MUNDO"), FALSE);
	free(str);
	str = ft_strtrim("HOLA MUNDO", "H");
	print_test("2", !strcmp(str, "OLA MUNDO"), FALSE);
	free(str);
	str = ft_strtrim("   HOLA MUNDO ", " ");
	print_test("3", !strcmp(str, "HOLA MUNDO"), FALSE);
	free(str);
	str = ft_strtrim("   \n ", " \n");
	print_test("4", !strcmp(str, ""), FALSE);
	free(str);
	str = ft_strtrim("   \n ", "\n ");
	print_test("5", !strcmp(str, ""), FALSE);
	free(str);
	str = ft_strtrim("", " ");
	print_test("6", !strcmp(str, ""), TRUE);
	free(str);
}

void	test_str3(void)
{
	test_substr();
	test_strjoin();
	test_strtrim();
}
