/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:16:32 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 11:45:17 by andeviei         ###   ########.fr       */
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

/* ************************************************************************** */
/* Alloc: managing lists of memory allocations                                */

void	tlib_alloc_add(void *addr, size_t size);
t_bool	tlib_alloc_delete(void *addr);
void	tlib_alloc_print(void);
void	tlib_alloc_reset(void);
size_t	tlib_alloc_lookup(void *addr);
size_t	tlib_alloc_count(void);
t_byte	tlib_alloc_errors(void);
void	tlib_alloc_setmock(size_t timer);
t_bool	tlib_alloc_tickmocks(void);
void	tlib_alloc_resetmocks(void);

/* ************************************************************************** */
/* Io: testing functions that use file descriptors                            */

t_bool	tlib_io_readtest(int fd, size_t len, ssize_t exp_len, void *exp);

/* ************************************************************************** */
/* Malloc: redefining malloc and free to add logging tools                    */

void	*libc_malloc(size_t len);
void	libc_free(void *addr);

/* ************************************************************************** */
/* Print: printing test results                                               */

void	tlib_print_missing(void (*test)(void), void *fun, char *title);
void	tlib_print_test(t_bool ok);
int		tlib_print_final(void);

/* ************************************************************************** */
/* Printf: making my own version for portability                              */

void	tlib_printf(int fd, char *format, ...);

/* ************************************************************************** */
/* Run: handling child processes                                              */

int		tlib_run_process(int (*fun)(void));

/* ************************************************************************** */
/* Var: "global" variables                                                    */

t_uint	*tlib_var_failed(void);
t_alloc	**tlib_var_alloclist(void);
t_amock	**tlib_var_amocklist(void);
t_byte	*tlib_var_errmalloc(void);

#endif