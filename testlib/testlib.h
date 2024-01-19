/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:16:32 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/19 13:29:32 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTLIB_H
# define TESTLIB_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

# define COLOR_GREEN	"\033[0;32m"
# define COLOR_NONE		"\033[0m"
# define COLOR_RED		"\033[0;31m"

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}						t_bool;
typedef unsigned int	t_uint;

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

t_uint	tlib_var_failed(t_bool add);

#endif