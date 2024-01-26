/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:05:18 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 13:08:07 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_putnbr_fd_testone(int num, char *str)
{
	char	buf[15];
	int		fd[2];
	ssize_t	len;

	pipe(fd);
	ft_putnbr_fd(num, fd[1]);
	close(fd[1]);
	len = strlen(str);
	tlib_test_ok(read(fd[0], buf, 15) == len);
	tlib_test_ok(!memcmp(buf, str, len));
	tlib_test_ok(tlib_alloc_count() == 0);
	close(fd[0]);
}

static int	test_putnbr_fd_child1(void)
{

	tlib_alloc_reset();
	test_putnbr_fd_testone(53, "53");
	test_putnbr_fd_testone(0, "0");
	test_putnbr_fd_testone(-4242, "-4242");
	test_putnbr_fd_testone(2147483647, "2147483647");
	test_putnbr_fd_testone(-2147483648, "-2147483648");
	return (0);
}

void	test_putnbr_fd(void)
{
	tlib_test_ok(tlib_run_process(&test_putnbr_fd_child1) == 0);
}
