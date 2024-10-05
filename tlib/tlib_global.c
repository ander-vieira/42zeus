/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tlib_global.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 18:59:42 by andeviei          #+#    #+#             */
/*   Updated: 2024/10/05 19:01:59 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tlib_int.h"

t_bool	tlib_islogging;
int		tlib_logfd;
char	*tlib_section;
t_bool	tlib_newsection;

t_alloc	*tlib_allocs;
t_amock	*tlib_mocks;

t_bool	tlib_ischild;
t_bool	tlib_testfailed;
int		print_pipe[2];
