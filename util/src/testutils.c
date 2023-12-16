/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:16:26 by andeviei          #+#    #+#             */
/*   Updated: 2023/12/16 11:53:51 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testutils.h"

static t_uint	failed_count(t_bool add)
{
	static t_uint	count;

	if (add)
		count++;
	return (count);
}

void	print_title(char *title)
{
	printf("%s: ", title);
}

void	print_test(char *text, t_bool ok, t_bool last)
{
	printf("[%s: ", text);
	if (ok)
		printf(COLOR_GREEN"OK"COLOR_NONE);
	else
	{
		printf(COLOR_RED"KO"COLOR_NONE);
		failed_count(TRUE);
	}
	printf("]");
	if (last)
		printf("\n");
	else
		printf(" ");
}

int	print_all_tests(void)
{
	printf("--- FINAL RESULT ---\n");
	if (failed_count(FALSE) == 0)
	{
		printf(COLOR_GREEN"All tests OK!\n"COLOR_NONE);
		return (EXIT_SUCCESS);
	}
	else
	{
		printf(COLOR_RED"Errors detected, please review.\n"COLOR_NONE);
		return (EXIT_FAILURE);
	}
}