/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:09:04 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 09:39:49 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_strlen(void)
{
	tlib_print_test(ft_strlen("HOLA") == 4);
	tlib_print_test(ft_strlen("HOLA MUNDO\nAAA") == 14);
	tlib_print_test(ft_strlen("") == 0);
	tlib_print_test(tlib_alloc_count() == 0);
	tlib_alloc_reset();
}

void	test_strchr(void)
{
	char	*str;

	str = "HOLA MUNDO\n";
	tlib_print_test(ft_strchr(str, 'H') == str);
	tlib_print_test(ft_strchr(str, 'O') == str + 1);
	tlib_print_test(ft_strchr(str, ' ') == str + 4);
	tlib_print_test(ft_strchr(str, '\n') == str + 10);
	tlib_print_test(ft_strchr(str, '\0') == str + 11);
	tlib_print_test(ft_strchr(str, 'k') == NULL);
	tlib_print_test(tlib_alloc_count() == 0);
	tlib_alloc_reset();
}

void	test_strrchr(void)
{
	char	*str;

	str = "HOLA MUNDO\n";
	tlib_print_test(ft_strrchr(str, 'H') == str);
	tlib_print_test(ft_strrchr(str, 'O') == str + 9);
	tlib_print_test(ft_strrchr(str, ' ') == str + 4);
	tlib_print_test(ft_strrchr(str, '\n') == str + 10);
	tlib_print_test(ft_strrchr(str, '\0') == str + 11);
	tlib_print_test(ft_strrchr(str, 'k') == NULL);
	tlib_print_test(tlib_alloc_count() == 0);
	tlib_alloc_reset();
}

void	test_strncmp(void)
{
	tlib_print_test(!ft_strncmp("HOLA", "HOLA", 4));
	tlib_print_test(!ft_strncmp("HOLA", "HOLA MUNDO", 4));
	tlib_print_test(ft_strncmp("HOLA", "HOLA MUNDO", 5));
	tlib_print_test(!ft_strncmp("HOLA", "HALA", 1));
	tlib_print_test(ft_strncmp("HOLA", "HALA", 2));
	tlib_print_test(!ft_strncmp("HOLA", "HOLA", 10));
	tlib_print_test(tlib_alloc_count() == 0);
	tlib_alloc_reset();
}
