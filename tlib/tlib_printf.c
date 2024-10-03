#include "tlib_int.h"

static void	print_str(int fd, char *str) {
	size_t	len;

	if (str != NULL) {
		len = 0;
		while (str[len] != '\0')
			len++;
		write(fd, str, len);
	} else
		print_str(fd, "(null)");
}

static void print_color(int fd, char c) {
	if (!isatty(fd))
		return ;
	if (c == 'n')
		print_str(fd, COLORCODE_NONE);
	else if (c == 'r')
		print_str(fd, COLORCODE_RED);
	else if (c == 'g')
		print_str(fd, COLORCODE_GREEN);
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
	else if (format[*i] == 'n' || format[*i] == 'r' || format[*i] == 'g')
		print_color(fd, format[*i]);
	else
		write(fd, "%", 1);
	if (format[*i] != '\0')
		*i += 1;
}

void	tlib_printf(int fd, char *format, ...) {
	size_t	i;
	va_list	args;

	va_start(args, format);
	i = 0;
	while (format[i] != '\0') {
		if (format[i] == '%')
			print_direc(fd, format, &i, args);
		else
			print_text(fd, format, &i);
	}
	va_end(args);
}
