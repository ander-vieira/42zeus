/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:09:35 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/17 15:05:18 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

static void	test_lstadd_front_crash1(void)
{
	t_list	*l;

	l = taux_lstnew(NULL, &libc_malloc);
	ft_lstadd_front(NULL, l);
	libc_free(l);
}

static void	test_lstadd_front_crash2(void)
{
	t_list	*l;

	l = taux_lstnew(NULL, &libc_malloc);
	ft_lstadd_front(&l, NULL);
	libc_free(l);
}

void	test_lstadd_front(void)
{
	t_list	*l;
	t_list	*l1;
	t_list	*l2;

	l = NULL;
	l1 = taux_lstnew(NULL, &libc_malloc);
	ft_lstadd_front(&l, l1);
	tlib_test_ok(l == l1);
	tlib_test_ok(l->next == NULL);
	tlib_test_ok(tlib_alloc_count() == 0);
	l2 = taux_lstnew(NULL, &libc_malloc);
	ft_lstadd_front(&l, l2);
	tlib_test_ok(l == l2);
	tlib_test_ok(l->next == l1);
	tlib_test_ok(l->next->next == NULL);
	tlib_test_ok(tlib_alloc_count() == 0);
	taux_lstclear(&l, &libc_free);
	tlib_test_process(&test_lstadd_front_crash1, PRESULT_OK);
	tlib_test_process(&test_lstadd_front_crash2, PRESULT_OK);
	tlib_alloc_reset();
}
