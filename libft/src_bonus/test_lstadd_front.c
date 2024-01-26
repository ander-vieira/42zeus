/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:09:35 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 11:47:41 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

static int	test_lstadd_front_crash1(void)
{
	t_list	*l;

	l = taux_lstnew(NULL, &libc_malloc);
	ft_lstadd_front(NULL, l);
	libc_free(l);
	return (0);
}

static int	test_lstadd_front_crash2(void)
{
	t_list	*l;

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
	tlib_print_test(l == l1);
	tlib_print_test(l->next == NULL);
	tlib_print_test(tlib_alloc_count() == 0);
	l2 = taux_lstnew(NULL, &libc_malloc);
	ft_lstadd_front(&l, l2);
	tlib_print_test(l == l2);
	tlib_print_test(l->next == l1);
	tlib_print_test(l->next->next == NULL);
	tlib_print_test(tlib_alloc_count() == 0);
	taux_lstclear(&l, &libc_free);
	tlib_print_test(tlib_run_process(&test_lstadd_front_crash1) == 0);
	tlib_print_test(tlib_run_process(&test_lstadd_front_crash2) == 0);
	tlib_alloc_reset();
}
