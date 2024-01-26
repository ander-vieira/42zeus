/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:41:49 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 15:09:14 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

static void	test_lstadd_back_crash1(void)
{
	t_list	*l;

	l = taux_lstnew(NULL, &libc_malloc);
	ft_lstadd_back(NULL, l);
	libc_free(l);
}

static void	test_lstadd_back_crash2(void)
{
	t_list	*l;

	l = taux_lstnew(NULL, &libc_malloc);
	ft_lstadd_back(&l, NULL);
	libc_free(l);
}

void	test_lstadd_back(void)
{
	t_list	*l;
	t_list	*l1;
	t_list	*l2;

	l = NULL;
	l1 = taux_lstnew(NULL, &libc_malloc);
	ft_lstadd_back(&l, l1);
	tlib_test_ok(l == l1);
	tlib_test_ok(l->next == NULL);
	l2 = taux_lstnew(NULL, &libc_malloc);
	ft_lstadd_back(&l, l2);
	tlib_test_ok(l == l1);
	tlib_test_ok(l->next == l2);
	tlib_test_ok(l->next->next == NULL);
	tlib_test_ok(tlib_alloc_count() == 0);
	taux_lstclear(&l, &libc_free);
	tlib_test_process(&test_lstadd_back_crash1, STATUS_OK);
	tlib_test_process(&test_lstadd_back_crash2, STATUS_OK);
	tlib_alloc_reset();
}
