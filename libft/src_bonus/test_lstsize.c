/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:32:37 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/21 21:18:02 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

static void	test_lstsize_child1(void)
{
	t_list	*l1;
	t_list	*l2;
	t_list	*l3;

	tlib_alloc_reset();
	l1 = taux_lstnew(NULL);
	l2 = taux_lstnew(NULL);
	l3 = taux_lstnew(NULL);
	l1->next = l2;
	l2->next = l3;
	tlib_test_ok(ft_lstsize(l1) == 3);
	tlib_test_ok(ft_lstsize(l2) == 2);
	tlib_test_ok(ft_lstsize(l3) == 1);
	tlib_test_ok(tlib_alloc_lookup(l1) == sizeof(t_list));
	tlib_test_ok(tlib_alloc_lookup(l2) == sizeof(t_list));
	tlib_test_ok(tlib_alloc_lookup(l3) == sizeof(t_list));
	tlib_test_ok(tlib_alloc_count() == 3);
	free(l1);
	free(l2);
	free(l3);
}

static void	test_lstsize_child2(void)
{
	tlib_test_ok(ft_lstsize(NULL) == 0);
}

void	test_lstsize(void)
{
	tlib_test_process(&test_lstsize_child1, PRESULT_OK);
	tlib_test_process(&test_lstsize_child2, PRESULT_OK);
}
