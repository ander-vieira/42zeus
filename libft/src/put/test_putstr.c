/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:05:18 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 15:09:14 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_putstr_fd_testone(char *str)
{
	char	buf[10];
	int		fd[2];
	ssize_t	len;

	len = strlen(str);
	pipe(fd);
	ft_putstr_fd(str, fd[1]);
	close(fd[1]);
	tlib_test_ok(read(fd[0], buf, 10) == len && !memcmp(buf, str, len));
	close(fd[0]);
}

static void	test_putstr_fd_child1(void)
{
	tlib_alloc_reset();
	test_putstr_fd_testone("ASDFG");
	test_putstr_fd_testone("");
	tlib_test_ok(tlib_alloc_count() == 0);
}

static void	test_putstr_fd_child2(void)
{
	int		fd[2];

	tlib_alloc_reset();
	pipe(fd);
	ft_putstr_fd(NULL, fd[1]);
	tlib_test_ok(tlib_alloc_count() == 0);
	close(fd[1]);
	close(fd[0]);
}

void	test_putstr_fd(void)
{
	tlib_test_process(&test_putstr_fd_child1, STATUS_OK);
	tlib_test_process(&test_putstr_fd_child2, STATUS_OK);
}
