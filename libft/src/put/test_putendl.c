/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putendl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:05:18 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 14:14:45 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_putendl_fd_testone(char *str)
{
	char	buf[10];
	int		fd[2];
	ssize_t	len;

	len = strlen(str);
	pipe(fd);
	ft_putendl_fd(str, fd[1]);
	close(fd[1]);
	tlib_test_ok(read(fd[0], buf, 10) == len + 1 && !memcmp(buf, str, len)
		&& buf[len] == '\n');
	close(fd[0]);
}

static int	test_putendl_fd_child1(void)
{
	tlib_alloc_reset();
	test_putendl_fd_testone("ASDFG");
	test_putendl_fd_testone("");
	tlib_test_ok(tlib_alloc_count() == 0);
	return (0);
}

static int	test_putendl_fd_child2(void)
{
	int		fd[2];

	tlib_alloc_reset();
	pipe(fd);
	ft_putendl_fd(NULL, fd[1]);
	close(fd[1]);
	close(fd[0]);
	tlib_test_ok(tlib_alloc_count() == 0);
	return (0);
}

void	test_putendl_fd(void)
{
	tlib_test_ok(tlib_run_process(&test_putendl_fd_child1) == 0);
	tlib_test_ok(tlib_run_process(&test_putendl_fd_child2) == 0);
}
