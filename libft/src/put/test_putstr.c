#include "test.h"

static void	test_putstr_fd_testone(char *str) {
	char	buf[10];
	int		fd[2];
	ssize_t	len;

	len = strlen(str);
	pipe(fd);
	ft_putstr_fd(str, fd[1]);
	close(fd[1]);
	tlib_testresult_raw(read(fd[0], buf, 10) == len && !memcmp(buf, str, len));
	close(fd[0]);
}

static void	test_putstr_fd_child1(void) {
	tlib_mockmalloc_reset();
	test_putstr_fd_testone("ASDFG");
	test_putstr_fd_testone("");
	tlib_testmalloc_count(0);
}

static void	test_putstr_fd_child2(void) {
	int		fd[2];

	tlib_mockmalloc_reset();
	pipe(fd);
	ft_putstr_fd(NULL, fd[1]);
	tlib_testmalloc_count(0);
	close(fd[1]);
	close(fd[0]);
}

void	test_putstr_fd(void) {
	tlib_testprocess_ok(&test_putstr_fd_child1);
	tlib_testprocess_ok(&test_putstr_fd_child2);
}
