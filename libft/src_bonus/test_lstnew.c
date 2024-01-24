/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:09:35 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/24 19:08:07 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

static int	test_lstnew_crash1(void *ctx)
{
	t_list	*list;
	int		status;

	(void)ctx;
	tlib_alloc_setmock(1);
	list = ft_lstnew(NULL);
	if (list == NULL)
		status = 0;
	else
		status = 1;
	free(list);
	return (status);
}

void	test_lstnew(void)
{
	char	c;
	t_list	*l;

	l = ft_lstnew(&c);
	tlib_print_test("1", l != NULL, FALSE);
	tlib_print_test("2", l->content == &c, FALSE);
	tlib_print_test("3", l->next == NULL, FALSE);
	tlib_print_test("4", tlib_alloc_lookup(l) == sizeof(t_list), FALSE);
	tlib_print_test("5", tlib_alloc_count() == 1, FALSE);
	free(l);
	tlib_print_test("6",
		tlib_run_process(&test_lstnew_crash1, NULL) == 0, TRUE);
	tlib_alloc_reset();
}
