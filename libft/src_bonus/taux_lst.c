/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taux_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:42:20 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/22 11:10:41 by andeviei         ###   ########.fr       */
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

void	taux_parg_init(t_parg *parg, size_t len, ...)
{
	va_list	args;
	size_t	i;

	va_start(args, len);
	if (len > 3)
		len = 3;
	parg->len = len;
	parg->i = 0;
	parg->err = FALSE;
	i = 0;
	while (i < len)
	{
		parg->p[i] = va_arg(args, void *);
		i++;
	}
	va_end(args);
}

void	taux_parg_check(t_parg *parg, void *p)
{
	size_t	i;

	parg->i++;
	if (p != NULL)
	{
		i = 0;
		while (i < parg->len)
		{
			if (p == parg->p[i])
			{
				parg->p[i] = NULL;
				return ;
			}
			i++;
		}
	}
	parg->err = TRUE;
}

t_bool	taux_parg_ok(t_parg parg)
{
	return (!parg.err);
}

void	taux_pget_init(t_pget *pget, size_t len, ...)
{
	va_list	args;
	size_t	i;

	va_start(args, len);
	if (len > 3)
		len = 3;
	pget->len = len;
	pget->i = 0;
	pget->j = 0;
	pget->err = FALSE;
	i = 0;
	while (i < len)
	{
		pget->p[i] = va_arg(args, void *);
		i++;
	}
	va_end(args);
}

void	*taux_pget_get(t_pget *pget)
{
	size_t	i;

	i = pget->i;
	pget->i++;
	if (i >= pget->len)
		return (NULL);
	return (pget->p[i]);
}

void	taux_pget_check(t_pget *pget, void *p)
{
	size_t	i;

	pget->j++;
	if (p != NULL)
	{
		i = 0;
		while (i < pget->len && i < pget->i)
		{
			if (p == pget->p[i])
			{
				pget->p[i] = NULL;
				return ;
			}
			i++;
		}
	}
	pget->err = TRUE;
}

t_bool	taux_pget_ok(t_pget pget)
{
	return (!pget.err && pget.i == pget.j);
}
