/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:14:59 by andeviei          #+#    #+#             */
/*   Updated: 2023/12/15 15:42:36 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	test_is();
	test_to();
	test_mem();
	test_put();
	return (print_all_tests());
}
