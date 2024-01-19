/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlib_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:21:54 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/19 17:20:40 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testlib.h"

t_uint	*tlib_var_failed(void)
{
	static t_uint	failed;

	return (&failed);
}

t_alloc	**tlib_var_alloclist(void)
{
	static t_alloc	*list;

	return (&list);
}

t_byte	*tlib_var_errmalloc(void)
{
	static t_byte	errmalloc;

	return (&errmalloc);
}
