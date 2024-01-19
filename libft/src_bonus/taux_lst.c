/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taux_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:42:20 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/19 13:13:02 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

t_list	*taux_lstnew(void *content)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

void	taux_lstadd_back(t_list **lst, t_list *n)
{
	t_list	*current;

	if (lst != NULL)
	{
		current = *lst;
		while (current->next != NULL)
			current = current->next;
		current->next = n;
	}
}
