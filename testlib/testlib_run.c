/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlib_run.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:51:24 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/17 16:51:42 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testlib.h"

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
