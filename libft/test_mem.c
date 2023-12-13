/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:23:25 by andeviei          #+#    #+#             */
/*   Updated: 2023/12/13 14:53:35 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_bzero_memset(void)
{
	char	buf[5];

	print_title("bzero");
	ft_bzero(buf, 5);
	print_test("1", !memcmp(buf, "\0\0\0\0\0", 5), TRUE);
	print_title("memset");
	print_test("1", ft_memset(buf, '\0', 5) == buf, FALSE);
	print_test("2", !memcmp(buf, "\0\0\0\0\0", 5), FALSE);
	print_test("3", ft_memset(buf, '5', 5) == buf, FALSE);
	print_test("4", !memcmp(buf, "55555", 5), TRUE);
}

void	test_memcpy_memmove(void)
{
	char	buf[5];

	print_title("memcpy");
	print_test("1", ft_memcpy(buf, "AS DF", 5) == buf, FALSE);
	print_test("2", !memcmp(buf, "AS DF", 5), TRUE);
	print_title("memmove");
	print_test("1", ft_memmove(buf, "AS DF", 5) == buf, FALSE);
	print_test("2", !memcmp(buf, "AS DF", 5), FALSE);
	print_test("3", ft_memmove(buf, buf + 3, 2) == buf, FALSE);
	print_test("4", !memcmp(buf, "DF DF", 5), FALSE);
	print_test("5", ft_memmove(buf + 2, buf, 3) == buf + 2, FALSE);
	print_test("6", !memcmp(buf, "DFDF ", 5), TRUE);
}

void	test_memchr(void)
{
	char	buf[11];

	strcpy(buf, "HOLA MUNDO");
	print_title("memchr");
	print_test("1", memchr(buf, 'H', 10) == buf, FALSE);
	print_test("2", memchr(buf, 'A', 10) == buf + 3, FALSE);
	print_test("3", memchr(buf, ' ', 10) == buf + 4, FALSE);
	print_test("4", memchr(buf, ' ', 2) == NULL, FALSE);
	print_test("5", memchr(buf, 'J', 10) == NULL, FALSE);
	print_test("6", memchr(buf, '\0', 10) == NULL, FALSE);
	print_test("7", memchr(buf, '\0', 11) == buf + 10, TRUE);
}

void	test_memcmp(void)
{
	print_title("memcmp");
	print_test("1", !ft_memcmp("HOLA MUNDO", "HOLA MUNDO", 10), FALSE);
	print_test("2", !ft_memcmp("HOLA MUNDO", "HOLA", 4), FALSE);
	print_test("3", !ft_memcmp("HOLA MUNDO", "HOLAAAAA", 4), FALSE);
	print_test("4", ft_memcmp("JOLA MUNDO", "HOLA MUNDO", 4), FALSE);
	print_test("5", ft_memcmp("HOLA MUNDO", "HOLAAAAA", 5), FALSE);
	print_test("6", ft_memcmp("", "HOLAAAAA", 1), FALSE);
	print_test("7", !ft_memcmp("", "", 1), TRUE);
}

void	test_mem(void)
{
	test_bzero_memset();
	test_memcpy_memmove();
	test_memchr();
	test_memcmp();
}