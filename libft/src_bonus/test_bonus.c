/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:56:26 by andeviei          #+#    #+#             */
/*   Updated: 2024/10/02 22:50:42 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

int	main(void)
{
	tlib_testmissing(&test_lstnew, &ft_lstnew, "lstnew");
	tlib_testmissing(&test_lstadd_front, &ft_lstadd_front, "lstadd_front");
	tlib_testmissing(&test_lstsize, &ft_lstsize, "lstsize");
	tlib_testmissing(&test_lstlast, &ft_lstlast, "lstlast");
	tlib_testmissing(&test_lstadd_back, &ft_lstadd_back, "lstadd_back");
	tlib_testmissing(&test_lstdelone, &ft_lstdelone, "lstdelone");
	tlib_testmissing(&test_lstclear, &ft_lstclear, "lstclear");
	tlib_testmissing(&test_lstiter, &ft_lstiter, "lstiter");
	tlib_testmissing(&test_lstmap, &ft_lstmap, "lstmap");
	return (tlib_test_results());
}
