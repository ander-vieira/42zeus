/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:38:54 by andeviei          #+#    #+#             */
/*   Updated: 2023/12/18 17:19:14 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_substr(void)
{
	char	*str;

	print_title("substr");
	str = ft_substr("HOLA MUNDO", 0, 4);
	print_test("1", !strncmp(str, "HOLA", 5), FALSE);
	free(str);
	str = ft_substr("HOLA MUNDO", 5, 3);
	print_test("2", !strncmp(str, "MUN", 4), FALSE);
	free(str);
	str = ft_substr("HOLA MUNDO", 7, 5);
	print_test("3", !strncmp(str, "NDO", 4), FALSE);
	free(str);
	str = ft_substr("HOLA MUNDO", 15, 2);
	print_test("4", !strncmp(str, "", 1), FALSE);
	free(str);
}

static void	test_strjoin(void)
{
	print_title("strjoin");
	print_test("1", TRUE, TRUE);
}

static void	test_strtrim(void)
{
	print_title("strtrim");
	print_test("1", TRUE, TRUE);
}

void	test_str3(void)
{
	test_substr();
	test_strjoin();
	test_strtrim();
}
