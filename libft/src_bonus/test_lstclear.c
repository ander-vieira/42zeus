/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:42:55 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 09:39:49 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

static int	test_lstclear_crash1(void *ctx)
{
	(void)ctx;
	ft_lstclear(NULL, &taux_delfun);
	return (0);
}

static int	test_lstclear_crash2(void *ctx)
{
	t_list	*list;

	(void)ctx;
	list = NULL;
	ft_lstclear(&list, &taux_delfun);
	return (0);
}

static int	test_lstclear_crash3(void *ctx)
{
	t_list	*l;
	t_list	*l1;

	(void)ctx;
	l1 = taux_lstnew(NULL, &malloc);
	l = l1;
	ft_lstclear(&l, NULL);
	free(l1);
	return (0);
}

void	test_lstclear(void)
{
	char	c[2];
	t_list	*l;
	t_list	*l1;
	t_list	*l2;

	memset(c, 'a', 2);
	l1 = taux_lstnew(c, &malloc);
	l2 = taux_lstnew(c + 1, &malloc);
	l = l1;
	taux_lstadd_back(&l1, l2);
	ft_lstclear(&l, &taux_delfun);
	tlib_print_test(l == NULL);
	tlib_print_test(tlib_alloc_lookup(l1) == 0);
	tlib_print_test(tlib_alloc_lookup(l2) == 0);
	tlib_print_test(tlib_alloc_count() == 0);
	tlib_print_test(!memcmp(c, "cc", 2));
	free(l1);
	free(l2);
	tlib_print_test(tlib_run_process(&test_lstclear_crash1, NULL) == 0);
	tlib_print_test(tlib_run_process(&test_lstclear_crash2, NULL) == 0);
	tlib_print_test(tlib_run_process(&test_lstclear_crash3, NULL) == 0);
	tlib_alloc_reset();
}
