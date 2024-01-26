/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:49:33 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 12:25:33 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

void	test_lstiter(void)
{
	char	c[2];
	t_list	*l;

	memset(c, 'a', 2);
	l = taux_lstnew(c, &libc_malloc);
	taux_lstadd_back(&l, taux_lstnew(c + 1, &libc_malloc));
	ft_lstiter(l, &taux_iterfun);
	tlib_test_ok(!memcmp(c, "ii", 2));
	tlib_test_ok(tlib_alloc_count() == 0);
	taux_lstclear(&l, &libc_free);
	tlib_alloc_reset();
}
