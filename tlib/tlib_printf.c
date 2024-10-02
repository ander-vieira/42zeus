/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tlib_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:11:26 by andeviei          #+#    #+#             */
/*   Updated: 2024/10/02 22:47:58 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tlib_int.h"

static void	print_str(int fd, char *str)
{
	size_t	len;

	if (str != NULL)
	{
		len = 0;
		while (str[len] != '\0')
			len++;
		write(fd, str, len);
	}
	else
		print_str(fd, "(null)");
}

static void	print_nbr(int fd, size_t nbr, t_uint base)
{
	if (base > 16)
		return ;
	if (nbr >= base)
		print_nbr(fd, nbr /= base, base);
	write(fd, &("0123456789abcdef"[nbr % base]), 1);
}

static void	print_text(int fd, char *format, size_t *i)
{
	size_t	len;

	len = 0;
	while (format[*i + len] != '\0' && format[*i + len] != '%')
		len++;
	write(fd, format + *i, len);
	*i += len;
}

static void	print_direc(int fd, char *format, size_t *i, va_list args)
{
	*i += 1;
	if (format[*i] == 's')
		print_str(fd, va_arg(args, char *));
	else if (format[*i] == 'u')
		print_nbr(fd, va_arg(args, size_t), 10);
	else if (format[*i] == 'p')
	{
		print_str(fd, "0x");
		print_nbr(fd, (size_t)va_arg(args, void *), 16);
	}
	else
		write(fd, "%", 1);
	if (format[*i] != '\0')
		*i += 1;
}

void	tlib_printf(int fd, char *format, ...)
{
	size_t	i;
	va_list	args;

	va_start(args, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			print_direc(fd, format, &i, args);
		else
			print_text(fd, format, &i);
	}
	va_end(args);
}
