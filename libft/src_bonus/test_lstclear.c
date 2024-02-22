/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:42:55 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/22 11:01:01 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

static t_parg	g_parg;

static void	test_lstclear_del(void *p)
{
	taux_parg_check(&g_parg, p);
}

static void	test_lstclear_child1(void)
{
	t_list	*l;
	t_list	*l1;
	t_list	*l2;

	tlib_alloc_reset();
	taux_parg_init(&g_parg, 2, &l1, &l2);
	l1 = taux_lstnew(&l1);
	l2 = taux_lstnew(&l2);
	l = l1;
	l->next = l2;
	ft_lstclear(&l, &test_lstclear_del);
	tlib_test_ok(l == NULL);
	tlib_test_ok(taux_parg_ok(g_parg));
	tlib_test_ok(g_parg.i == 2);
	tlib_test_ok(tlib_alloc_lookup(l1) == 0);
	tlib_test_ok(tlib_alloc_lookup(l2) == 0);
	tlib_test_ok(tlib_alloc_count() == 0);
	free(l1);
	free(l2);
}

static void	test_lstclear_child2(void)
{
	t_list	*l;

	tlib_alloc_reset();
	taux_parg_init(&g_parg, 0);
	l = NULL;
	ft_lstclear(&l, &test_lstclear_del);
	tlib_test_ok(l == NULL);
	tlib_test_ok(g_parg.i == 0);
	tlib_test_ok(tlib_alloc_count() == 0);
}

static void	test_lstclear_child3(void)
{
	tlib_alloc_reset();
	taux_parg_init(&g_parg, 0);
	ft_lstclear(NULL, &test_lstclear_del);
	tlib_test_ok(g_parg.i == 0);
	tlib_test_ok(tlib_alloc_count() == 0);
}

static void	test_lstclear_child4(void)
{
	t_list	*l;
	t_list	*l1;

	tlib_alloc_reset();
	l1 = taux_lstnew(NULL);
	l = l1;
	ft_lstclear(&l, NULL);
	tlib_test_ok(l == l1 && l->next == NULL);
	tlib_test_ok(tlib_alloc_lookup(l1) == sizeof(t_list));
	tlib_test_ok(tlib_alloc_count() == 1);
	free(l1);
}

void	test_lstclear(void)
{
	tlib_test_process(&test_lstclear_child1, PRESULT_OK);
	tlib_test_process(&test_lstclear_child2, PRESULT_OK);
	tlib_test_process(&test_lstclear_child3, PRESULT_OK);
	tlib_test_process(&test_lstclear_child4, PRESULT_OK);
}
