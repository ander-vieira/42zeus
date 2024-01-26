/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mem3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:32:35 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 09:39:49 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_memchr(void)
{
	char	buf[11];

	strcpy(buf, "HOLA MUNDO");
	tlib_print_test(memchr(buf, 'H', 10) == buf);
	tlib_print_test(memchr(buf, 'A', 10) == buf + 3);
	tlib_print_test(memchr(buf, ' ', 10) == buf + 4);
	tlib_print_test(memchr(buf, ' ', 2) == NULL);
	tlib_print_test(memchr(buf, 'J', 10) == NULL);
	tlib_print_test(memchr(buf, '\0', 10) == NULL);
	tlib_print_test(memchr(buf, '\0', 11) == buf + 10);
	tlib_print_test(tlib_alloc_count() == 0);
	tlib_alloc_reset();
}

void	test_memcmp(void)
{
	tlib_print_test(!ft_memcmp("HOLA MUNDO", "HOLA MUNDO", 10));
	tlib_print_test(!ft_memcmp("HOLA MUNDO", "HOLA", 4));
	tlib_print_test(!ft_memcmp("HOLA MUNDO", "HOLAAAAA", 4));
	tlib_print_test(ft_memcmp("JOLA MUNDO", "HOLA MUNDO", 4));
	tlib_print_test(ft_memcmp("HOLA MUNDO", "HOLAAAAA", 5));
	tlib_print_test(ft_memcmp("", "HOLAAAAA", 1));
	tlib_print_test(!ft_memcmp("", "", 1));
	tlib_print_test(tlib_alloc_count() == 0);
	tlib_alloc_reset();
}
