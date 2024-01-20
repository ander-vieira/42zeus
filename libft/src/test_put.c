/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_put.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:05:18 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/20 19:39:25 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static void	test_putchar_fd(void)
{
	int		fd[2];

	pipe(fd);
	ft_putchar_fd('5', fd[1]);
	ft_putchar_fd(' ', fd[1]);
	ft_putchar_fd('\0', fd[1]);
	close(fd[1]);
	tlib_print_test("1", tlib_io_readtest(fd[0], 1, 1, "5"), FALSE);
	tlib_print_test("2", tlib_io_readtest(fd[0], 1, 1, " "), FALSE);
	tlib_print_test("3", tlib_io_readtest(fd[0], 1, 1, "\0"), FALSE);
	tlib_print_test("4", tlib_io_readtest(fd[0], 1, 0, NULL), FALSE);
	tlib_print_test("5", tlib_alloc_count() == 0, TRUE);
	close(fd[0]);
	tlib_alloc_reset();
}

static void	test_putstr_fd(void)
{
	int		fd[2];

	pipe(fd);
	ft_putstr_fd("HOLA MUNDO", fd[1]);
	ft_putstr_fd("PEPITO\n\n", fd[1]);
	ft_putstr_fd("", fd[1]);
	close(fd[1]);
	tlib_print_test("1", tlib_io_readtest(fd[0], 10, 10, "HOLA MUNDO"), FALSE);
	tlib_print_test("2", tlib_io_readtest(fd[0], 8, 8, "PEPITO\n\n"), FALSE);
	tlib_print_test("3", tlib_io_readtest(fd[0], 1, 0, NULL), FALSE);
	tlib_print_test("4", tlib_alloc_count() == 0, TRUE);
	close(fd[0]);
	tlib_alloc_reset();
}

static void	test_putendl_fd(void)
{
	int		fd[2];

	pipe(fd);
	ft_putendl_fd("HO MUN", fd[1]);
	ft_putendl_fd("PE AAA", fd[1]);
	ft_putendl_fd("", fd[1]);
	close(fd[1]);
	tlib_print_test("1", tlib_io_readtest(fd[0], 7, 7, "HO MUN\n"), FALSE);
	tlib_print_test("2", tlib_io_readtest(fd[0], 7, 7, "PE AAA\n"), FALSE);
	tlib_print_test("3", tlib_io_readtest(fd[0], 1, 1, "\n"), FALSE);
	tlib_print_test("4", tlib_io_readtest(fd[0], 1, 0, NULL), FALSE);
	tlib_print_test("5", tlib_alloc_count() == 0, TRUE);
	close(fd[0]);
	tlib_alloc_reset();
}

static void	test_putnbr_fd(void)
{
	int		fd[2];

	pipe(fd);
	ft_putnbr_fd(53, fd[1]);
	ft_putnbr_fd(0, fd[1]);
	ft_putnbr_fd(-42, fd[1]);
	ft_putnbr_fd(2147483647, fd[1]);
	ft_putnbr_fd(-2147483648, fd[1]);
	close(fd[1]);
	tlib_print_test("1", tlib_io_readtest(fd[0], 2, 2, "53"), FALSE);
	tlib_print_test("2", tlib_io_readtest(fd[0], 1, 1, "0"), FALSE);
	tlib_print_test("3", tlib_io_readtest(fd[0], 3, 3, "-42"), FALSE);
	tlib_print_test("4", tlib_io_readtest(fd[0], 10, 10, "2147483647"), FALSE);
	tlib_print_test("5", tlib_io_readtest(fd[0], 11, 11, "-2147483648"), FALSE);
	tlib_print_test("6", tlib_alloc_count() == 0, TRUE);
	close(fd[0]);
	tlib_alloc_reset();
}

void	test_put(void)
{
	tlib_print_missing(&test_putchar_fd, &ft_putchar_fd, "putchar_fd");
	tlib_print_missing(&test_putstr_fd, &ft_putstr_fd, "putstr_fd");
	tlib_print_missing(&test_putendl_fd, &ft_putendl_fd, "putendl_fd");
	tlib_print_missing(&test_putnbr_fd, &ft_putnbr_fd, "putnbr_fd");
}
