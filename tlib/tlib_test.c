/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tlib_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:25:04 by andeviei          #+#    #+#             */
/*   Updated: 2024/10/03 00:33:22 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tlib_int.h"

t_bool	g_child;
t_bool	g_failed;

static void	tlib_test_setfail()
{
	if (g_child)
		kill(getppid(), SIGUSR1);
	else
		g_failed = TRUE;
}

void	handle_sigusr(int signal)
{
	tlib_test_setfail();
}

void	tlib_testmissing(void (*test)(void), void *fun, char *title)
{
	tlib_printf(STDOUT_FILENO, "--- %s ---\n", title);
	if (fun != NULL)
		test();
	else
	{
		tlib_test_setfail();
		tlib_printf(STDOUT_FILENO, "["COLOR_RED"MISSING"COLOR_NONE"]\n");
	}
	tlib_printf(STDOUT_FILENO, "\n");
}

void	tlib_testresult_bool(t_bool ok)
{
	if (ok)
		tlib_printf(STDOUT_FILENO, COLOR_GREEN"[OK]"COLOR_NONE);
	else
	{
		tlib_test_setfail();
		tlib_printf(STDOUT_FILENO, COLOR_RED"[KO]"COLOR_NONE);
	}
}

void	tlib_testmalloc_size(void *addr, size_t expected_size) {
	size_t	actual_size;

	actual_size = tlib_mockmalloc_lookup(addr);
	if (actual_size == expected_size)
		tlib_printf(STDOUT_FILENO, COLOR_GREEN"[OK]"COLOR_NONE);
	else
	{
		tlib_test_setfail();
		tlib_printf(STDOUT_FILENO, COLOR_RED"[KO]"COLOR_NONE);
		//TODO report error
	}
}

void	tlib_testmalloc_count(size_t expected_count) {
	size_t	actual_count;

	actual_count = tlib_mockmalloc_count();
	if (actual_count == expected_count)
		tlib_printf(STDOUT_FILENO, COLOR_GREEN"[OK]"COLOR_NONE);
	else
	{
		tlib_test_setfail();
		tlib_printf(STDOUT_FILENO, COLOR_RED"[KO]"COLOR_NONE);
		//TODO report error
	}
}

static t_pres	get_pres(int status)
{
	if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
		return (PRESULT_OK);
	else if (WIFSIGNALED(status) && WTERMSIG(status) == 11)
		return (PRESULT_SEGFAULT);
	else
		return (PRESULT_CRASH);
}

static void	print_pres(t_pres pres)
{
	if (pres == PRESULT_OK)
		tlib_printf(STDOUT_FILENO, COLOR_RED"[NO CRASH]"COLOR_NONE);
	else if (pres == PRESULT_SEGFAULT)
		tlib_printf(STDOUT_FILENO, COLOR_RED"[SEGFAULT]"COLOR_NONE);
	else
		tlib_printf(STDOUT_FILENO, COLOR_RED"[CRASH]"COLOR_NONE);
}

void	tlib_test_process(void (*fun)(void), t_pres expected)
{
	pid_t	pid;
	int		status;
	t_pres	pres;
	void	(*sighandler)(int);

	sighandler = signal(SIGUSR1, &handle_sigusr);
	pid = fork();
	if (pid == -1)
		return ;
	else if (pid == 0)
	{
		g_child = TRUE;
		fun();
		exit(0);
	}
	waitpid(pid, &status, 0);
	signal(SIGUSR1, sighandler);
	pres = get_pres(status);
	if (pres == expected)
		tlib_printf(STDOUT_FILENO, COLOR_GREEN"[OK]"COLOR_NONE);
	else
	{
		tlib_test_setfail();
		print_pres(pres);
	}
}

int	tlib_test_results(void)
{
	tlib_printf(STDOUT_FILENO, "--- FINAL RESULT ---\n");
	if (!g_failed)
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
