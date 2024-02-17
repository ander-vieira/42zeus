/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:14:59 by andeviei          #+#    #+#             */
/*   Updated: 2024/02/17 17:36:44 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	tlib_test_missing(&test_isalpha, &ft_isalpha, "isalpha");
	tlib_test_missing(&test_isdigit, &ft_isdigit, "isdigit");
	tlib_test_missing(&test_isalnum, &ft_isalnum, "isalnum");
	tlib_test_missing(&test_isascii, &ft_isascii, "isascii");
	tlib_test_missing(&test_isprint, &ft_isprint, "isprint");
	tlib_test_missing(&test_tolower, &ft_tolower, "tolower");
	tlib_test_missing(&test_toupper, &ft_toupper, "toupper");
	tlib_test_missing(&test_bzero, &ft_bzero, "bzero");
	tlib_test_missing(&test_memset, &ft_memset, "memset");
	tlib_test_missing(&test_memcpy, &ft_memcpy, "memcpy");
	tlib_test_missing(&test_memmove, &ft_memmove, "memmove");
	tlib_test_missing(&test_memchr, &ft_memchr, "memchr");
	tlib_test_missing(&test_memcmp, &ft_memcmp, "memcmp");
	tlib_test_missing(&test_atoi, &ft_atoi, "atoi");
	tlib_test_missing(&test_calloc, &ft_calloc, "calloc");
	tlib_test_missing(&test_strlen, &ft_strlen, "strlen");
	tlib_test_missing(&test_strchr, &ft_strchr, "strchr");
	tlib_test_missing(&test_strrchr, &ft_strrchr, "strrchr");
	tlib_test_missing(&test_strncmp, &ft_strncmp, "strncmp");
	tlib_test_missing(&test_strdup, &ft_strdup, "strdup");
	tlib_test_missing(&test_strlcpy, &ft_strlcpy, "strlcpy");
	tlib_test_missing(&test_strlcat, &ft_strlcat, "strlcat");
	tlib_test_missing(&test_strnstr, &ft_strnstr, "strnstr");
	tlib_test_missing(&test_substr, &ft_substr, "substr");
	tlib_test_missing(&test_strjoin, &ft_strjoin, "strjoin");
	tlib_test_missing(&test_strtrim, &ft_strtrim, "strtrim");
	tlib_test_missing(&test_split, &ft_split, "split");
	tlib_test_missing(&test_itoa, &ft_itoa, "itoa");
	tlib_test_missing(&test_strmapi, &ft_strmapi, "strmapi");
	tlib_test_missing(&test_striteri, &ft_striteri, "striteri");
	tlib_test_missing(&test_putchar_fd, &ft_putchar_fd, "putchar_fd");
	tlib_test_missing(&test_putstr_fd, &ft_putstr_fd, "putstr_fd");
	tlib_test_missing(&test_putendl_fd, &ft_putendl_fd, "putendl_fd");
	tlib_test_missing(&test_putnbr_fd, &ft_putnbr_fd, "putnbr_fd");
	return (tlib_test_results());
}
