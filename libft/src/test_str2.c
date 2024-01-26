/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:22:09 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 09:39:49 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_strdup(void)
{
	char	*str;

	str = ft_strdup("HOLA");
	tlib_print_test(!strcmp(str, "HOLA"));
	tlib_print_test(tlib_alloc_lookup(str) == 5);
	tlib_print_test(tlib_alloc_count() == 1);
	free(str);
	str = ft_strdup("");
	tlib_print_test(!strcmp(str, ""));
	tlib_print_test(tlib_alloc_lookup(str) == 1);
	tlib_print_test(tlib_alloc_count() == 1);
	free(str);
	tlib_print_test(tlib_alloc_errors() == 0x00);
	tlib_alloc_reset();
}

void	test_strlcpy(void)
{
	char	buf[10];

	tlib_print_test(ft_strlcat(buf, "HOLA", 10) == 4);
	tlib_print_test(!strcmp(buf, "HOLA"));
	tlib_print_test(ft_strlcpy(buf, "HOLA MUNDO", 10) == 10);
	tlib_print_test(!strcmp(buf, "HOLA MUND"));
	tlib_print_test(ft_strlcpy(buf, "", 10) == 0);
	tlib_print_test(!strcmp(buf, ""));
	tlib_print_test(tlib_alloc_count() == 0);
	tlib_alloc_reset();
}

void	test_strlcat(void)
{
	char	buf[10];

	strcpy(buf, "");
	tlib_print_test(ft_strlcat(buf, "HOLA", 10) == 4);
	tlib_print_test(!strcmp(buf, "HOLA"));
	tlib_print_test(ft_strlcat(buf, " ", 10) == 5);
	tlib_print_test(!strcmp(buf, "HOLA "));
	tlib_print_test(ft_strlcat(buf, "MUNDO", 10) == 10);
	tlib_print_test(!strcmp(buf, "HOLA MUND"));
	strcpy(buf, "AB");
	tlib_print_test(ft_strlcat(buf, "CDE", 4) == 5);
	tlib_print_test(!strcmp(buf, "ABC"));
	strcpy(buf, "ABC");
	tlib_print_test(ft_strlcat(buf, "DE", 2) == 4);
	tlib_print_test(!strcmp(buf, "ABC"));
	tlib_print_test(tlib_alloc_count() == 0);
	tlib_alloc_reset();
}

void	test_strnstr(void)
{
	char	*str;

	str = "HOLA MUNDO";
	tlib_print_test(ft_strnstr(str, "HOLA", 10) == str);
	tlib_print_test(ft_strnstr(str, "MUN", 10) == str + 5);
	tlib_print_test(ft_strnstr(str, " M", 10) == str + 4);
	tlib_print_test(ft_strnstr(str, " O", 10) == NULL);
	tlib_print_test(ft_strnstr(str, "MUND", 5) == NULL);
	tlib_print_test(ft_strnstr(str, "", 10) == str);
	tlib_print_test(ft_strnstr(str, "", 0) == str);
	tlib_print_test(tlib_alloc_count() == 0);
	tlib_alloc_reset();
}
