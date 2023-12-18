/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:20:43 by andeviei          #+#    #+#             */
/*   Updated: 2023/12/18 17:24:56 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <unistd.h>
# include <string.h>

# include "../util/src/testutils.h"

# ifdef TEST_EVAL
#  include "../repo/libft.h"
# else

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

# endif

void	test_is(void);
void	test_to(void);
void	test_mem(void);
void	test_put(void);
void	test_atoi(void);
void	test_calloc(void);
void	test_str1(void);
void	test_str2(void);
void	test_str3(void);
void	test_str4(void);
void	test_itoa(void);

#endif