/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlib_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:25:04 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/20 13:11:53 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testlib.h"

void	tlib_print_missing(void (*test)(void), void *fun, char *title)
{
	tlib_printf(STDOUT_FILENO, "%s: ", title);
	if (fun != NULL)
		test();
	else
	{
		tlib_printf(STDOUT_FILENO, "["COLOR_RED"MISSING"COLOR_NONE"]\n");
		*tlib_var_failed() += 1;
	}
}

void	tlib_print_test(char *text, t_bool ok, t_bool last)
{
	tlib_printf(STDOUT_FILENO, "[%s: ", text);
	if (ok)
		tlib_printf(STDOUT_FILENO, COLOR_GREEN"OK"COLOR_NONE);
	else
	{
		tlib_printf(STDOUT_FILENO, COLOR_RED"KO"COLOR_NONE);
		*tlib_var_failed() += 1;
	}
	tlib_printf(STDOUT_FILENO, "]");
	if (last)
		tlib_printf(STDOUT_FILENO, "\n");
	else
		tlib_printf(STDOUT_FILENO, " ");
}

int	tlib_print_final(void)
{
	tlib_printf(STDOUT_FILENO, "--- FINAL RESULT ---\n");
	if (*tlib_var_failed() == 0)
	{
		tlib_printf(STDOUT_FILENO, COLOR_GREEN"All tests OK!\n"COLOR_NONE);
		return (EXIT_SUCCESS);
	}
	else
	{
		tlib_printf(STDOUT_FILENO, COLOR_RED"Errors detected, please review.\n"COLOR_NONE);
		return (EXIT_FAILURE);
	}
}
