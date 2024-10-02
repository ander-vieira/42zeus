/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putendl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:05:18 by andeviei          #+#    #+#             */
/*   Updated: 2024/10/02 23:46:19 by andeviei         ###   ########.fr       */
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
	tlib_testresult_bool(read(fd[0], buf, 10) == len + 1 && !memcmp(buf, str, len)
		&& buf[len] == '\n');
	close(fd[0]);
}

static void	test_putendl_fd_child1(void)
{
	tlib_mockmalloc_reset();
	test_putendl_fd_testone("ASDFG");
	test_putendl_fd_testone("");
	tlib_testmalloc_count(0);
}

static void	test_putendl_fd_child2(void)
{
	int		fd[2];

	tlib_mockmalloc_reset();
	pipe(fd);
	ft_putendl_fd(NULL, fd[1]);
	close(fd[1]);
	close(fd[0]);
	tlib_testmalloc_count(0);
}

void	test_putendl_fd(void)
{
	tlib_test_process(&test_putendl_fd_child1, PRESULT_OK);
	tlib_test_process(&test_putendl_fd_child2, PRESULT_OK);
}
