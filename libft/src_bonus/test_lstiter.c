/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:49:33 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/22 11:02:49 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

static t_parg	g_parg;

static void	test_lstiter_fun(void *p)
{
	taux_parg_check(&g_parg, p);
}

static void	test_lstiter_child1(void)
{
	t_list	*l1;
	t_list	*l2;

	tlib_alloc_reset();
	taux_parg_init(&g_parg, 2, &l1, &l2);
	l1 = taux_lstnew(&l1);
	l2 = taux_lstnew(&l2);
	l1->next = l2;
	ft_lstiter(l1, &test_lstiter_fun);
	tlib_test_ok(l1->next == l2 && l2->next == NULL);
	tlib_test_ok(taux_parg_ok(g_parg));
	tlib_test_ok(g_parg.i == 2);
	tlib_test_ok(tlib_alloc_lookup(l1) == sizeof(t_list));
	tlib_test_ok(tlib_alloc_lookup(l2) == sizeof(t_list));
	tlib_test_ok(tlib_alloc_count() == 2);
	free(l1);
	free(l2);
}

static void	test_lstiter_child2(void)
{
	tlib_alloc_reset();
	taux_parg_init(&g_parg, 0);
	ft_lstiter(NULL, &test_lstiter_fun);
	tlib_test_ok(g_parg.i == 0);
	tlib_test_ok(tlib_alloc_count() == 0);
}

static void	test_lstiter_child3(void)
{
	t_list	*l1;

	tlib_alloc_reset();
	l1 = taux_lstnew(NULL);
	ft_lstiter(l1, NULL);
	tlib_test_ok(l1->next == NULL);
	tlib_test_ok(tlib_alloc_lookup(l1) == sizeof(t_list));
	tlib_test_ok(tlib_alloc_count() == 1);
	free(l1);
}

void	test_lstiter(void)
{
	tlib_test_process(&test_lstiter_child1, PRESULT_OK);
	tlib_test_process(&test_lstiter_child2, PRESULT_OK);
	tlib_test_process(&test_lstiter_child3, PRESULT_OK);
}
