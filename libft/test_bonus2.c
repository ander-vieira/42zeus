/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:42:55 by andeviei          #+#    #+#             */
/*   Updated: 2023/12/18 21:57:40 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

static void	delone(void *content)
{
	*((char *)content) = 'c';
}

static void	test_lstdelone(void)
{
	char	c;
	t_list	*l;

	print_title("lstdelone");
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

	print_title("lstclear");
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
	test_lstdelone();
	test_lstclear();
}
