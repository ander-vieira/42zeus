/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:42:55 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/20 13:10:42 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

static void	test_lstsize(void)
{
	t_list	*l;

	l = taux_lstnew(NULL);
	taux_lstadd_back(&l, taux_lstnew(NULL));
	taux_lstadd_back(&l, taux_lstnew(NULL));
	tlib_print_test("1", ft_lstsize(l) == 3, FALSE);
	tlib_print_test("2", ft_lstsize(l->next) == 2, FALSE);
	tlib_print_test("3", ft_lstsize(l->next->next) == 1, FALSE);
	tlib_print_test("4", ft_lstsize(l->next->next->next) == 0, FALSE);
	tlib_print_test("5", ft_lstsize(NULL) == 0, TRUE);
	taux_lstclear(&l);
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
	l = taux_lstnew(&c);
	ft_lstdelone(l, &delone);
	tlib_print_test("1", c == 'c', TRUE);
}

static void	test_lstclear(void)
{
	char	c1;
	char	c2;
	t_list	*l;

	c1 = 'a';
	c2 = 'a';
	l = taux_lstnew(&c1);
	taux_lstadd_back(&l, taux_lstnew(&c2));
	ft_lstclear(&l, &delone);
	tlib_print_test("1", l == NULL, FALSE);
	tlib_print_test("2", c1 == 'c', FALSE);
	tlib_print_test("3", c2 == 'c', TRUE);
}

void	test_bonus2(void)
{
	tlib_print_missing(&test_lstsize, &ft_lstsize, "lstsize");
	tlib_print_missing(&test_lstdelone, &ft_lstdelone, "lstdelone");
	tlib_print_missing(&test_lstclear, &ft_lstclear, "lstclear");
}
