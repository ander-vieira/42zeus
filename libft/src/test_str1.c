/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:09:04 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/17 16:45:39 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

size_t	ft_strlen(const char *str) __attribute__((weak));
char	*ft_strchr(const char *str, int c) __attribute__((weak));
char	*ft_strrchr(const char *str, int c) __attribute__((weak));
int		ft_strncmp(const char *s1, const char *s2, size_t n)
		__attribute__((weak));

static void	test_strlen(void)
{
	print_test("1", ft_strlen("HOLA") == 4, FALSE);
	print_test("2", ft_strlen("HOLA MUNDO\nAAA") == 14, FALSE);
	print_test("3", ft_strlen("") == 0, TRUE);
}

static void	test_strchr(void)
{
	char	*str;

	str = "HOLA MUNDO\n";
	print_test("1", ft_strchr(str, 'H') == str, FALSE);
	print_test("2", ft_strchr(str, 'O') == str + 1, FALSE);
	print_test("3", ft_strchr(str, ' ') == str + 4, FALSE);
	print_test("4", ft_strchr(str, '\n') == str + 10, FALSE);
	print_test("5", ft_strchr(str, '\0') == str + 11, FALSE);
	print_test("6", ft_strchr(str, 'k') == NULL, TRUE);
}

static void	test_strrchr(void)
{
	char	*str;

	str = "HOLA MUNDO\n";
	print_test("1", ft_strrchr(str, 'H') == str, FALSE);
	print_test("2", ft_strrchr(str, 'O') == str + 9, FALSE);
	print_test("3", ft_strrchr(str, ' ') == str + 4, FALSE);
	print_test("4", ft_strrchr(str, '\n') == str + 10, FALSE);
	print_test("5", ft_strrchr(str, '\0') == str + 11, FALSE);
	print_test("6", ft_strrchr(str, 'k') == NULL, TRUE);
}

static void	test_strncmp(void)
{
	print_test("1", !ft_strncmp("HOLA", "HOLA", 4), FALSE);
	print_test("2", !ft_strncmp("HOLA", "HOLA MUNDO", 4), FALSE);
	print_test("3", ft_strncmp("HOLA", "HOLA MUNDO", 5), FALSE);
	print_test("4", !ft_strncmp("HOLA", "HALA", 1), FALSE);
	print_test("5", ft_strncmp("HOLA", "HALA", 2), FALSE);
	print_test("6", !ft_strncmp("HOLA", "HOLA", 10), TRUE);
}

void	test_str1(void)
{
	test_if_exists(&test_strlen, &ft_strlen, "strlen");
	test_if_exists(&test_strchr, &ft_strchr, "strchr");
	test_if_exists(&test_strrchr, &ft_strrchr, "strrchr");
	test_if_exists(&test_strncmp, &ft_strncmp, "strncmp");
}
