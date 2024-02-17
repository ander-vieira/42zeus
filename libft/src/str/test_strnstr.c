/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:22:09 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/17 17:14:22 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

//TODO

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
