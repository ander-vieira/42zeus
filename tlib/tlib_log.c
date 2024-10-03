/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tlib_log.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andeviei <andeviei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 09:53:50 by andeviei          #+#    #+#             */
/*   Updated: 2024/10/03 13:54:58 by andeviei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tlib_int.h"

t_bool	tlib_islogging;
int		tlib_logfd;
char	*tlib_section;
t_bool	tlib_newsection;

void	tlib_log_end(void) {
	if (tlib_islogging)
		close(tlib_logfd);
	tlib_islogging = FALSE;
}

void	tlib_log_print(char *format, ...) {
	va_list	args;

	if (!tlib_islogging)
		return ;
	if (tlib_newsection) {
		tlib_printf(tlib_logfd, "\n--- %s ---\n\n", tlib_section);
		tlib_newsection = FALSE;
	}
	va_start(args, format);
	tlib_vprintf(tlib_logfd, format, args);
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
