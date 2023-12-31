/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:14:59 by andeviei          #+#    #+#             */
/*   Updated: 2023/12/19 01:30:46 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	test_is();
	test_to();
	test_mem();
	test_atoi();
	test_calloc();
	test_str1();
	test_str2();
	test_str3();
	test_str4();
	test_itoa();
	test_split();
	test_put();
	return (print_all_tests());
}
