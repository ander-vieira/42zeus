/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:16:26 by andeviei          #+#    #+#             */
/*   Updated: 2023/12/11 17:36:47 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testutils.h"

t_uint	g_failed = 0;

void	print_title(char *title)
{
	printf("%s: ", title);
}

void	print_test(char *text, t_bool ok, t_bool last)
{
	printf("[%s: ", text);
	if (ok)
		printf(COLOR_GREEN"OK"COLOR_NONE);
	else
	{
		printf(COLOR_RED"KO"COLOR_NONE);
		g_failed++;
	}
	printf("]");
	if (last)
		printf("\n");
	else
		printf(" ");
}

int	print_all_tests(void)
{
	printf("--- FINAL RESULT ---\n");
	if (g_failed == 0)
	{
		printf(COLOR_GREEN"All tests OK!\n"COLOR_NONE);
		return (EXIT_SUCCESS);
	}
	else
	{
		printf(COLOR_RED"Errors detected, please review.\n"COLOR_NONE);
		return (EXIT_FAILURE);
	}
}
