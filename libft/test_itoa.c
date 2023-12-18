/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:32:38 by andeviei          #+#    #+#             */
/*   Updated: 2023/12/18 17:19:16 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_itoa(void)
{
	char	*str;

	print_title("itoa");
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
