/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:09:35 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/19 23:56:00 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

static void	test_lstadd_front_child1(void)
{
	t_list	*l;
	t_list	*l1;

	l1 = taux_lstnew(NULL, &libc_malloc);
	l = NULL;
	tlib_alloc_reset();
	ft_lstadd_front(&l, l1);
	tlib_test_ok(l == l1 && l->next == NULL);
	tlib_test_ok(tlib_alloc_count() == 0);
	libc_free(l1);
}

static void	test_lstadd_front_child2(void)
{
	t_list	*l;
	t_list	*l1;
	t_list	*l2;

	tlib_alloc_reset();
	l1 = taux_lstnew(NULL, &libc_malloc);
	l2 = taux_lstnew(NULL, &libc_malloc);
	l = l1;
	ft_lstadd_front(&l, l2);
	tlib_test_ok(l == l2 && l->next == l1 && l->next->next == NULL);
	tlib_test_ok(tlib_alloc_count() == 0);
	libc_free(l1);
	libc_free(l2);
}

static void	test_lstadd_front_child3(void)
{
	t_list	*l;

	l = taux_lstnew(NULL, &libc_malloc);
	ft_lstadd_front(NULL, l);
	libc_free(l);
}

static void	test_lstadd_front_child4(void)
{
	t_list	*l;
	t_list	*l1;

	l1 = taux_lstnew(NULL, &libc_malloc);
	l = l1;
	ft_lstadd_front(&l, NULL);
	tlib_test_ok(l == l1 && l->next == NULL);
	libc_free(l1);
}

void	test_lstadd_front(void)
{
	tlib_test_process(&test_lstadd_front_child1, PRESULT_OK);
	tlib_test_process(&test_lstadd_front_child2, PRESULT_OK);
	tlib_test_process(&test_lstadd_front_child3, PRESULT_OK);
	tlib_test_process(&test_lstadd_front_child4, PRESULT_OK);
}
