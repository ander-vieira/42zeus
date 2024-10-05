/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tlib_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 10:53:33 by andeviei          #+#    #+#             */
/*   Updated: 2024/10/05 12:26:15 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tlib_int.h"

t_bool	tlib_aux_memisset(void *addr, size_t n, unsigned char c) {
	size_t	i;

	if (addr == NULL)
		return (FALSE);
	i = 0;
	while (i < n) {
		if (((unsigned char *)addr)[i] != c)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	tlib_aux_memcmp(void *addr1, void *addr2, size_t n) {
	size_t	i;

	i = 0;
	while (i < n) {
		if (((unsigned char *)addr1)[i] != ((unsigned char *)addr2)[i])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	tlib_aux_memcpy(void *dst, void *src, size_t n) {
	size_t	i;

	i = 0;
	while (i < n) {
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
}

t_bool	tlib_aux_strcmp(char *str1, char *str2) {
	size_t	i;

	if (str1 == NULL && str2 == NULL)
		return (TRUE);
	if (str1 == NULL || str2 == NULL)
		return (FALSE);
	i = 0;
	while (str1[i] != '\0' || str2[i] != '\0') {
		if (str1[i] != str2[i])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

size_t	tlib_aux_strlen(char *str) {
	size_t	len;

	if (str == NULL)
		return (0);
	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
