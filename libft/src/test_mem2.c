/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mem2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:32:35 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/19 13:26:20 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	*ft_memchr(const void *s, int c, size_t n) __attribute__((weak));
int		ft_memcmp(const void *s1, const void *s2, size_t n)
		__attribute__((weak));

static void	test_memchr(void)
{
	char	buf[11];

	strcpy(buf, "HOLA MUNDO");
	tlib_print_test("1", memchr(buf, 'H', 10) == buf, FALSE);
	tlib_print_test("2", memchr(buf, 'A', 10) == buf + 3, FALSE);
	tlib_print_test("3", memchr(buf, ' ', 10) == buf + 4, FALSE);
	tlib_print_test("4", memchr(buf, ' ', 2) == NULL, FALSE);
	tlib_print_test("5", memchr(buf, 'J', 10) == NULL, FALSE);
	tlib_print_test("6", memchr(buf, '\0', 10) == NULL, FALSE);
	tlib_print_test("7", memchr(buf, '\0', 11) == buf + 10, TRUE);
}

static void	test_memcmp(void)
{
	tlib_print_test("1", !ft_memcmp("HOLA MUNDO", "HOLA MUNDO", 10), FALSE);
	tlib_print_test("2", !ft_memcmp("HOLA MUNDO", "HOLA", 4), FALSE);
	tlib_print_test("3", !ft_memcmp("HOLA MUNDO", "HOLAAAAA", 4), FALSE);
	tlib_print_test("4", ft_memcmp("JOLA MUNDO", "HOLA MUNDO", 4), FALSE);
	tlib_print_test("5", ft_memcmp("HOLA MUNDO", "HOLAAAAA", 5), FALSE);
	tlib_print_test("6", ft_memcmp("", "HOLAAAAA", 1), FALSE);
	tlib_print_test("7", !ft_memcmp("", "", 1), TRUE);
}

void	test_mem2(void)
{
	tlib_print_missing(&test_memchr, &ft_memchr, "memchr");
	tlib_print_missing(&test_memcmp, &ft_memcmp, "memcmp");
}
