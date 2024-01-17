/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:16:32 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/17 17:07:07 by andeviei         ###   ########.fr       */
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

int		run_in_process(int (*fun)(void *), void *ctx);
void	test_if_exists(void (*test)(void), void *fun, char *title);
void	print_test(char *text, t_bool ok, t_bool last);
int		print_all_tests(void);

#endif