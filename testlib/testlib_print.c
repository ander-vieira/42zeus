/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlib_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:25:04 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/19 16:17:48 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testlib.h"

void	tlib_print_missing(void (*test)(void), void *fun, char *title)
{
	printf("%s: ", title);
	if (fun != NULL)
		test();
	else
	{
		printf("["COLOR_RED"MISSING"COLOR_NONE"]\n");
		*tlib_var_failed() += 1;
	}
}

void	tlib_print_test(char *text, t_bool ok, t_bool last)
{
	printf("[%s: ", text);
	if (ok)
		printf(COLOR_GREEN"OK"COLOR_NONE);
	else
	{
		printf(COLOR_RED"KO"COLOR_NONE);
		*tlib_var_failed() += 1;
	}
	printf("]");
	if (last)
		printf("\n");
	else
		printf(" ");
}

int	tlib_print_final(void)
{
	printf("--- FINAL RESULT ---\n");
	if (*tlib_var_failed() == 0)
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
