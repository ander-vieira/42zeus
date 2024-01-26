/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:05:18 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 12:25:33 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	test_putstr_fd_child1(void)
{
	char	buf[10];
	int		fd[2];

	tlib_alloc_reset();
	pipe(fd);
	ft_putstr_fd("ASDFG", fd[1]);
	close(fd[1]);
	tlib_test_ok(read(fd[0], buf, 10) == 5);
	tlib_test_ok(!memcmp(buf, "ASDFG", 5));
	tlib_test_ok(tlib_alloc_count() == 0);
	close(fd[0]);
	pipe(fd);
	ft_putstr_fd("", fd[1]);
	close(fd[1]);
	tlib_test_ok(read(fd[0], buf, 10) == 0);
	tlib_test_ok(tlib_alloc_count() == 0);
	close(fd[0]);
	return (0);
}

static int	test_putstr_fd_child2(void)
{
	int		fd[2];

	tlib_alloc_reset();
	pipe(fd);
	ft_putstr_fd(NULL, fd[1]);
	tlib_test_ok(tlib_alloc_count() == 0);
	close(fd[1]);
	close(fd[0]);
	return (0);
}

void	test_putstr_fd(void)
{
	tlib_test_ok(tlib_run_process(&test_putstr_fd_child1) == 0);
	tlib_test_ok(tlib_run_process(&test_putstr_fd_child2) == 0);
}
