/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:09:35 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/24 19:08:15 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

static int	test_lstadd_front_crash1(void *ctx)
{
	t_list	*l;

	(void)ctx;
	l = taux_lstnew(NULL, &libc_malloc);
	ft_lstadd_front(NULL, l);
	libc_free(l);
	return (0);
}

static int	test_lstadd_front_crash2(void *ctx)
{
	t_list	*l;

	(void)ctx;
	l = taux_lstnew(NULL, &libc_malloc);
	ft_lstadd_front(&l, NULL);
	libc_free(l);
	return (0);
}

void	test_lstadd_front(void)
{
	t_list	*l;
	t_list	*l1;
	t_list	*l2;

	l = NULL;
	l1 = taux_lstnew(NULL, &libc_malloc);
	ft_lstadd_front(&l, l1);
	tlib_print_test("1", l == l1, FALSE);
	tlib_print_test("2", l->next == NULL, FALSE);
	tlib_print_test("3", tlib_alloc_count() == 0, FALSE);
	l2 = taux_lstnew(NULL, &libc_malloc);
	ft_lstadd_front(&l, l2);
	tlib_print_test("4", l == l2, FALSE);
	tlib_print_test("5", l->next == l1, FALSE);
	tlib_print_test("6", l->next->next == NULL, FALSE);
	tlib_print_test("7", tlib_alloc_count() == 0, FALSE);
	taux_lstclear(&l, &libc_free);
	tlib_print_test("8",
		tlib_run_process(&test_lstadd_front_crash1, NULL) == 0, FALSE);
	tlib_print_test("9",
		tlib_run_process(&test_lstadd_front_crash2, NULL) == 0, TRUE);
	tlib_alloc_reset();
}
