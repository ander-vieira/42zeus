/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:16:26 by andeviei          #+#    #+#             */
/*   Updated: 2023/12/18 13:01:56 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testutils.h"

static t_uint	failed_count(t_bool add)
{
	static t_uint	count;

	if (add)
		count++;
	return (count);
}

int	run_in_process(int (*fun)(void *), void *ctx)
{
	pid_t	pid;
	int		status;
	int		fd;

	pid = fork();
	if (pid == -1)
		return (-1);
	else if (pid == 0)
	{
		fd = open("/dev/null", O_RDONLY);
		dup2(fd, STDOUT_FILENO);
		dup2(fd, STDERR_FILENO);
		close(fd);
		exit(fun(ctx));
	}
	waitpid(pid, &status, 0);
	return (status);
}

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
		failed_count(TRUE);
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
	if (failed_count(FALSE) == 0)
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
