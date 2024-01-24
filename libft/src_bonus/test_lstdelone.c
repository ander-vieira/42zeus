/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstdelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:06:12 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/24 18:51:15 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

static int	test_lstdelone_crash1(void *ctx)
{
	(void)ctx;
	ft_lstdelone(NULL, &taux_delfun);
	return (0);
}

static int	test_lstdelone_crash2(void *ctx)
{
	t_list	*list;

	(void)ctx;
	list = taux_lstnew(NULL, &malloc);
	ft_lstdelone(list, NULL);
	free(list);
	return (0);
}

void	test_lstdelone(void)
{
	char	c[2];
	t_list	*l1;
	t_list	*l2;

	memset(c, 'a', 2);
	l1 = taux_lstnew(c, &malloc);
	l2 = taux_lstnew(c + 1, &malloc);
	taux_lstadd_back(&l1, l2);
	ft_lstdelone(l1, &taux_delfun);
	tlib_print_test("1", tlib_alloc_lookup(l1) == 0, FALSE);
	tlib_print_test("2", tlib_alloc_lookup(l2) == sizeof(t_list), FALSE);
	tlib_print_test("3", tlib_alloc_count() == 1, FALSE);
	tlib_print_test("4", c[0] == 'c', FALSE);
	tlib_print_test("5", c[1] == 'a', FALSE);
	ft_lstdelone(l2, &taux_delfun);
	tlib_print_test("6", tlib_alloc_lookup(l2) == 0, FALSE);
	tlib_print_test("7", tlib_alloc_count() == 0, FALSE);
	tlib_print_test("8", c[1] == 'c', FALSE);
	free(l1);
	free(l2);
	tlib_print_test("9",
		tlib_run_process(&test_lstdelone_crash1, NULL) == 0, FALSE);
	tlib_print_test("10",
		tlib_run_process(&test_lstdelone_crash2, NULL) == 0, TRUE);
	tlib_alloc_reset();
}
