/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:32:37 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/24 19:09:00 by andeviei         ###   ########.fr       */
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
	tlib_print_test("1", ft_lstsize(l) == 3, FALSE);
	tlib_print_test("2", ft_lstsize(l->next) == 2, FALSE);
	tlib_print_test("3", ft_lstsize(l->next->next) == 1, FALSE);
	tlib_print_test("4", ft_lstsize(l->next->next->next) == 0, FALSE);
	tlib_print_test("5", tlib_alloc_count() == 0, FALSE);
	tlib_print_test("6",
		tlib_run_process(&test_lstsize_crash1, NULL) == 0, TRUE);
	taux_lstclear(&l, &libc_free);
	tlib_alloc_reset();
}
