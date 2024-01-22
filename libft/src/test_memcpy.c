/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:46:07 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/22 18:16:45 by andeviei         ###   ########.fr       */
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

static void	test_memcpy1(void)
{
	char	buf[5];

	tlib_print_test("1", ft_memcpy(buf, "AS DF", 5) == buf, FALSE);
	tlib_print_test("2", !memcmp(buf, "AS DF", 5), FALSE);
	tlib_print_test("3", tlib_alloc_count() == 0, FALSE);
	tlib_print_test("4",
		tlib_run_process(&test_memcpy_crash1, NULL) != 0, FALSE);
	tlib_print_test("5",
		tlib_run_process(&test_memcpy_crash2, NULL) != 0, FALSE);
	tlib_print_test("6",
		tlib_run_process(&test_memcpy_crash3, NULL) == 0, TRUE);
	tlib_alloc_reset();
}

void	test_memcpy(void)
{
	tlib_print_missing(&test_memcpy1, &ft_memcpy, "memcpy");
}
