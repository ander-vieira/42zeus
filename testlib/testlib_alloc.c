/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlib_alloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:37:23 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/19 17:32:50 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testlib.h"

void	tlib_alloc_add(void *addr, size_t size, void *(*old_malloc)(size_t))
{
	t_alloc	**list;

	list = tlib_var_alloclist();
	while (*list != NULL)
		list = &((*list)->next);
	*list = (t_alloc *)old_malloc(sizeof(t_alloc));
	if (*list == NULL)
		return ;
	(*list)->addr = addr;
	(*list)->size = size;
	(*list)->next = NULL;
}

t_bool	tlib_alloc_delete(void *addr, void (*old_free)(void *))
{
	t_alloc	**list;
	t_alloc	*current;

	list = tlib_var_alloclist();
	while ((*list)->addr != addr)
	{
		if (*list == NULL)
			return (FALSE);
		list = &((*list)->next);
	}
	current = *list;
	*list = current->next;
	old_free(current);
	return (TRUE);
}

void	tlib_alloc_print(void)
{
	t_alloc	**list;

	list = tlib_var_alloclist();
	while (*list != NULL)
	{
		printf("%p: %zu bytes\n", (*list)->addr, (*list)->size);
		list = &((*list)->next);
	}
}

void	tlib_alloc_reset(void)
{
	t_alloc	**list;
	t_alloc	*current;

	list = tlib_var_alloclist();
	while (*list != NULL)
	{
		current = *list;
		list = &((*list)->next);
		free(current);
	}
	*tlib_var_alloclist() = NULL;
	*tlib_var_errmalloc() = 0x00;
}
