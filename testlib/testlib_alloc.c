/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlib_alloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:37:23 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 15:14:47 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testlib.h"

t_alloc	*g_allocs;
t_amock	*g_mocks;

void	tlib_alloc_add(void *addr, size_t size)
{
	t_alloc	**list;

	list = &g_allocs;
	while (*list != NULL)
		list = &((*list)->next);
	*list = (t_alloc *)libc_malloc(sizeof(t_alloc));
	if (*list == NULL)
		return ;
	(*list)->addr = addr;
	(*list)->size = size;
	(*list)->next = NULL;
}

t_bool	tlib_alloc_delete(void *addr)
{
	t_alloc	**list;
	t_alloc	*current;

	list = &g_allocs;
	while ((*list)->addr != addr)
	{
		if (*list == NULL)
			return (FALSE);
		list = &((*list)->next);
	}
	current = *list;
	*list = current->next;
	libc_free(current);
	return (TRUE);
}

void	tlib_alloc_reset(void)
{
	t_alloc	**list;
	t_alloc	*current;

	list = &g_allocs;
	while (*list != NULL)
	{
		current = *list;
		list = &((*list)->next);
		free(current);
	}
	g_allocs = NULL;
	tlib_alloc_resetmocks();
}

size_t	tlib_alloc_lookup(void *addr)
{
	t_alloc	**list;

	list = &g_allocs;
	while (*list != NULL)
	{
		if ((*list)->addr == addr)
			return ((*list)->size);
		list = &((*list)->next);
	}
	return (0);
}

size_t	tlib_alloc_count(void)
{
	t_alloc	**list;
	size_t	count;

	list = &g_allocs;
	count = 0;
	while (*list != NULL)
	{
		count += 1;
		list = &((*list)->next);
	}
	return (count);
}

void	tlib_alloc_setmock(size_t timer)
{
	t_amock	**list;

	if (timer == 0)
		return ;
	list = &g_mocks;
	while (*list != NULL)
		list = &((*list)->next);
	*list = (t_amock *)libc_malloc(sizeof(t_amock));
	if (*list == NULL)
		return ;
	(*list)->timer = timer;
	(*list)->next = NULL;
}

t_bool	tlib_alloc_tickmocks(void)
{
	t_bool	mock;
	t_amock	**list;
	t_amock	*current;

	list = &g_mocks;
	mock = FALSE;
	while (*list != NULL)
	{
		(*list)->timer -= 1;
		if ((*list)->timer == 0)
		{
			current = *list;
			*list = current->next;
			free(current);
			mock = TRUE;
		}
		else
			list = &((*list)->next);
	}
	return (mock);
}

void	tlib_alloc_resetmocks(void)
{
	t_amock	**list;
	t_amock	*current;

	list = &g_mocks;
	while (*list != NULL)
	{
		current = *list;
		list = &((*list)->next);
		free(current);
	}
	g_mocks = NULL;
}
