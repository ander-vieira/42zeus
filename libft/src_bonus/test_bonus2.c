/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:42:55 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/17 17:05:30 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

int		ft_lstsize(t_list *lst) __attribute__((weak));
void	ft_lstdelone(t_list *lst, void (*del)(void *)) __attribute__((weak));
void	ft_lstclear(t_list **lst, void (*del)(void *)) __attribute__((weak));

static void	test_lstsize(void)
{
	t_list	*l;

	l = ft_lstnew(NULL);
	ft_lstadd_back(&l, ft_lstnew(NULL));
	ft_lstadd_back(&l, ft_lstnew(NULL));
	print_test("1", ft_lstsize(l) == 3, FALSE);
	print_test("2", ft_lstsize(l->next) == 2, FALSE);
	print_test("3", ft_lstsize(l->next->next) == 1, FALSE);
	print_test("4", ft_lstsize(l->next->next->next) == 0, FALSE);
	print_test("5", ft_lstsize(NULL) == 0, TRUE);
}

static void	delone(void *content)
{
	*((char *)content) = 'c';
}

static void	test_lstdelone(void)
{
	char	c;
	t_list	*l;

	c = 'a';
	l = ft_lstnew(&c);
	ft_lstdelone(l, &delone);
	print_test("1", c == 'c', TRUE);
}

static void	test_lstclear(void)
{
	char	c1;
	char	c2;
	t_list	*l;

	c1 = 'a';
	c2 = 'a';
	l = ft_lstnew(&c1);
	ft_lstadd_back(&l, ft_lstnew(&c2));
	ft_lstclear(&l, &delone);
	print_test("1", l == NULL, FALSE);
	print_test("2", c1 == 'c', FALSE);
	print_test("3", c2 == 'c', TRUE);
}

void	test_bonus2(void)
{
	test_if_exists(&test_lstsize, &ft_lstsize, "lstsize");
	test_if_exists(&test_lstdelone, &ft_lstdelone, "lstdelone");
	test_if_exists(&test_lstclear, &ft_lstclear, "lstclear");
}
