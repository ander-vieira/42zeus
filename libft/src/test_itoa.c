/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:32:38 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/20 18:41:00 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_itoa1(void)
{
	char	*str;

	str = ft_itoa(50);
	tlib_print_test("1", !strcmp(str, "50"), FALSE);
	free(str);
	str = ft_itoa(0);
	tlib_print_test("2", !strcmp(str, "0"), FALSE);
	free(str);
	str = ft_itoa(-42069);
	tlib_print_test("3", !strcmp(str, "-42069"), FALSE);
	free(str);
	str = ft_itoa(2147483647);
	tlib_print_test("4", !strcmp(str, "2147483647"), FALSE);
	free(str);
	str = ft_itoa(-2147483648);
	tlib_print_test("5", !strcmp(str, "-2147483648"), TRUE);
	free(str);
	tlib_alloc_reset();
}

void	test_itoa(void)
{
	tlib_print_missing(&test_itoa1, &ft_itoa, "itoa");
}