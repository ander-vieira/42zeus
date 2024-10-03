#include "tlib_int.h"

static void	print_str(int fd, char *str) {
	size_t	len;

	if (str == NULL)
		str = "(null)";
	len = 0;
	while (str[len] != '\0')
		len++;
	write(fd, str, len);
}

static void print_num(int fd, unsigned long num) {
	if (num >= 10)
		print_num(fd, num / 10);
	write(fd, &("0123456789"[num % 10]), 1);
}

static void print_snum(int fd, int num) {
	if (num < 0) {
		write(1, "-", 1);
		print_num(fd, -(long)num);
	} else
		print_num(fd, num);
}

static void print_color(int fd, char c) {
	if (!isatty(fd))
		return ;
	if (c == 'g')
		print_str(fd, COLORCODE_GREEN);
	else if (c == 'n')
		print_str(fd, COLORCODE_NONE);
	else if (c == 'r')
		print_str(fd, COLORCODE_RED);
	else if (c == 'y')
		print_str(fd, COLORCODE_YELLOW);
}

static void	print_text(int fd, char *format, size_t *i) {
	size_t	len;

	len = 0;
	while (format[*i + len] != '\0' && format[*i + len] != '%')
		len++;
	write(fd, format + *i, len);
	*i += len;
}

static void	print_direc(int fd, char *format, size_t *i, va_list args) {
	*i += 1;
	if (format[*i] == 's')
		print_str(fd, va_arg(args, char *));
	else if (format[*i] == 'z')
		print_num(fd, va_arg(args, size_t));
	else if (format[*i] == 'g' || format[*i] == 'n' || format[*i] == 'r' || format[*i] == 'y')
		print_color(fd, format[*i]);
	else
		write(fd, "%", 1);
	if (format[*i] != '\0')
		*i += 1;
}

void	tlib_printf(int fd, char *format, ...) {
	va_list	args;

	va_start(args, format);
	tlib_vprintf(fd, format, args);
	va_end(args);
}

void	tlib_vprintf(int fd, char *format, va_list args) {
	size_t	i;
	i = 0;
	while (format[i] != '\0') {
		if (format[i] == '%')
			print_direc(fd, format, &i, args);
		else
			print_text(fd, format, &i);
	}
}
