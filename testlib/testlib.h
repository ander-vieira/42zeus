/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:16:32 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/17 15:03:49 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTLIB_H
# define TESTLIB_H

# define _GNU_SOURCE

# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <dlfcn.h>
# include <fcntl.h>
# include <sys/wait.h>

# define COLOR_GREEN	"\033[0;32m"
# define COLOR_NONE		"\033[0m"
# define COLOR_RED		"\033[0;31m"

# define ERRMALLOC_ZERO	0x01
# define ERRMALLOC_FREE	0x02

# define STATUS_OK			0
# define STATUS_SEGFAULT	139

typedef unsigned char	t_byte;
typedef unsigned int	t_uint;

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}						t_bool;

typedef struct s_alloc
{
	struct s_alloc	*next;
	void			*addr;
	size_t			size;
}	t_alloc;

typedef struct s_amock
{
	struct s_amock	*next;
	size_t			timer;
}	t_amock;

typedef enum s_pres
{
	PRESULT_OK,
	PRESULT_SEGFAULT,
	PRESULT_CRASH
}	t_pres;

/* ************************************************************************** */
/* Alloc: managing lists of memory allocations                                */

void	tlib_alloc_add(void *addr, size_t size);
t_bool	tlib_alloc_delete(void *addr);
void	tlib_alloc_reset(void);
size_t	tlib_alloc_lookup(void *addr);
size_t	tlib_alloc_count(void);
void	tlib_alloc_setmock(size_t timer);
t_bool	tlib_alloc_tickmocks(void);
void	tlib_alloc_resetmocks(void);

/* ************************************************************************** */
/* Malloc: redefining malloc and free to add logging tools                    */

void	*libc_malloc(size_t len);
void	libc_free(void *addr);

/* ************************************************************************** */
/* Printf: making my own version for portability                              */

void	tlib_printf(int fd, char *format, ...);

/* ************************************************************************** */
/* Test: printing test results                                                */

void	tlib_test_missing(void (*test)(void), void *fun, char *title);
void	tlib_test_ok(t_bool ok);
void	tlib_test_process(void (*fun)(void), t_pres expected);
int		tlib_test_results(void);

#endif