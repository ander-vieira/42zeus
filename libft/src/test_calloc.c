/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:25:29 by andeviei          #+#    #+#             */
/*   Updated: 2023/12/18 17:19:25 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

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

void	test_calloc(void)
{
	int	status;

	print_title("calloc");
	status = run_in_process(test_calloc_child1, NULL);
	print_test("1", !WIFSIGNALED(status) || WTERMSIG(status) != 11, FALSE);
	print_test("2", !WIFSIGNALED(status) || WTERMSIG(status) != 6, FALSE);
	print_test("3", WIFEXITED(status) && WEXITSTATUS(status) == 0, TRUE);
}
