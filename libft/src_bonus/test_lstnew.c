/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:09:35 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/21 21:21:04 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

static void	test_lstnew_child1(void)
{
	t_list	*l;

	tlib_alloc_reset();
	l = ft_lstnew(&l);
	tlib_test_ok(l != NULL && l->content == &l && l->next == NULL);
	tlib_test_ok(tlib_alloc_lookup(l) == sizeof(t_list));
	tlib_test_ok(tlib_alloc_count() == 1);
	free(l);
}

static void	test_lstnew_child2(void)
{
	tlib_alloc_reset();
	tlib_alloc_setmock(1);
	tlib_test_ok(ft_lstnew(NULL) == NULL);
	tlib_test_ok(tlib_alloc_count() == 0);
}

void	test_lstnew(void)
{
	tlib_test_process(&test_lstnew_child1, PRESULT_OK);
	tlib_test_process(&test_lstnew_child2, PRESULT_OK);
}
