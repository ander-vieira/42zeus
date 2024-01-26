/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:41:49 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 09:39:49 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

static int	test_lstadd_back_crash1(void *ctx)
{
	t_list	*l;

	(void)ctx;
	l = taux_lstnew(NULL, &libc_malloc);
	ft_lstadd_back(NULL, l);
	libc_free(l);
	return (0);
}

static int	test_lstadd_back_crash2(void *ctx)
{
	t_list	*l;

	(void)ctx;
	l = taux_lstnew(NULL, &libc_malloc);
	ft_lstadd_back(&l, NULL);
	libc_free(l);
	return (0);
}

void	test_lstadd_back(void)
{
	t_list	*l;
	t_list	*l1;
	t_list	*l2;

	l = NULL;
	l1 = taux_lstnew(NULL, &libc_malloc);
	ft_lstadd_back(&l, l1);
	tlib_print_test(l == l1);
	tlib_print_test(l->next == NULL);
	l2 = taux_lstnew(NULL, &libc_malloc);
	ft_lstadd_back(&l, l2);
	tlib_print_test(l == l1);
	tlib_print_test(l->next == l2);
	tlib_print_test(l->next->next == NULL);
	tlib_print_test(tlib_alloc_count() == 0);
	taux_lstclear(&l, &libc_free);
	tlib_print_test(tlib_run_process(&test_lstadd_back_crash1, NULL) == 0);
	tlib_print_test(tlib_run_process(&test_lstadd_back_crash2, NULL) == 0);
	tlib_alloc_reset();
}
