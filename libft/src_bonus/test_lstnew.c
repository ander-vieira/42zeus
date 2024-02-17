/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:09:35 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/17 15:05:18 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

static void	test_lstnew_crash1(void)
{
	t_list	*list;

	tlib_alloc_setmock(1);
	list = ft_lstnew(NULL);
	tlib_test_ok(list == NULL);
}

void	test_lstnew(void)
{
	char	c;
	t_list	*l;

	l = ft_lstnew(&c);
	tlib_test_ok(l != NULL);
	tlib_test_ok(l->content == &c);
	tlib_test_ok(l->next == NULL);
	tlib_test_ok(tlib_alloc_lookup(l) == sizeof(t_list));
	tlib_test_ok(tlib_alloc_count() == 1);
	free(l);
	tlib_test_process(&test_lstnew_crash1, PRESULT_OK);
	tlib_alloc_reset();
}
