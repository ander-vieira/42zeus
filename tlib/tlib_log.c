#include "tlib_int.h"

void	tlib_log_end(void) {
	if (tlib_islogging)
		close(tlib_logfd);
	tlib_islogging = FALSE;
}

void	tlib_log_print(char *format, ...) {
	va_list	args;

	va_start(args, format);
	tlib_log_vaprint(format, args);
	va_end(args);
}

void	tlib_log_section(char *section) {
	if (!tlib_islogging)
		return ;
	tlib_section = section;
	tlib_newsection = TRUE;
}

void	tlib_log_start(t_bool clear) {
	if (tlib_islogging)
		return ;
	if (clear)
		tlib_logfd = open(ERRORLOG_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		tlib_logfd = open(ERRORLOG_FILE, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (tlib_logfd != -1)
		tlib_islogging = TRUE;
}

void	tlib_log_vaprint(char *format, va_list args) {
	if (!tlib_islogging)
		return ;
	if (tlib_newsection) {
		tlib_print(tlib_logfd, "\n--- %s ---\n\n", tlib_section);
		tlib_newsection = FALSE;
	}
	tlib_vaprint(tlib_logfd, format, args);
}
