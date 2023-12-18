/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:49:33 by andeviei          #+#    #+#             */
/*   Updated: 2023/12/18 21:58:01 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

static void	iter(void *content)
{
	*((char *)content) = 'c';
}

static void	*map(void *content)
{
	return (content);
}

static void	test_lstiter(void)
{
	char	c1;
	char	c2;
	t_list	*l;

	print_title("lstiter");
	c1 = 'a';
	c2 = 'a';
	l = ft_lstnew(&c1);
	ft_lstadd_back(&l, ft_lstnew(&c2));
	ft_lstiter(l, &iter);
	print_test("1", c1 == 'c', FALSE);
	print_test("2", c2 == 'c', TRUE);
	free(l->next);
	free(l);
}

static void	test_lstmap(void)
{
	char	c1;
	char	c2;
	t_list	*l1;
	t_list	*l2;

	print_title("lstmap");
	c1 = 'a';
	c2 = 'a';
	l1 = ft_lstnew(&c1);
	ft_lstadd_back(&l1, ft_lstnew(&c2));
	l2 = ft_lstmap(l1, &map, &iter);
	print_test("1", l2->content == &c1, FALSE);
	print_test("2", c1 == 'a', FALSE);
	print_test("3", l2->next->content == &c2, FALSE);
	print_test("4", c2 == 'a', TRUE);
	free(l1->next);
	free(l1);
	free(l2->next);
	free(l2);
}

void	test_bonus3(void)
{
	test_lstiter();
	test_lstmap();
}
