/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:56:26 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/26 12:26:21 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

int	main(void)
{
	tlib_test_missing(&test_lstnew, &ft_lstnew, "lstnew");
	tlib_test_missing(&test_lstadd_front, &ft_lstadd_front, "lstadd_front");
	tlib_test_missing(&test_lstsize, &ft_lstsize, "lstsize");
	tlib_test_missing(&test_lstlast, &ft_lstlast, "lstlast");
	tlib_test_missing(&test_lstadd_back, &ft_lstadd_back, "lstadd_back");
	tlib_test_missing(&test_lstdelone, &ft_lstdelone, "lstdelone");
	tlib_test_missing(&test_lstclear, &ft_lstclear, "lstclear");
	tlib_test_missing(&test_lstiter, &ft_lstiter, "lstiter");
	tlib_test_missing(&test_lstmap, &ft_lstmap, "lstmap");
	return (tlib_test_results());
}
