/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:41:49 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/22 11:11:11 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

static void	test_lstadd_back_child1(void)
{
	t_list	*l;
	t_list	*l1;

	tlib_alloc_reset();
	l1 = taux_lstnew(NULL);
	l = NULL;
	ft_lstadd_back(&l, l1);
	tlib_test_ok(l == l1 && l1->next == NULL);
	tlib_test_ok(tlib_alloc_lookup(l1) == sizeof(t_list));
	tlib_test_ok(tlib_alloc_count() == 1);
	free(l1);
}

static void	test_lstadd_back_child2(void)
{
	t_list	*l;
	t_list	*l1;
	t_list	*l2;

	tlib_alloc_reset();
	l1 = taux_lstnew(NULL);
	l2 = taux_lstnew(NULL);
	l = l1;
	ft_lstadd_back(&l, l2);
	tlib_test_ok(l == l1 && l1->next == l2 && l2->next == NULL);
	tlib_test_ok(tlib_alloc_lookup(l1) == sizeof(t_list));
	tlib_test_ok(tlib_alloc_lookup(l2) == sizeof(t_list));
	tlib_test_ok(tlib_alloc_count() == 2);
	free(l1);
	free(l2);
}

static void	test_lstadd_back_child3(void)
{
	t_list	*l;
	t_list	*l1;
	t_list	*l2;
	t_list	*l3;

	tlib_alloc_reset();
	l1 = taux_lstnew(NULL);
	l2 = taux_lstnew(NULL);
	l3 = taux_lstnew(NULL);
	l = l1;
	l->next = l2;
	ft_lstadd_back(&l, l3);
	tlib_test_ok(l == l1 && l1->next == l2
		&& l2->next == l3 && l3->next == NULL);
	tlib_test_ok(tlib_alloc_lookup(l1) == sizeof(t_list));
	tlib_test_ok(tlib_alloc_lookup(l2) == sizeof(t_list));
	tlib_test_ok(tlib_alloc_lookup(l3) == sizeof(t_list));
	tlib_test_ok(tlib_alloc_count() == 3);
	free(l1);
	free(l2);
	free(l3);
}

static void	test_lstadd_back_child4(void)
{
	t_list	*l1;

	tlib_alloc_reset();
	l1 = taux_lstnew(NULL);
	ft_lstadd_back(NULL, l1);
	tlib_test_ok(tlib_alloc_lookup(l1) == sizeof(t_list));
	tlib_test_ok(tlib_alloc_count() == 1);
	free(l1);
}

static void	test_lstadd_back_child5(void)
{
	t_list	*l;
	t_list	*l1;

	tlib_alloc_reset();
	l1 = taux_lstnew(NULL);
	l = l1;
	ft_lstadd_back(&l, NULL);
	tlib_test_ok(l == l1 && l->next == NULL);
	tlib_test_ok(tlib_alloc_lookup(l1) == sizeof(t_list));
	tlib_test_ok(tlib_alloc_count() == 1);
	free(l);
}

void	test_lstadd_back(void)
{
	tlib_test_process(&test_lstadd_back_child1, PRESULT_OK);
	tlib_test_process(&test_lstadd_back_child2, PRESULT_OK);
	tlib_test_process(&test_lstadd_back_child3, PRESULT_OK);
	tlib_test_process(&test_lstadd_back_child4, PRESULT_OK);
	tlib_test_process(&test_lstadd_back_child5, PRESULT_OK);
}
