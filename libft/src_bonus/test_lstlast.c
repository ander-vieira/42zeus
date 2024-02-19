/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstlast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:32:37 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/19 23:59:03 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

static void	test_lstlast_child1(void)
{
	t_list	*l1;
	t_list	*l2;
	t_list	*l3;

	l1 = taux_lstnew(NULL, &libc_malloc);
	l2 = taux_lstnew(NULL, &libc_malloc);
	l3 = taux_lstnew(NULL, &libc_malloc);
	l1->next = l2;
	l2->next = l3;
	tlib_alloc_reset();
	tlib_test_ok(ft_lstlast(l1) == l3);
	tlib_test_ok(ft_lstlast(l2) == l3);
	tlib_test_ok(ft_lstlast(l3) == l3);
	tlib_test_ok(tlib_alloc_count() == 0);
	libc_free(l1);
	libc_free(l2);
	libc_free(l3);
}

static void	test_lstlast_child2(void)
{
	tlib_test_ok(ft_lstlast(NULL) == NULL);
}

void	test_lstlast(void)
{
	tlib_test_process(&test_lstlast_child1, PRESULT_OK);
	tlib_test_process(&test_lstlast_child2, PRESULT_OK);
}
