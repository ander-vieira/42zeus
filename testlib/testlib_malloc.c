/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlib_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:05:47 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/19 17:27:25 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testlib.h"

/* ************************************************************************** */
/* Redefining the function malloc to log memory allocations                   */

void	*malloc(size_t len)
{
	void	*(*old_malloc)(size_t);
	void	*addr;

	if (len == 0)
	{
		*tlib_var_errmalloc() |= ERRMALLOC_ZERO;
		return (NULL);
	}
	old_malloc = dlsym(RTLD_NEXT, "malloc");
	addr = old_malloc(len);
	tlib_alloc_add(addr, len, old_malloc);
	return (addr);
}

/* ************************************************************************** */
/* Redefining the function free to log memory allocations                     */

void	free(void *addr)
{
	void	(*old_free)(void *);

	if (tlib_alloc_lookup(addr) == 0)
	{
		*tlib_var_errmalloc() |= ERRMALLOC_FREE;
		return ;
	}
	old_free = dlsym(RTLD_NEXT, "free");
	old_free(addr);
	tlib_alloc_delete(addr, old_free);
}
