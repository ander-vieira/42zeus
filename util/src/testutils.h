/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testutils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:16:32 by andeviei          #+#    #+#             */
/*   Updated: 2023/12/11 17:37:57 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTUTILS_H
# define TESTUTILS_H

# include <stdlib.h>
# include <stdio.h>

# define COLOR_GREEN	"\033[0;32m"
# define COLOR_NONE		"\033[0m"
# define COLOR_RED		"\033[0;31m"

typedef enum e_bool
{
	FALSE = 0,
	TRUE = 1
}						t_bool;
typedef unsigned int	t_uint;

void	print_title(char *title);
void	print_test(char *text, t_bool ok, t_bool last);
int		print_all_tests(void);

#endif