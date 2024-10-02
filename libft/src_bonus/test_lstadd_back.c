/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:41:49 by andeviei          #+#    #+#             */
/*   Updated: 2024/10/02 23:46:19 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

static void	test_lstadd_back_child1(void)
{
	t_list	*l;
	t_list	*l1;

	tlib_mockmalloc_reset();
	l1 = taux_lstnew(NULL);
	l = NULL;
	ft_lstadd_back(&l, l1);
	tlib_testresult_bool(l == l1 && l1->next == NULL);
	tlib_testmalloc_size(l1, sizeof(t_list));
	tlib_testmalloc_count(1);
	free(l1);
}

static void	test_lstadd_back_child2(void)
{
	t_list	*l;
	t_list	*l1;
	t_list	*l2;

	tlib_mockmalloc_reset();
	l1 = taux_lstnew(NULL);
	l2 = taux_lstnew(NULL);
	l = l1;
	ft_lstadd_back(&l, l2);
	tlib_testresult_bool(l == l1 && l1->next == l2 && l2->next == NULL);
	tlib_testmalloc_size(l1, sizeof(t_list));
	tlib_testmalloc_size(l2, sizeof(t_list));
	tlib_testmalloc_count(2);
	free(l1);
	free(l2);
}

static void	test_lstadd_back_child3(void)
{
	t_list	*l;
	t_list	*l1;
	t_list	*l2;
	t_list	*l3;

	tlib_mockmalloc_reset();
	l1 = taux_lstnew(NULL);
	l2 = taux_lstnew(NULL);
	l3 = taux_lstnew(NULL);
	l = l1;
	l->next = l2;
	ft_lstadd_back(&l, l3);
	tlib_testresult_bool(l == l1 && l1->next == l2
		&& l2->next == l3 && l3->next == NULL);
	tlib_testmalloc_size(l1, sizeof(t_list));
	tlib_testmalloc_size(l2, sizeof(t_list));
	tlib_testmalloc_size(l3, sizeof(t_list));
	tlib_testmalloc_count(3);
	free(l1);
	free(l2);
	free(l3);
}

static void	test_lstadd_back_child4(void)
{
	t_list	*l1;

	tlib_mockmalloc_reset();
	l1 = taux_lstnew(NULL);
	ft_lstadd_back(NULL, l1);
	tlib_testmalloc_size(l1, sizeof(t_list));
	tlib_testmalloc_count(1);
	free(l1);
}

static void	test_lstadd_back_child5(void)
{
	t_list	*l;
	t_list	*l1;

	tlib_mockmalloc_reset();
	l1 = taux_lstnew(NULL);
	l = l1;
	ft_lstadd_back(&l, NULL);
	tlib_testresult_bool(l == l1 && l->next == NULL);
	tlib_testmalloc_size(l1, sizeof(t_list));
	tlib_testmalloc_count(1);
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
