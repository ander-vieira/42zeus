/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putendl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:05:18 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 12:01:32 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	test_putendl_fd_child1(void)
{
	char	buf[10];
	int		fd[2];

	tlib_alloc_reset();
	pipe(fd);
	ft_putendl_fd("ASDFG", fd[1]);
	close(fd[1]);
	tlib_print_test(read(fd[0], buf, 10) == 6);
	tlib_print_test(!memcmp(buf, "ASDFG\n", 6));
	tlib_print_test(tlib_alloc_count() == 0);
	close(fd[0]);
	pipe(fd);
	ft_putendl_fd("", fd[1]);
	close(fd[1]);
	tlib_print_test(read(fd[0], buf, 10) == 1);
	tlib_print_test(!memcmp(buf, "\n", 1));
	tlib_print_test(tlib_alloc_count() == 0);
	close(fd[0]);
	return (0);
}

static int	test_putendl_fd_child2(void)
{
	int		fd[2];

	tlib_alloc_reset();
	pipe(fd);
	ft_putendl_fd(NULL, fd[1]);
	tlib_print_test(tlib_alloc_count() == 0);
	close(fd[1]);
	close(fd[0]);
	return (0);
}

void	test_putendl_fd(void)
{
	tlib_print_test(tlib_run_process(&test_putendl_fd_child1) == 0);
	tlib_print_test(tlib_run_process(&test_putendl_fd_child2) == 0);
}
