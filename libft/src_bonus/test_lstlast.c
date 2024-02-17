/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstlast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:32:37 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/17 15:05:18 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

static void	test_lstlast_crash1(void)
{
	ft_lstlast(NULL);
}

void	test_lstlast(void)
{
	t_list	*l;

	l = taux_lstnew(NULL, &libc_malloc);
	taux_lstadd_back(&l, taux_lstnew(NULL, &libc_malloc));
	taux_lstadd_back(&l, taux_lstnew(NULL, &libc_malloc));
	tlib_test_ok(ft_lstlast(l) == l->next->next);
	tlib_test_ok(ft_lstlast(l->next) == l->next->next);
	tlib_test_ok(ft_lstlast(l->next->next) == l->next->next);
	tlib_test_ok(tlib_alloc_count() == 0);
	tlib_test_process(&test_lstlast_crash1, PRESULT_OK);
	taux_lstclear(&l, &libc_free);
	tlib_alloc_reset();
}
