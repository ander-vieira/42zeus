/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:42:55 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 15:09:14 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

static void	test_lstclear_crash1(void)
{
	ft_lstclear(NULL, &taux_delfun);
}

static void	test_lstclear_crash2(void)
{
	t_list	*list;

	list = NULL;
	ft_lstclear(&list, &taux_delfun);
}

static void	test_lstclear_crash3(void)
{
	t_list	*l;
	t_list	*l1;

	l1 = taux_lstnew(NULL, &malloc);
	l = l1;
	ft_lstclear(&l, NULL);
	free(l1);
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
	tlib_test_ok(l == NULL);
	tlib_test_ok(tlib_alloc_lookup(l1) == 0);
	tlib_test_ok(tlib_alloc_lookup(l2) == 0);
	tlib_test_ok(tlib_alloc_count() == 0);
	tlib_test_ok(!memcmp(c, "cc", 2));
	free(l1);
	free(l2);
	tlib_test_process(&test_lstclear_crash1, STATUS_OK);
	tlib_test_process(&test_lstclear_crash2, STATUS_OK);
	tlib_test_process(&test_lstclear_crash3, STATUS_OK);
	tlib_alloc_reset();
}
