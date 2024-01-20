/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlib_io.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:16:04 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/20 19:31:05 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testlib.h"

t_bool	tlib_io_readtest(int fd, size_t len, ssize_t exp_len, void *exp)
{
	void	*buf;
	ssize_t	read_len;
	t_bool	result;

	buf = (char *)malloc(sizeof(char) * len);
	read_len = read(fd, buf, len);
	result = (read_len == exp_len
			&& (exp_len <= 0 || !memcmp(buf, exp, exp_len)));
	free(buf);
	return (result);
}
