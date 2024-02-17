/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:22:09 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/17 17:15:42 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

//TODO

void	test_strlcat(void)
{
	char	buf[10];

	strcpy(buf, "");
	tlib_test_ok(ft_strlcat(buf, "HOLA", 10) == 4);
	tlib_test_ok(!strcmp(buf, "HOLA"));
	tlib_test_ok(ft_strlcat(buf, " ", 10) == 5);
	tlib_test_ok(!strcmp(buf, "HOLA "));
	tlib_test_ok(ft_strlcat(buf, "MUNDO", 10) == 10);
	tlib_test_ok(!strcmp(buf, "HOLA MUND"));
	strcpy(buf, "AB");
	tlib_test_ok(ft_strlcat(buf, "CDE", 4) == 5);
	tlib_test_ok(!strcmp(buf, "ABC"));
	strcpy(buf, "ABC");
	tlib_test_ok(ft_strlcat(buf, "DE", 2) == 4);
	tlib_test_ok(!strcmp(buf, "ABC"));
	tlib_test_ok(tlib_alloc_count() == 0);
	tlib_alloc_reset();
}
