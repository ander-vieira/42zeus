/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:32:37 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/17 15:05:18 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

static void	test_lstsize_crash1(void)
{
	int	size;

	size = ft_lstsize(NULL);
	tlib_test_ok(size == 0);
}

void	test_lstsize(void)
{
	t_list	*l;

	l = taux_lstnew(NULL, &libc_malloc);
	taux_lstadd_back(&l, taux_lstnew(NULL, &libc_malloc));
	taux_lstadd_back(&l, taux_lstnew(NULL, &libc_malloc));
	tlib_test_ok(ft_lstsize(l) == 3);
	tlib_test_ok(ft_lstsize(l->next) == 2);
	tlib_test_ok(ft_lstsize(l->next->next) == 1);
	tlib_test_ok(ft_lstsize(l->next->next->next) == 0);
	tlib_test_ok(tlib_alloc_count() == 0);
	tlib_test_process(&test_lstsize_crash1, PRESULT_OK);
	taux_lstclear(&l, &libc_free);
	tlib_alloc_reset();
}
