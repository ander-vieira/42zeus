/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taux_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:42:20 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/20 13:10:02 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

t_list	*taux_lstnew(void *content)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

void	taux_lstadd_back(t_list **list, t_list *n)
{
	if (list == NULL)
		return ;
	while (*list != NULL)
		list = &((*list)->next);
	*list = n;
}

void	taux_lstclear(t_list **list)
{
	t_list	*current;
	t_list	*next;

	if (list == NULL)
		return ;
	next = *list;
	*list = NULL;
	while (next != NULL)
	{
		current = next;
		next = current->next;
		free(current);
	}
}
