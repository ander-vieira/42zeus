/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_is2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:27:18 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/17 16:31:16 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int		ft_isprint(int c) __attribute__((weak));

static void	test_isprint(void)
{
	print_test("1", !ft_isprint(0), FALSE);
	print_test("2", !ft_isprint('\n'), FALSE);
	print_test("3", ft_isprint(' '), FALSE);
	print_test("4", ft_isprint('5'), FALSE);
	print_test("5", ft_isprint('A'), FALSE);
	print_test("6", ft_isprint('a'), FALSE);
	print_test("7", ft_isprint('~'), FALSE);
	print_test("8", !ft_isprint(0x7F), FALSE);
	print_test("9", !ft_isprint(0x100), TRUE);
}

void	test_is2(void)
{
	test_if_exists(&test_isprint, &ft_isprint, "isprint");
}
