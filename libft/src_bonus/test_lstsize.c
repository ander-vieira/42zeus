/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:32:37 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 09:39:49 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

static int	test_lstsize_crash1(void *ctx)
{
	int	size;
	int	status;

	(void)ctx;
	size = ft_lstsize(NULL);
	if (size == 0)
		status = 0;
	else
		status = 1;
	return (status);
}

void	test_lstsize(void)
{
	t_list	*l;

	l = taux_lstnew(NULL, &libc_malloc);
	taux_lstadd_back(&l, taux_lstnew(NULL, &libc_malloc));
	taux_lstadd_back(&l, taux_lstnew(NULL, &libc_malloc));
	tlib_print_test(ft_lstsize(l) == 3);
	tlib_print_test(ft_lstsize(l->next) == 2);
	tlib_print_test(ft_lstsize(l->next->next) == 1);
	tlib_print_test(ft_lstsize(l->next->next->next) == 0);
	tlib_print_test(tlib_alloc_count() == 0);
	tlib_print_test(tlib_run_process(&test_lstsize_crash1, NULL) == 0);
	taux_lstclear(&l, &libc_free);
	tlib_alloc_reset();
}
