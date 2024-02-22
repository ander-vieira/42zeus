/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstdelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:06:12 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/22 11:01:59 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

static t_parg	g_parg;

static void	test_lstdelone_del(void *p)
{
	taux_parg_check(&g_parg, p);
}

static void	test_lstdelone_child1(void)
{
	t_list	*l1;
	t_list	*l2;

	taux_parg_init(&g_parg, 1, &l1);
	tlib_alloc_reset();
	l1 = taux_lstnew(&l1);
	l2 = taux_lstnew(NULL);
	l1->next = l2;
	ft_lstdelone(l1, &test_lstdelone_del);
	tlib_test_ok(taux_parg_ok(g_parg));
	tlib_test_ok(g_parg.i == 1);
	tlib_test_ok(tlib_alloc_lookup(l1) == 0);
	tlib_test_ok(tlib_alloc_lookup(l2) == sizeof(t_list));
	tlib_test_ok(tlib_alloc_count() == 1);
	free(l1);
	free(l2);
}

static void	test_lstdelone_child2(void)
{
	t_list	*l;

	tlib_alloc_reset();
	l = taux_lstnew(NULL);
	ft_lstdelone(l, NULL);
	tlib_test_ok(tlib_alloc_lookup(l) == sizeof(t_list));
	tlib_test_ok(tlib_alloc_count() == 1);
	free(l);
}

static void	test_lstdelone_child3(void)
{
	tlib_alloc_reset();
	taux_parg_init(&g_parg, 0);
	ft_lstdelone(NULL, &test_lstdelone_del);
	tlib_test_ok(g_parg.i == 0);
	tlib_test_ok(tlib_alloc_count() == 0);
}

void	test_lstdelone(void)
{
	tlib_test_process(&test_lstdelone_child1, PRESULT_OK);
	tlib_test_process(&test_lstdelone_child2, PRESULT_OK);
	tlib_test_process(&test_lstdelone_child3, PRESULT_OK);
}
