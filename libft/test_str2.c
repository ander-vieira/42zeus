/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:22:09 by andeviei          #+#    #+#             */
/*   Updated: 2023/12/18 17:32:18 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_strdup(void)
{
	char	*str;

	print_title("strdup");
	str = ft_strdup("HOLA");
	print_test("1", !strcmp(str, "HOLA"), FALSE);
	free(str);
	str = ft_strdup("");
	print_test("", !strcmp(str, ""), TRUE);
	free(str);
}

static void	test_strlcpy(void)
{
	char	buf[10];

	print_title("strlcpy");
	print_test("1", ft_strlcat(buf, "HOLA", 10) == 4, FALSE);
	print_test("2", !strcmp(buf, "HOLA"), FALSE);
	print_test("3", ft_strlcpy(buf, "HOLA MUNDO", 10) == 10, FALSE);
	print_test("4", !strcmp(buf, "HOLA MUND"), FALSE);
	print_test("5", ft_strlcpy(buf, "", 10) == 0, FALSE);
	print_test("6", !strcmp(buf, ""), TRUE);
}

static void	test_strlcat(void)
{
	char	buf[10];

	print_title("strlcat");
	strcpy(buf, "");
	print_test("1", ft_strlcat(buf, "HOLA", 10) == 4, FALSE);
	print_test("2", !strcmp(buf, "HOLA"), FALSE);
	print_test("3", ft_strlcat(buf, " ", 10) == 5, FALSE);
	print_test("4", !strcmp(buf, "HOLA "), FALSE);
	print_test("5", ft_strlcat(buf, "MUNDO", 10) == 10, FALSE);
	print_test("6", !strcmp(buf, "HOLA MUND"), FALSE);
	strcpy(buf, "AB");
	print_test("7", ft_strlcat(buf, "CDE", 4) == 5, FALSE);
	print_test("8", !strcmp(buf, "ABC"), FALSE);
	strcpy(buf, "ABC");
	print_test("9", ft_strlcat(buf, "DE", 2) == 4, FALSE);
	print_test("10", !strcmp(buf, "ABC"), TRUE);
}

static void	test_strnstr(void)
{
	char	*str;

	print_title("strnstr");
	str = "HOLA MUNDO";
	print_test("1", ft_strnstr(str, "HOLA", 10) == str, FALSE);
	print_test("2", ft_strnstr(str, "MUN", 10) == str + 5, FALSE);
	print_test("3", ft_strnstr(str, " M", 10) == str + 4, FALSE);
	print_test("4", ft_strnstr(str, " O", 10) == NULL, FALSE);
	print_test("5", ft_strnstr(str, "MUND", 5) == NULL, FALSE);
	print_test("6", ft_strnstr(str, "", 10) == str, FALSE);
	print_test("7", ft_strnstr(str, "", 0) == str, TRUE);
}

void	test_str2(void)
{
	test_strdup();
	test_strlcpy();
	test_strlcat();
	test_strnstr();
}
