/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:49:33 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 12:25:33 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

static int	test_lstmap_crash1(void)
{
	int	status;

	status = 0;
	return (status);
}

void	test_lstmap(void)
{
	char	c[10];
	t_list	*l1;
	t_list	*l2;

	memset(c, 'a', 10);
	l1 = taux_lstnew(c, &libc_malloc);
	taux_lstadd_back(&l1, taux_lstnew(c + 2, &libc_malloc));
	l2 = ft_lstmap(l1, &taux_mapfun, &taux_delfun);
	tlib_test_ok(l2 != NULL);
	tlib_test_ok(tlib_alloc_lookup(l2) == sizeof(t_list));
	tlib_test_ok(l2->content == c + 1);
	tlib_test_ok(l2->next != NULL);
	tlib_test_ok(tlib_alloc_lookup(l2->next) == sizeof(t_list));
	tlib_test_ok(l2->next->content == c + 4);
	tlib_test_ok(l2->next->next == NULL);
	tlib_test_ok(tlib_alloc_count() == 2);
	tlib_test_ok(!memcmp(c, "aaaaaaaaaa", 10));
	taux_lstclear(&l1, &libc_free);
	taux_lstclear(&l2, &free);
	tlib_test_ok(tlib_run_process(&test_lstmap_crash1) == 0);
	tlib_alloc_reset();
}
