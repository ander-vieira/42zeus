#include "test.h"

static void	test_putnbr_fd_testone(int num, char *str) {
	char	buf[15];
	int		fd[2];
	ssize_t	len;

	pipe(fd);
	ft_putnbr_fd(num, fd[1]);
	close(fd[1]);
	len = strlen(str);
	tlib_testresult_raw(read(fd[0], buf, 15) == len && !memcmp(buf, str, len));
	close(fd[0]);
}

static void	test_putnbr_fd_child1(void) {
	tlib_mockmalloc_reset();
	test_putnbr_fd_testone(53, "53");
	test_putnbr_fd_testone(0, "0");
	test_putnbr_fd_testone(-4242, "-4242");
	test_putnbr_fd_testone(2147483647, "2147483647");
	test_putnbr_fd_testone(-2147483648, "-2147483648");
	tlib_testmalloc_count(0);
}

void	test_putnbr_fd(void) {
	tlib_testprocess_ok(&test_putnbr_fd_child1);
}
