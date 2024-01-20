/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taux_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:59:50 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/20 19:01:04 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	taux_split_free(char **split)
{
	size_t	i;

	if (split != NULL)
	{
		i = 0;
		while (split[i] != NULL)
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
}
