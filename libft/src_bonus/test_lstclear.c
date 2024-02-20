/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:42:55 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/20 11:27:05 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

static void		*g_p[2];
static size_t	g_len;
static size_t	g_i;

static void	test_lstclear_init(size_t len, ...)
{
	va_list	args;
	size_t	i;

	va_start(args, len);
	g_i = 0;
	g_len = len;
	i = 0;
	while (i < g_len)
	{
		g_p[i] = va_arg(args, void *);
		i++;
	}
	va_end(args);
}

static void	test_lstclear_del(void *p)
{
	t_bool	found;
	size_t	i;

	found = FALSE;
	i = 0;
	while (i < g_len)
	{
		if (p == g_p[i])
		{
			found = TRUE;
			g_p[i] = NULL;
			break ;
		}
		i++;
	}
	tlib_test_ok(found);
	g_i++;
}

static void	test_lstclear_child1(void)
{
	t_list	*l;
	t_list	*l1;
	t_list	*l2;

	test_lstclear_init(2, &l1, &l2);
	tlib_alloc_reset();
	l1 = taux_lstnew(&l1, &malloc);
	l2 = taux_lstnew(&l2, &malloc);
	l = l1;
	l->next = l2;
	ft_lstclear(&l, &test_lstclear_del);
	tlib_test_ok(g_i == 2);
	tlib_test_ok(l == NULL);
	tlib_test_ok(tlib_alloc_lookup(l1) == 0);
	tlib_test_ok(tlib_alloc_lookup(l2) == 0);
	tlib_test_ok(tlib_alloc_count() == 0);
	free(l1);
	free(l2);
}

static void	test_lstclear_child2(void)
{
	t_list	*l;

	test_lstclear_init(0);
	l = NULL;
	ft_lstclear(&l, &test_lstclear_del);
	tlib_test_ok(g_i == 0);
	tlib_test_ok(l == NULL);
}

static void	test_lstclear_child3(void)
{
	test_lstclear_init(0);
	ft_lstclear(NULL, &test_lstclear_del);
	tlib_test_ok(g_i == 0);
}

static void	test_lstclear_child4(void)
{
	t_list	*l;
	t_list	*l1;

	tlib_alloc_reset();
	l1 = taux_lstnew(NULL, &malloc);
	l = l1;
	ft_lstclear(&l, NULL);
	tlib_test_ok(l == l1 && l->next == NULL);
	tlib_test_ok(tlib_alloc_lookup(l1) == sizeof(t_list));
	tlib_test_ok(tlib_alloc_count() == 1);
	free(l1);
}

void	test_lstclear(void)
{
	tlib_test_process(&test_lstclear_child1, PRESULT_OK);
	tlib_test_process(&test_lstclear_child2, PRESULT_OK);
	tlib_test_process(&test_lstclear_child3, PRESULT_OK);
	tlib_test_process(&test_lstclear_child4, PRESULT_OK);
}
