/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:05:18 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 11:58:56 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	test_putchar_fd_child1(void)
{
	char	buf[10];
	int		fd[2];

	tlib_alloc_reset();
	pipe(fd);
	ft_putchar_fd('5', fd[1]);
	close(fd[1]);
	tlib_print_test(read(fd[0], buf, 10) == 1);
	tlib_print_test(buf[0] == '5');
	tlib_print_test(tlib_alloc_count() == 0);
	close(fd[0]);
	tlib_alloc_reset();
	pipe(fd);
	ft_putchar_fd('\0', fd[1]);
	close(fd[1]);
	tlib_print_test(read(fd[0], buf, 10) == 1);
	tlib_print_test(buf[0] == '\0');
	close(fd[0]);
	return (0);
}

void	test_putchar_fd(void)
{
	tlib_print_test(tlib_run_process(&test_putchar_fd_child1) == 0);
}
