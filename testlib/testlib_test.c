/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlib_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:25:04 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 12:39:33 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testlib.h"

t_uint	g_failed;

void	tlib_test_missing(void (*test)(void), void *fun, char *title)
{
	tlib_printf(STDOUT_FILENO, "--- %s ---\n", title);
	if (fun != NULL)
		test();
	else
	{
		tlib_printf(STDOUT_FILENO, "["COLOR_RED"MISSING"COLOR_NONE"]\n");
		g_failed += 1;
	}
	tlib_printf(STDOUT_FILENO, "\n");
}

void	tlib_test_ok(t_bool ok)
{
	if (ok)
		tlib_printf(STDOUT_FILENO, COLOR_GREEN"[OK]"COLOR_NONE);
	else
	{
		tlib_printf(STDOUT_FILENO, COLOR_RED"[KO]"COLOR_NONE);
		g_failed += 1;
	}
}

int	tlib_test_results(void)
{
	tlib_printf(STDOUT_FILENO, "--- FINAL RESULT ---\n");
	if (g_failed == 0)
	{
		tlib_printf(STDOUT_FILENO, COLOR_GREEN"All tests OK!\n"COLOR_NONE);
		return (EXIT_SUCCESS);
	}
	else
	{
		tlib_printf(STDOUT_FILENO,
			COLOR_RED"Errors detected, please review.\n"COLOR_NONE);
		return (EXIT_FAILURE);
	}
}
