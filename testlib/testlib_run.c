/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlib_run.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:51:24 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/22 14:11:43 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testlib.h"

int	tlib_run_process(int (*fun)(void *), void *ctx)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		return (-1);
	else if (pid == 0)
		exit(fun(ctx));
	waitpid(pid, &status, 0);
	return (status);
}
