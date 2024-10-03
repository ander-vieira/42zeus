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

static void	print_strvar(int fd, char *str) {
	if (str == NULL)
		print_str(fd, "NULL");
	else {
		print_str(fd, "\"");
		print_str(fd, str);
		print_str(fd, "\"");
	}
}

static void print_char(int fd, char c) {
	print_str(fd, "'");
	if (c == '\0')
		print_str(fd, "\\0");
	else if (c == '\n')
		print_str(fd, "\\n");
	else
		write(fd, &c, 1);
	print_str(fd, "'");
}

static void print_num(int fd, unsigned long num, unsigned int base) {
	if (num >= base)
		print_num(fd, num / base, base);
	write(fd, &("0123456789abcdef"[num % base]), 1);
}

static void print_snum(int fd, int num) {
	if (num < 0) {
		write(fd, "-", 1);
		print_num(fd, -(long)num, 10);
	} else
		print_num(fd, num, 10);
}

static void print_addr(int fd, void *addr) {
	if (addr == NULL)
		print_str(fd, "NULL");
	else {
		print_str(fd, "0x");
		print_num(fd, (unsigned long)addr, 16);
	}
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
	else if (format[*i] == 'S')
		print_strvar(fd, va_arg(args, char *));
	else if (format[*i] == 'c')
		print_char(fd, va_arg(args, int));
	else if (format[*i] == 'u')
		print_num(fd, va_arg(args, unsigned int), 10);
	else if (format[*i] == 'z')
		print_num(fd, va_arg(args, size_t), 10);
	else if (format[*i] == 'd')
		print_snum(fd, va_arg(args, int));
	else if (format[*i] == 'p')
		print_addr(fd, va_arg(args, void *));
	else if (format[*i] == 'g' || format[*i] == 'n' || format[*i] == 'r' || format[*i] == 'y')
		print_color(fd, format[*i]);
	else
		write(fd, "%", 1);
	if (format[*i] != '\0')
		*i += 1;
}

void	tlib_print(int fd, char *format, ...) {
	va_list	args;

	va_start(args, format);
	tlib_vaprint(fd, format, args);
	va_end(args);
}

void	tlib_vaprint(int fd, char *format, va_list args) {
	size_t	i;
	i = 0;
	while (format[i] != '\0') {
		if (format[i] == '%')
			print_direc(fd, format, &i, args);
		else
			print_text(fd, format, &i);
	}
}
