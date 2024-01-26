/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlib_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:25:04 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 15:23:21 by andeviei         ###   ########.fr       */
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
		g_failed += 1;
		tlib_printf(STDOUT_FILENO, COLOR_RED"[KO]"COLOR_NONE);
	}
}

void	tlib_test_process(void (*fun)(void), int expected)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		return ;
	else if (pid == 0)
	{
		fun();
		exit(0);
	}
	waitpid(pid, &status, 0);
	if (status == expected)
		tlib_printf(STDOUT_FILENO, COLOR_GREEN"[OK]"COLOR_NONE);
	else
	{
		g_failed += 1;
		if (status == STATUS_OK)
			tlib_printf(STDOUT_FILENO, COLOR_RED"[NO CRASH]"COLOR_NONE);
		else if (status == STATUS_SEGFAULT)
			tlib_printf(STDOUT_FILENO, COLOR_RED"[SEGFAULT]"COLOR_NONE);
		else
			tlib_printf(STDOUT_FILENO, COLOR_RED"[CRASH]"COLOR_NONE);
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
