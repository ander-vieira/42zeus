/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:46:07 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 09:39:49 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	test_memcpy_crash1(void *ctx)
{
	(void)ctx;
	ft_memcpy(NULL, "MUNDO", 5);
	return (0);
}

static int	test_memcpy_crash2(void *ctx)
{
	char	buf[5];

	(void)ctx;
	ft_memcpy(buf, NULL, 5);
	return (0);
}

static int	test_memcpy_crash3(void *ctx)
{
	int		status;
	void	*ptr;

	(void)ctx;
	ptr = ft_memcpy(NULL, NULL, 2);
	if (ptr == NULL)
		status = 0;
	else
		status = 1;
	free(ptr);
	return (status);
}

void	test_memcpy(void)
{
	char	buf[5];

	tlib_print_test(ft_memcpy(buf, "AS DF", 5) == buf);
	tlib_print_test(!memcmp(buf, "AS DF", 5));
	tlib_print_test(tlib_alloc_count() == 0);
	tlib_print_test(tlib_run_process(&test_memcpy_crash1, NULL) != 0);
	tlib_print_test(tlib_run_process(&test_memcpy_crash2, NULL) != 0);
	tlib_print_test(tlib_run_process(&test_memcpy_crash3, NULL) == 0);
	tlib_alloc_reset();
}
