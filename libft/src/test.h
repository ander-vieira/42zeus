/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:20:43 by andeviei          #+#    #+#             */
/*   Updated: 2024/01/20 17:05:05 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <unistd.h>
# include <string.h>

# include "../../testlib/testlib.h"

# ifdef TEST_EVAL
#  include "../../repo/libft.h"
# else

/* ************************************************************************** */
/* Fake definitions to get VSCode dependency detection working                */

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

int		ft_tolower(int c);
int		ft_toupper(int c);

void	ft_bzero(void *b, size_t n);
void	*ft_memset(void *b, int c, size_t n);
void	*ft_memcpy(void *d, const void *s, size_t n);
void	*ft_memmove(void *d, const void *s, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char *str, int fd);
void	ft_putnbr_fd(int num, int fd);

int		ft_atoi(const char *str);

void	*ft_calloc(size_t count, size_t size);

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strnstr(const char *h, const char *n, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_itoa(int n);
char	**ft_split(char const *str, char c);

# endif

/* ************************************************************************** */
/* Weak definitions to check for missing functions                            */

#pragma weak ft_isalpha
#pragma weak ft_isdigit
#pragma weak ft_isalnum
#pragma weak ft_isascii
#pragma weak ft_isprint

#pragma weak ft_tolower
#pragma weak ft_toupper

#pragma weak ft_bzero
#pragma weak ft_memset
#pragma weak ft_memcpy
#pragma weak ft_memmove
#pragma weak ft_memchr
#pragma weak ft_memcmp

#pragma weak ft_putchar_fd
#pragma weak ft_putstr_fd
#pragma weak ft_putendl_fd
#pragma weak ft_putnbr_fd

#pragma weak ft_atoi

#pragma weak ft_calloc

#pragma weak ft_strlen
#pragma weak ft_strchr
#pragma weak ft_strrchr
#pragma weak ft_strncmp
#pragma weak ft_strdup
#pragma weak ft_strlcpy
#pragma weak ft_strlcat
#pragma weak ft_strnstr
#pragma weak ft_substr
#pragma weak ft_strjoin
#pragma weak ft_strtrim
#pragma weak ft_strmapi
#pragma weak ft_striteri
#pragma weak ft_itoa
#pragma weak ft_split

/* ************************************************************************** */
/* Test functions                                                             */

void	test_is1(void);
void	test_is2(void);
void	test_to(void);
void	test_mem1(void);
void	test_mem2(void);
void	test_put(void);
void	test_atoi(void);
void	test_calloc(void);
void	test_str1(void);
void	test_str2(void);
void	test_str3(void);
void	test_str4(void);
void	test_itoa(void);
void	test_split(void);

#endif