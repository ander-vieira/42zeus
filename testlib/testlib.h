/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:16:32 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/19 17:34:08 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTLIB_H
# define TESTLIB_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <dlfcn.h>

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

/* ************************************************************************** */
/* Alloc: managing lists of memory allocations                                */

void	tlib_alloc_add(void *addr, size_t size, void *(*old_malloc)(size_t));
t_bool	tlib_alloc_delete(void *addr, void (*old_free)(void *));
void	tlib_alloc_print(void);
void	tlib_alloc_reset(void);
size_t	tlib_alloc_lookup(void *addr);
size_t	tlib_alloc_count(void);
t_bool	tlib_alloc_errors(void);

/* ************************************************************************** */
/* Print: printing test results                                               */

void	tlib_print_missing(void (*test)(void), void *fun, char *title);
void	tlib_print_test(char *text, t_bool ok, t_bool last);
int		tlib_print_final(void);

/* ************************************************************************** */
/* Run: handling child processes                                              */

int		tlib_run_process(int (*fun)(void *), void *ctx);

/* ************************************************************************** */
/* Var: "global" variables                                                    */

t_uint	*tlib_var_failed(void);
t_alloc	**tlib_var_alloclist(void);
t_byte	*tlib_var_errmalloc(void);

#endif