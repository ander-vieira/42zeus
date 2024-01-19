/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:25:29 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/19 13:27:46 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	*ft_calloc(size_t count, size_t size) __attribute__((weak));

static int	test_calloc_child1(void *ctx)
{
	char	*buf;

	(void)ctx;
	buf = ft_calloc(3, 2);
	if (memcmp(buf, "\0\0\0\0\0\0", 6))
		return (1);
	free(buf);
	return (0);
}

static void	test_calloc1(void)
{
	int	status;

	status = tlib_run_process(test_calloc_child1, NULL);
	tlib_print_test("1", !WIFSIGNALED(status) || WTERMSIG(status) != 11, FALSE);
	tlib_print_test("2", !WIFSIGNALED(status) || WTERMSIG(status) != 6, FALSE);
	tlib_print_test("3", WIFEXITED(status) && WEXITSTATUS(status) == 0, TRUE);
}

void	test_calloc(void)
{
	tlib_print_missing(&test_calloc1, &ft_calloc, "calloc");
}
