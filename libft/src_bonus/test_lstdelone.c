/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstdelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:06:12 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/17 15:05:18 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

static void	test_lstdelone_crash1(void)
{
	ft_lstdelone(NULL, &taux_delfun);
}

static void	test_lstdelone_crash2(void)
{
	t_list	*list;

	list = taux_lstnew(NULL, &malloc);
	ft_lstdelone(list, NULL);
	free(list);
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
	tlib_test_ok(tlib_alloc_lookup(l1) == 0);
	tlib_test_ok(tlib_alloc_lookup(l2) == sizeof(t_list));
	tlib_test_ok(tlib_alloc_count() == 1);
	tlib_test_ok(c[0] == 'c');
	tlib_test_ok(c[1] == 'a');
	ft_lstdelone(l2, &taux_delfun);
	tlib_test_ok(tlib_alloc_lookup(l2) == 0);
	tlib_test_ok(tlib_alloc_count() == 0);
	tlib_test_ok(c[1] == 'c');
	free(l1);
	free(l2);
	tlib_test_process(&test_lstdelone_crash1, PRESULT_OK);
	tlib_test_process(&test_lstdelone_crash2, PRESULT_OK);
	tlib_alloc_reset();
}
