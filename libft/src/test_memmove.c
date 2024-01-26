/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:08:04 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 09:39:49 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	test_memmove_crash1(void *ctx)
{
	(void)ctx;
	ft_memmove(NULL, "MUNDO", 5);
	return (0);
}

static int	test_memmove_crash2(void *ctx)
{
	char	buf[5];

	(void)ctx;
	ft_memmove(buf, NULL, 5);
	return (0);
}

static int	test_memmove_crash3(void *ctx)
{
	int		status;
	void	*ptr;

	(void)ctx;
	ptr = ft_memmove(NULL, NULL, 2);
	if (ptr == NULL)
		status = 0;
	else
		status = 1;
	free(ptr);
	return (status);
}

void	test_memmove(void)
{
	char	buf[5];

	tlib_print_test(ft_memmove(buf, "AS DF", 5) == buf);
	tlib_print_test(!memcmp(buf, "AS DF", 5));
	tlib_print_test(ft_memmove(buf, buf + 3, 2) == buf);
	tlib_print_test(!memcmp(buf, "DF DF", 5));
	tlib_print_test(ft_memmove(buf + 2, buf, 3) == buf + 2);
	tlib_print_test(!memcmp(buf, "DFDF ", 5));
	tlib_print_test(tlib_alloc_count() == 0);
	tlib_print_test(tlib_run_process(&test_memmove_crash1, NULL) != 0);
	tlib_print_test(tlib_run_process(&test_memmove_crash2, NULL) != 0);
	tlib_print_test(tlib_run_process(&test_memmove_crash3, NULL) == 0);
	tlib_alloc_reset();
}
