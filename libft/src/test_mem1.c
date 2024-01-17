/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mem1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:23:25 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/17 16:38:49 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	ft_bzero(void *b, size_t n) __attribute__((weak));
void	*ft_memset(void *b, int c, size_t n) __attribute__((weak));
void	*ft_memcpy(void *d, const void *s, size_t n) __attribute__((weak));
void	*ft_memmove(void *d, const void *s, size_t n) __attribute__((weak));

static void	test_bzero(void)
{
	char	buf[5];

	ft_bzero(buf, 5);
	print_test("1", !memcmp(buf, "\0\0\0\0\0", 5), TRUE);
}

static void	test_memset(void)
{
	char	buf[5];

	print_test("1", ft_memset(buf, '\0', 5) == buf, FALSE);
	print_test("2", !memcmp(buf, "\0\0\0\0\0", 5), FALSE);
	print_test("3", ft_memset(buf, '5', 5) == buf, FALSE);
	print_test("4", !memcmp(buf, "55555", 5), TRUE);
}

static void	test_memcpy(void)
{
	char	buf[5];

	print_test("1", ft_memcpy(buf, "AS DF", 5) == buf, FALSE);
	print_test("2", !memcmp(buf, "AS DF", 5), TRUE);
}

static void	test_memmove(void)
{
	char	buf[5];

	print_test("1", ft_memmove(buf, "AS DF", 5) == buf, FALSE);
	print_test("2", !memcmp(buf, "AS DF", 5), FALSE);
	print_test("3", ft_memmove(buf, buf + 3, 2) == buf, FALSE);
	print_test("4", !memcmp(buf, "DF DF", 5), FALSE);
	print_test("5", ft_memmove(buf + 2, buf, 3) == buf + 2, FALSE);
	print_test("6", !memcmp(buf, "DFDF ", 5), TRUE);
}

void	test_mem1(void)
{
	test_if_exists(&test_bzero, &ft_bzero, "bzero");
	test_if_exists(&test_memset, &ft_memset, "memset");
	test_if_exists(&test_memcpy, &ft_memcpy, "memcpy");
	test_if_exists(&test_memmove, &ft_memmove, "memmove");
}
