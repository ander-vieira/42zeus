/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:20:43 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/24 19:09:07 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_BONUS_H
# define TEST_BONUS_H

# include <unistd.h>
# include <string.h>

# include "../../testlib/testlib.h"

/* ************************************************************************** */
/* Fake definition to get VSCode dependency detection working                */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

/* ************************************************************************** */
/* Weak declarations to check for missing functions                           */

# pragma weak ft_lstnew
# pragma weak ft_lstadd_front
# pragma weak ft_lstadd_back
# pragma weak ft_lstlast
# pragma weak ft_lstsize
# pragma weak ft_lstdelone
# pragma weak ft_lstclear
# pragma weak ft_lstiter
# pragma weak ft_lstmap

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *n);
void	ft_lstadd_back(t_list **lst, t_list *n);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*fun)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*fun)(void *), void (*del)(void *));

/* ************************************************************************** */
/* Utility unctions for testing lists                                         */

t_list	*taux_lstnew(void *content, void *(*f_malloc)(size_t));
void	taux_lstadd_back(t_list **list, t_list *n);
void	taux_lstclear(t_list **list, void (*f_free)(void *));

void	taux_delfun(void *content);
void	taux_iterfun(void *content);
void	*taux_mapfun(void *content);

/* ************************************************************************** */
/* Test functions                                                             */

void	test_lstnew(void);
void	test_lstadd_front(void);
void	test_lstsize(void);
void	test_lstlast(void);
void	test_lstadd_back(void);
void	test_lstdelone(void);
void	test_lstclear(void);
void	test_lstiter(void);
void	test_lstmap(void);

#endif