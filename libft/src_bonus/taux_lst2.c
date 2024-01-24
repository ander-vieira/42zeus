/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taux_lst2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:50:59 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/24 18:58:42 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

void	taux_delfun(void *content)
{
	*((char *)content) = 'c';
}

void	taux_iterfun(void *content)
{
	*((char *)content) = 'i';
}

void	*taux_mapfun(void *content)
{
	static int	i;

	i += 1;
	return (content + i);
}
