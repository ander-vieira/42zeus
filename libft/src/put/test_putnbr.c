/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:05:18 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 12:06:12 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_putnbr_fd_child1_1(char *buf, int *fd)
{
	tlib_alloc_reset();
	pipe(fd);
	ft_putnbr_fd(53, fd[1]);
	close(fd[1]);
	tlib_print_test(read(fd[0], buf, 15) == 2);
	tlib_print_test(!memcmp(buf, "53", 2));
	tlib_print_test(tlib_alloc_count() == 0);
	close(fd[0]);
	pipe(fd);
	ft_putnbr_fd(0, fd[1]);
	close(fd[1]);
	tlib_print_test(read(fd[0], buf, 15) == 1);
	tlib_print_test(!memcmp(buf, "0", 1));
	tlib_print_test(tlib_alloc_count() == 0);
	close(fd[0]);
	pipe(fd);
	ft_putnbr_fd(-4242, fd[1]);
	close(fd[1]);
	tlib_print_test(read(fd[0], buf, 15) == 5);
	tlib_print_test(!memcmp(buf, "-4242", 5));
	tlib_print_test(tlib_alloc_count() == 0);
	close(fd[0]);
}

static int	test_putnbr_fd_child1(void)
{
	char	buf[15];
	int		fd[2];

	test_putnbr_fd_child1_1(buf, fd);
	pipe(fd);
	ft_putnbr_fd(2147483647, fd[1]);
	close(fd[1]);
	tlib_print_test(read(fd[0], buf, 15) == 10);
	tlib_print_test(!memcmp(buf, "2147483647", 10));
	tlib_print_test(tlib_alloc_count() == 0);
	close(fd[0]);
	pipe(fd);
	ft_putnbr_fd(-2147483648, fd[1]);
	close(fd[1]);
	tlib_print_test(read(fd[0], buf, 15) == 11);
	tlib_print_test(!memcmp(buf, "-2147483648", 11));
	tlib_print_test(tlib_alloc_count() == 0);
	close(fd[0]);
	return (0);
}

void	test_putnbr_fd(void)
{
	tlib_print_test(tlib_run_process(&test_putnbr_fd_child1) == 0);
}
