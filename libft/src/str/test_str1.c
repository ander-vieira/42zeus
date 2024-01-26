/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:09:04 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 13:22:16 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_strchr(void)
{
	char	*str;

	str = "HOLA MUNDO\n";
	tlib_test_ok(ft_strchr(str, 'H') == str);
	tlib_test_ok(ft_strchr(str, 'O') == str + 1);
	tlib_test_ok(ft_strchr(str, ' ') == str + 4);
	tlib_test_ok(ft_strchr(str, '\n') == str + 10);
	tlib_test_ok(ft_strchr(str, '\0') == str + 11);
	tlib_test_ok(ft_strchr(str, 'k') == NULL);
	tlib_test_ok(tlib_alloc_count() == 0);
	tlib_alloc_reset();
}

void	test_strrchr(void)
{
	char	*str;

	str = "HOLA MUNDO\n";
	tlib_test_ok(ft_strrchr(str, 'H') == str);
	tlib_test_ok(ft_strrchr(str, 'O') == str + 9);
	tlib_test_ok(ft_strrchr(str, ' ') == str + 4);
	tlib_test_ok(ft_strrchr(str, '\n') == str + 10);
	tlib_test_ok(ft_strrchr(str, '\0') == str + 11);
	tlib_test_ok(ft_strrchr(str, 'k') == NULL);
	tlib_test_ok(tlib_alloc_count() == 0);
	tlib_alloc_reset();
}

void	test_strncmp(void)
{
	tlib_test_ok(!ft_strncmp("HOLA", "HOLA", 4));
	tlib_test_ok(!ft_strncmp("HOLA", "HOLA MUNDO", 4));
	tlib_test_ok(ft_strncmp("HOLA", "HOLA MUNDO", 5));
	tlib_test_ok(!ft_strncmp("HOLA", "HALA", 1));
	tlib_test_ok(ft_strncmp("HOLA", "HALA", 2));
	tlib_test_ok(!ft_strncmp("HOLA", "HOLA", 10));
	tlib_test_ok(tlib_alloc_count() == 0);
	tlib_alloc_reset();
}
