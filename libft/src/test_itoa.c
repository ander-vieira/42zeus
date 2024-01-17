/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:32:38 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/17 16:55:22 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

char	*ft_itoa(int n) __attribute__((weak));

static void	test_itoa1(void)
{
	char	*str;

	str = ft_itoa(50);
	print_test("1", !strcmp(str, "50"), FALSE);
	free(str);
	str = ft_itoa(0);
	print_test("2", !strcmp(str, "0"), FALSE);
	free(str);
	str = ft_itoa(-42069);
	print_test("3", !strcmp(str, "-42069"), FALSE);
	free(str);
	str = ft_itoa(2147483647);
	print_test("4", !strcmp(str, "2147483647"), FALSE);
	free(str);
	str = ft_itoa(-2147483648);
	print_test("5", !strcmp(str, "-2147483648"), TRUE);
	free(str);
}

void	test_itoa(void)
{
	test_if_exists(&test_itoa1, &ft_itoa, "itoa");
}
