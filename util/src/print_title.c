/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_title.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:12:09 by andeviei          #+#    #+#             */
/*   Updated: 2023/11/18 17:02:58 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static char	*av_repeatchr(char c, size_t len)
{
	char	*result;
	size_t	i;

	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = c;
		i++;
	}
	result[len] = '\0';
	return (result);
}

int	main(int argc, char **argv)
{
	char	*hyph;

	if (argc < 2)
		return (0);
	hyph = av_repeatchr('-', strlen(argv[1]));
	if (hyph == NULL)
		return (0);
	printf("+---%s---+\n|   %s   |\n+---%s---+\n", hyph, argv[1], hyph);
	return (0);
}
