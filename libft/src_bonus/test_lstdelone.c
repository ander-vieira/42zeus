/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstdelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:06:12 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/20 11:00:20 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

static void		*g_p;
static t_uint	g_i;

static void	test_lstdelone_del1(void *p)
{
	tlib_test_ok(p == g_p);
	g_i++;
}

static void	test_lstdelone_del2(void *p)
{
	(void)p;
}

static void	test_lstdelone_child1(void)
{
	t_list	*l1;
	t_list	*l2;

	g_p = &l1;
	g_i = 0;
	tlib_alloc_reset();
	l1 = taux_lstnew(g_p, &malloc);
	l2 = taux_lstnew(NULL, &malloc);
	l1->next = l2;
	ft_lstdelone(l1, &test_lstdelone_del1);
	tlib_test_ok(g_i == 1);
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
	l = taux_lstnew(NULL, &malloc);
	ft_lstdelone(l, NULL);
	tlib_test_ok(tlib_alloc_lookup(l) == sizeof(t_list));
	tlib_test_ok(tlib_alloc_count() == 1);
	free(l);
}

static void	test_lstdelone_child3(void)
{
	ft_lstdelone(NULL, &test_lstdelone_del2);
}

void	test_lstdelone(void)
{
	tlib_test_process(&test_lstdelone_child1, PRESULT_OK);
	tlib_test_process(&test_lstdelone_child2, PRESULT_OK);
	tlib_test_process(&test_lstdelone_child3, PRESULT_OK);
}
