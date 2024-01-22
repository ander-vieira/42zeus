/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlib_alloc3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:53:01 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/22 15:41:55 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testlib.h"

void	tlib_alloc_setmock(size_t timer)
{
	t_amock	**list;

	if (timer == 0)
		return ;
	list = tlib_var_amocklist();
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

	list = tlib_var_amocklist();
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

	list = tlib_var_amocklist();
	while (*list != NULL)
	{
		current = *list;
		list = &((*list)->next);
		free(current);
	}
	*tlib_var_amocklist() = NULL;
}
