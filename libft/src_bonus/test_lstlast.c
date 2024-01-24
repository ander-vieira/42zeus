/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstlast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:32:37 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/24 19:08:42 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

static int	test_lstlast_crash1(void *ctx)
{
	(void)ctx;
	ft_lstlast(NULL);
	return (0);
}

void	test_lstlast(void)
{
	t_list	*l;

	l = taux_lstnew(NULL, &libc_malloc);
	taux_lstadd_back(&l, taux_lstnew(NULL, &libc_malloc));
	taux_lstadd_back(&l, taux_lstnew(NULL, &libc_malloc));
	tlib_print_test("1", ft_lstlast(l) == l->next->next, FALSE);
	tlib_print_test("2", ft_lstlast(l->next) == l->next->next, FALSE);
	tlib_print_test("3", ft_lstlast(l->next->next) == l->next->next, FALSE);
	tlib_print_test("4", tlib_alloc_count() == 0, FALSE);
	tlib_print_test("5",
		tlib_run_process(&test_lstlast_crash1, NULL) == 0, TRUE);
	taux_lstclear(&l, &libc_free);
	tlib_alloc_reset();
}
