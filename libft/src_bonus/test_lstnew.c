/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:09:35 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 12:25:33 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

static int	test_lstnew_crash1(void)
{
	t_list	*list;
	int		status;

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
	tlib_test_ok(l != NULL);
	tlib_test_ok(l->content == &c);
	tlib_test_ok(l->next == NULL);
	tlib_test_ok(tlib_alloc_lookup(l) == sizeof(t_list));
	tlib_test_ok(tlib_alloc_count() == 1);
	free(l);
	tlib_test_ok(tlib_run_process(&test_lstnew_crash1) == 0);
	tlib_alloc_reset();
}
