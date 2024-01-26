/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:32:37 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 12:25:33 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

static int	test_lstsize_crash1(void)
{
	int	size;
	int	status;

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
	tlib_test_ok(ft_lstsize(l) == 3);
	tlib_test_ok(ft_lstsize(l->next) == 2);
	tlib_test_ok(ft_lstsize(l->next->next) == 1);
	tlib_test_ok(ft_lstsize(l->next->next->next) == 0);
	tlib_test_ok(tlib_alloc_count() == 0);
	tlib_test_ok(tlib_run_process(&test_lstsize_crash1) == 0);
	taux_lstclear(&l, &libc_free);
	tlib_alloc_reset();
}
