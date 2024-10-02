/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:14:59 by andeviei          #+#    #+#             */
/*   Updated: 2024/10/02 22:50:42 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	tlib_testmissing(&test_isalpha, &ft_isalpha, "isalpha");
	tlib_testmissing(&test_isdigit, &ft_isdigit, "isdigit");
	tlib_testmissing(&test_isalnum, &ft_isalnum, "isalnum");
	tlib_testmissing(&test_isascii, &ft_isascii, "isascii");
	tlib_testmissing(&test_isprint, &ft_isprint, "isprint");
	tlib_testmissing(&test_tolower, &ft_tolower, "tolower");
	tlib_testmissing(&test_toupper, &ft_toupper, "toupper");
	tlib_testmissing(&test_bzero, &ft_bzero, "bzero");
	tlib_testmissing(&test_memset, &ft_memset, "memset");
	tlib_testmissing(&test_memcpy, &ft_memcpy, "memcpy");
	tlib_testmissing(&test_memmove, &ft_memmove, "memmove");
	tlib_testmissing(&test_memchr, &ft_memchr, "memchr");
	tlib_testmissing(&test_memcmp, &ft_memcmp, "memcmp");
	tlib_testmissing(&test_atoi, &ft_atoi, "atoi");
	tlib_testmissing(&test_calloc, &ft_calloc, "calloc");
	tlib_testmissing(&test_strlen, &ft_strlen, "strlen");
	tlib_testmissing(&test_strchr, &ft_strchr, "strchr");
	tlib_testmissing(&test_strrchr, &ft_strrchr, "strrchr");
	tlib_testmissing(&test_strncmp, &ft_strncmp, "strncmp");
	tlib_testmissing(&test_strdup, &ft_strdup, "strdup");
	tlib_testmissing(&test_strlcpy, &ft_strlcpy, "strlcpy");
	tlib_testmissing(&test_strlcat, &ft_strlcat, "strlcat");
	tlib_testmissing(&test_strnstr, &ft_strnstr, "strnstr");
	tlib_testmissing(&test_substr, &ft_substr, "substr");
	tlib_testmissing(&test_strjoin, &ft_strjoin, "strjoin");
	tlib_testmissing(&test_strtrim, &ft_strtrim, "strtrim");
	tlib_testmissing(&test_split, &ft_split, "split");
	tlib_testmissing(&test_itoa, &ft_itoa, "itoa");
	tlib_testmissing(&test_strmapi, &ft_strmapi, "strmapi");
	tlib_testmissing(&test_striteri, &ft_striteri, "striteri");
	tlib_testmissing(&test_putchar_fd, &ft_putchar_fd, "putchar_fd");
	tlib_testmissing(&test_putstr_fd, &ft_putstr_fd, "putstr_fd");
	tlib_testmissing(&test_putendl_fd, &ft_putendl_fd, "putendl_fd");
	tlib_testmissing(&test_putnbr_fd, &ft_putnbr_fd, "putnbr_fd");
	return (tlib_test_results());
}
