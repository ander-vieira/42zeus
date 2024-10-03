#include "test.h"

static void	test_putchar_fd_testone(char c) {
	char	buf[2];
	int		fd[2];

	pipe(fd);
	ft_putchar_fd(c, fd[1]);
	close(fd[1]);
	tlib_testresult_raw(read(fd[0], buf, 2) == 1 && buf[0] == c);
	close(fd[0]);
}

static void	test_putchar_fd_child1(void) {
	tlib_mockmalloc_reset();
	test_putchar_fd_testone('A');
	test_putchar_fd_testone('\0');
	tlib_testmalloc_leak(NULL);
}

void	test_putchar_fd(void) {
	tlib_testprocess_ok(&test_putchar_fd_child1);
}
