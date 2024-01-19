/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:56:26 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/19 13:16:23 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

t_list	*ft_lstnew(void *content) __attribute__((weak));
void	ft_lstadd_front(t_list **lst, t_list *n) __attribute__((weak));
void	ft_lstadd_back(t_list **lst, t_list *n) __attribute__((weak));
t_list	*ft_lstlast(t_list *lst) __attribute__((weak));

static void	test_lstnew(void)
{
	char	c;
	t_list	*l;

	l = ft_lstnew(&c);
	print_test("1", l != NULL, FALSE);
	print_test("2", l->content == &c, FALSE);
	print_test("3", l->next == NULL, TRUE);
	free(l);
}

static void	test_lstadd_front(void)
{
	t_list	*l;
	t_list	*l1;
	t_list	*l2;

	l = NULL;
	l1 = taux_lstnew(NULL);
	ft_lstadd_front(&l, l1);
	print_test("1", l == l1, FALSE);
	print_test("2", l->next == NULL, FALSE);
	l2 = taux_lstnew(NULL);
	ft_lstadd_front(&l, l2);
	print_test("3", l == l2, FALSE);
	print_test("4", l->next == l1, FALSE);
	print_test("5", l->next->next == NULL, TRUE);
}

static void	test_lstadd_back(void)
{
	t_list	*l;
	t_list	*l1;
	t_list	*l2;

	l = NULL;
	l1 = taux_lstnew(NULL);
	ft_lstadd_back(&l, l1);
	print_test("1", l == l1, FALSE);
	print_test("2", l->next == NULL, FALSE);
	l2 = taux_lstnew(NULL);
	ft_lstadd_back(&l, l2);
	print_test("3", l == l1, FALSE);
	print_test("4", l->next == l2, FALSE);
	print_test("5", l->next->next == NULL, FALSE);
	ft_lstadd_back(&l, NULL);
	print_test("6", l->next->next == NULL, TRUE);
	free(l1);
	free(l2);
}

void	test_lstlast(void)
{
	t_list	*l;

	l = taux_lstnew(NULL);
	taux_lstadd_back(&l, taux_lstnew(NULL));
	taux_lstadd_back(&l, taux_lstnew(NULL));
	print_test("1", ft_lstlast(l) == l->next->next, FALSE);
	print_test("2", ft_lstlast(l->next) == l->next->next, FALSE);
	print_test("3", ft_lstlast(l->next->next) == l->next->next, FALSE);
	print_test("4", ft_lstlast(NULL) == NULL, TRUE);
	free(l->next->next);
	free(l->next);
	free(l);
}

int	main(void)
{
	test_if_exists(&test_lstnew, &ft_lstnew, "lstnew");
	test_if_exists(&test_lstadd_front, &ft_lstadd_front, "lstadd_front");
	test_if_exists(&test_lstadd_back, &ft_lstadd_back, "lstadd_back");
	test_if_exists(&test_lstlast, &ft_lstlast, "lstlast");
	test_bonus2();
	test_bonus3();
	return (print_all_tests());
}
