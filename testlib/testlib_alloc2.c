/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlib_alloc2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:12:58 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/20 18:37:23 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testlib.h"

size_t	tlib_alloc_lookup(void *addr)
{
	t_alloc	**list;

	list = tlib_var_alloclist();
	while ((*list)->addr != addr)
	{
		if (*list == NULL)
			return (0);
		list = &((*list)->next);
	}
	return ((*list)->size);
}

size_t	tlib_alloc_count(void)
{
	t_alloc	**list;
	size_t	count;

	list = tlib_var_alloclist();
	count = 0;
	while (*list != NULL)
	{
		count += 1;
		list = &((*list)->next);
	}
	return (count);
}

t_byte	tlib_alloc_errors(void)
{
	return (*tlib_var_errmalloc());
}
