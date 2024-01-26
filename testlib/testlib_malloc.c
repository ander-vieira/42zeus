/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlib_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:05:47 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 15:14:53 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testlib.h"

/* ************************************************************************** */
/* Redefining the function malloc to log memory allocations                   */

void	*malloc(size_t len)
{
	void	*addr;

	if (tlib_alloc_tickmocks())
		return (NULL);
	if (len == 0)
	{
		return (NULL);
	}
	addr = libc_malloc(len);
	tlib_alloc_add(addr, len);
	return (addr);
}

/* ************************************************************************** */
/* Redefining the function free to log memory allocations                     */

void	free(void *addr)
{
	if (tlib_alloc_lookup(addr) == 0)
	{
		return ;
	}
	libc_free(addr);
	tlib_alloc_delete(addr);
}

void	*libc_malloc(size_t len)
{
	static void	*(*fun)(size_t);

	if (fun == NULL)
		fun = dlsym(RTLD_NEXT, "malloc");
	return (fun(len));
}

void	libc_free(void *addr)
{
	static void	(*fun)(void *);

	if (fun == NULL)
		fun = dlsym(RTLD_NEXT, "free");
	fun(addr);
}
