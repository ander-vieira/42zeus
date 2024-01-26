/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:05:18 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 15:09:14 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_putchar_fd_testone(char c)
{
	char	buf[2];
	int		fd[2];

	pipe(fd);
	ft_putchar_fd(c, fd[1]);
	close(fd[1]);
	tlib_test_ok(read(fd[0], buf, 2) == 1 && buf[0] == c);
	close(fd[0]);
}

static void	test_putchar_fd_child1(void)
{
	tlib_alloc_reset();
	test_putchar_fd_testone('A');
	test_putchar_fd_testone('\0');
	tlib_test_ok(tlib_alloc_count() == 0);
}

void	test_putchar_fd(void)
{
	tlib_test_process(&test_putchar_fd_child1, STATUS_OK);
}
