/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:22:09 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 14:18:04 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

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

void	test_strnstr(void)
{
	char	*str;

	str = "HOLA MUNDO";
	tlib_test_ok(ft_strnstr(str, "HOLA", 10) == str);
	tlib_test_ok(ft_strnstr(str, "MUN", 10) == str + 5);
	tlib_test_ok(ft_strnstr(str, " M", 10) == str + 4);
	tlib_test_ok(ft_strnstr(str, " O", 10) == NULL);
	tlib_test_ok(ft_strnstr(str, "MUND", 5) == NULL);
	tlib_test_ok(ft_strnstr(str, "", 10) == str);
	tlib_test_ok(ft_strnstr(str, "", 0) == str);
	tlib_test_ok(tlib_alloc_count() == 0);
	tlib_alloc_reset();
}
