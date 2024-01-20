/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:49:33 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/20 13:11:03 by andeviei         ###   ########.fr       */
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

	c1 = 'a';
	c2 = 'a';
	l = taux_lstnew(&c1);
	taux_lstadd_back(&l, taux_lstnew(&c2));
	ft_lstiter(l, &iter);
	tlib_print_test("1", c1 == 'c', FALSE);
	tlib_print_test("2", c2 == 'c', TRUE);
	taux_lstclear(&l);
}

static void	test_lstmap(void)
{
	char	c1;
	char	c2;
	t_list	*l1;
	t_list	*l2;

	c1 = 'a';
	c2 = 'a';
	l1 = taux_lstnew(&c1);
	taux_lstadd_back(&l1, taux_lstnew(&c2));
	l2 = ft_lstmap(l1, &map, &iter);
	tlib_print_test("1", l2->content == &c1, FALSE);
	tlib_print_test("2", c1 == 'a', FALSE);
	tlib_print_test("3", l2->next->content == &c2, FALSE);
	tlib_print_test("4", c2 == 'a', TRUE);
	taux_lstclear(&l1);
	taux_lstclear(&l2);
}

void	test_bonus3(void)
{
	tlib_print_missing(&test_lstiter, &ft_lstiter, "lstiter");
	tlib_print_missing(&test_lstmap, &ft_lstmap, "lstmap");
}
