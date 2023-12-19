/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_put.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:05:18 by andeviei          #+#    #+#             */
/*   Updated: 2023/12/18 13:12:30 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_putchar_fd(void)
{
	int		fd[2];
	char	c;

	print_title("putchar_fd");
	pipe(fd);
	ft_putchar_fd('5', fd[1]);
	print_test("1", read(fd[0], &c, 1) == 1, FALSE);
	print_test("2", c == '5', FALSE);
	ft_putchar_fd(' ', fd[1]);
	print_test("3", read(fd[0], &c, 1) == 1, FALSE);
	print_test("4", c == ' ', FALSE);
	ft_putchar_fd('\0', fd[1]);
	print_test("5", read(fd[0], &c, 1) == 1, FALSE);
	print_test("6", c == '\0', TRUE);
	close(fd[0]);
	close(fd[1]);
}

static void	test_putstr_fd(void)
{
	int		fd[2];
	char	str[11];

	print_title("putstr_fd");
	pipe(fd);
	ft_putstr_fd("HOLA MUNDO", fd[1]);
	print_test("1", read(fd[0], str, 10) == 10, FALSE);
	print_test("2", !memcmp(str, "HOLA MUNDO", 10), FALSE);
	ft_putstr_fd("PEPITO\n\n", fd[1]);
	print_test("3", read(fd[0], str, 8) == 8, FALSE);
	print_test("4", !memcmp(str, "PEPITO\n\n", 8), TRUE);
	close(fd[0]);
	close(fd[1]);
}

static void	test_putendl_fd(void)
{
	int		fd[2];
	char	str[11];

	print_title("putendl_fd");
	pipe(fd);
	ft_putendl_fd("HOLA MUNDO", fd[1]);
	print_test("1", read(fd[0], str, 11) == 11, FALSE);
	print_test("2", !memcmp(str, "HOLA MUNDO\n", 11), FALSE);
	ft_putendl_fd("\n", fd[1]);
	print_test("3", read(fd[0], str, 1) == 1, FALSE);
	print_test("4", !memcmp(str, "\n", 1), TRUE);
	close(fd[0]);
	close(fd[1]);
}

static void	test_putnbr_fd(void)
{
	int		fd[2];
	char	str[11];

	print_title("putnbr_fd");
	pipe(fd);
	ft_putnbr_fd(53, fd[1]);
	print_test("1", read(fd[0], str, 2) == 2, FALSE);
	print_test("2", !memcmp(str, "53", 2), FALSE);
	ft_putnbr_fd(0, fd[1]);
	print_test("3", read(fd[0], str, 1) == 1, FALSE);
	print_test("4", !memcmp(str, "0", 1), FALSE);
	ft_putnbr_fd(-42, fd[1]);
	print_test("5", read(fd[0], str, 3) == 3, FALSE);
	print_test("6", !memcmp(str, "-42", 3), FALSE);
	ft_putnbr_fd(2147483647, fd[1]);
	print_test("7", read(fd[0], str, 10) == 10, FALSE);
	print_test("8", !memcmp(str, "2147483647", 10), FALSE);
	ft_putnbr_fd(-2147483648, fd[1]);
	print_test("9", read(fd[0], str, 11) == 11, FALSE);
	print_test("10", !memcmp(str, "-2147483648", 11), TRUE);
	close(fd[0]);
	close(fd[1]);
}

void	test_put(void)
{
	test_putchar_fd();
	test_putstr_fd();
	test_putendl_fd();
	test_putnbr_fd();
}
