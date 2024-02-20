/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lstiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:49:33 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/20 11:29:17 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

static void		*g_p[2];
static size_t	g_len;
static size_t	g_i;

static void	test_lstiter_init(size_t len, ...)
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

static void	test_lstiter_fun(void *p)
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

static void	test_lstiter_child1(void)
{
	t_list	*l1;
	t_list	*l2;

	test_lstiter_init(2, &l1, &l2);
	tlib_alloc_reset();
	l1 = taux_lstnew(&l1, &malloc);
	l2 = taux_lstnew(&l2, &malloc);
	l1->next = l2;
	ft_lstiter(l1, &test_lstiter_fun);
	tlib_test_ok(g_i == 2);
	tlib_test_ok(l1->next == l2 && l2->next == NULL);
	tlib_test_ok(tlib_alloc_lookup(l1) == sizeof(t_list));
	tlib_test_ok(tlib_alloc_lookup(l2) == sizeof(t_list));
	tlib_test_ok(tlib_alloc_count() == 2);
	free(l1);
	free(l2);
}

static void	test_lstiter_child2(void)
{
	test_lstiter_init(0);
	ft_lstiter(NULL, &test_lstiter_fun);
	tlib_test_ok(g_i == 0);
}

static void	test_lstiter_child3(void)
{
	t_list	*l1;

	tlib_alloc_reset();
	l1 = taux_lstnew(NULL, &malloc);
	ft_lstiter(l1, NULL);
	tlib_test_ok(l1->next == NULL);
	tlib_test_ok(tlib_alloc_lookup(l1) == sizeof(t_list));
	tlib_test_ok(tlib_alloc_count() == 1);
	free(l1);
}

void	test_lstiter(void)
{
	tlib_test_process(&test_lstiter_child1, PRESULT_OK);
	tlib_test_process(&test_lstiter_child2, PRESULT_OK);
	tlib_test_process(&test_lstiter_child3, PRESULT_OK);
}
