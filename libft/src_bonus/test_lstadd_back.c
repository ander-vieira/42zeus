/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:41:49 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/20 00:04:31 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

static void	test_lstadd_back_child1(void)
{
	t_list	*l;
	t_list	*l1;

	l1 = taux_lstnew(NULL, &libc_malloc);
	l = NULL;
	tlib_alloc_reset();
	ft_lstadd_back(&l, l1);
	tlib_test_ok(l == l1);
	tlib_test_ok(tlib_alloc_count() == 0);
	libc_free(l1);
}

static void	test_lstadd_back_child2(void)
{
	t_list	*l;
	t_list	*l1;
	t_list	*l2;

	l1 = taux_lstnew(NULL, &libc_malloc);
	l2 = taux_lstnew(NULL, &libc_malloc);
	l = l1;
	tlib_alloc_reset();
	ft_lstadd_back(&l, l2);
	tlib_test_ok(l == l1 && l->next == l2);
	tlib_test_ok(tlib_alloc_count() == 0);
	libc_free(l1);
	libc_free(l2);
}

static void	test_lstadd_back_child3(void)
{
	t_list	*l;
	t_list	*l1;
	t_list	*l2;
	t_list	*l3;

	l1 = taux_lstnew(NULL, &libc_malloc);
	l2 = taux_lstnew(NULL, &libc_malloc);
	l3 = taux_lstnew(NULL, &libc_malloc);
	l = l1;
	l->next = l2;
	tlib_alloc_reset();
	ft_lstadd_back(&l, l3);
	tlib_test_ok(l == l1 && l->next == l2 && l->next->next == l3);
	tlib_test_ok(tlib_alloc_count() == 0);
	libc_free(l1);
	libc_free(l2);
	libc_free(l3);
}

static void	test_lstadd_back_child4(void)
{
	t_list	*l;

	l = taux_lstnew(NULL, &libc_malloc);
	ft_lstadd_back(NULL, l);
	libc_free(l);
}

static void	test_lstadd_back_child5(void)
{
	t_list	*l;
	t_list	*l1;

	l1 = taux_lstnew(NULL, &libc_malloc);
	l = l1;
	ft_lstadd_back(&l, NULL);
	tlib_test_ok(l == l1 && l->next == NULL);
	libc_free(l);
}

void	test_lstadd_back(void)
{
	tlib_test_process(&test_lstadd_back_child1, PRESULT_OK);
	tlib_test_process(&test_lstadd_back_child2, PRESULT_OK);
	tlib_test_process(&test_lstadd_back_child3, PRESULT_OK);
	tlib_test_process(&test_lstadd_back_child4, PRESULT_OK);
	tlib_test_process(&test_lstadd_back_child5, PRESULT_OK);
}
