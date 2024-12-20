#include "tlib_int.h"

static void	tlib_test_setfail() {
	if (tlib_ischild)
		kill(getppid(), SIGUSR1);
	else
		tlib_testfailed = TRUE;
}

static void	handle_sigusr(int signal) {
	tlib_test_setfail();
}

static void	tlib_testresult_raw(t_bool ok) {
	if (ok)
		tlib_print(STDOUT_FILENO, "%g[OK]%n");
	else {
		tlib_test_setfail();
		tlib_print(STDOUT_FILENO, "%r[KO]%n");
	}
}

void	tlib_testmalloc_leak(char *call, ...) {
	size_t	count;

	count = tlib_mockmalloc_count();
	if (count != 0) {
		tlib_test_setfail();
		tlib_print(STDOUT_FILENO, "%r[LEAKS]%n");
		__tlib_log_call(call);
		tlib_log_print(" has created a memory leak\n");
		tlib_log_print("- %z memory addresses not freed\n", count);
	}
}

void	tlib_testmalloc_notfreed(void *addr, char *call, ...) {
	size_t	actual_size;
	t_bool	condition;

	actual_size = tlib_mockmalloc_lookup(addr);
	condition = (actual_size != 0);
	tlib_testresult_raw(condition);
	if (!condition) {
		__tlib_log_call(call);
		tlib_log_print(" freed memory allocation %p unexpectedly\n", addr);
	}
}

void	tlib_testmalloc_size(void *addr, size_t expected_size, char *call, ...) {
	size_t	actual_size;
	t_bool	condition;

	actual_size = tlib_mockmalloc_lookup(addr);
	condition = (actual_size == expected_size);
	tlib_testresult_raw(condition);
	if (!condition) {
		__tlib_log_call(call);
		tlib_log_print(" returned a memory allocation of the wrong size\n");
		tlib_log_print("- (expected: %z, returned: %z)\n", expected_size, actual_size);
	}
}

void	tlib_testmissing(void (*test)(void), void *fun, char *section) {
	tlib_log_section(section);
	tlib_print(STDOUT_FILENO, "--- %s ---\n", section);
	if (fun != NULL)
		test();
	else {
		//TODO set separate flag for missing function
		tlib_print(STDOUT_FILENO, "%y[MISSING]%n");
	}
	tlib_print(STDOUT_FILENO, "\n");
}

void	tlib_testprint_capture(int fd) {
	int	fd_out;

	pipe(tlib_testprint_pipe);
	fd_out = dup(fd);
	dup2(tlib_testprint_pipe[1], fd);
	close(tlib_testprint_pipe[1]);
	tlib_testprint_pipe[1] = fd_out;
}

void	tlib_testprint_get(int fd, char *expected, char *call, ...) {
	char	*printed;
	t_bool	condition;

	close(fd);
	dup2(tlib_testprint_pipe[1], fd);
	close(tlib_testprint_pipe[1]);
	if (expected != NULL) {
		printed = tlib_readall(tlib_testprint_pipe[0]);
		condition = tlib_str_cmp(printed, expected);
		tlib_testresult_raw(condition);
		if (!condition) {
			__tlib_log_call(call);
			tlib_log_print(" has printed an incorrect output on file descriptor %d\n", fd);
			tlib_log_print("- (expected: %S, printed: %S)\n", expected, printed);
		}
		free(printed);
	}
	close(tlib_testprint_pipe[0]);
}

static int	tlib_testprocess_run(void (*fun)(void)) {
	pid_t	pid;
	int		status;
	void	(*sighandler)(int);
	int		fd[2];

	sighandler = signal(SIGUSR1, &handle_sigusr);
	pipe(fd);
	pid = fork();
	if (pid == -1)
		return (-1);
	else if (pid == 0) {
		tlib_ischild = TRUE;
		close(fd[0]);
		fun();
		tlib_log_end();
		write(fd[1], &tlib_newsection, sizeof(t_bool));
		exit(0);
	}
	close(fd[1]);
	waitpid(pid, &status, 0);
	signal(SIGUSR1, sighandler);
	read(fd[0], &tlib_newsection, sizeof(t_bool));
	close(fd[0]);
	return (status);
}

void	tlib_testprocess_ok(void (*fun)(void), char *call, ...) {
	int		status;

	status = tlib_testprocess_run(fun);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
		//Expected result, do nothing
	} else if (WIFSIGNALED(status) && WTERMSIG(status) == 11) {
		tlib_test_setfail();
		tlib_print(STDOUT_FILENO, "%r[SEGFAULT]%n");
		__tlib_log_call(call);
		tlib_log_print(" caused a segmentation fault\n");
	} else {
		tlib_test_setfail();
		tlib_print(STDOUT_FILENO, "%r[CRASH]%n");
		__tlib_log_call(call);
		tlib_log_print(" crashed in an unexpected way (status code: %d)\n", status);
	}
}

void	tlib_testprocess_segfault(void (*fun)(void), char *call, ...) {
	int		status;

	status = tlib_testprocess_run(fun);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
		tlib_test_setfail();
		tlib_print(STDOUT_FILENO, "%r[NO CRASH]%n");
		__tlib_log_call(call);
		tlib_log_print(" should have caused a segmentation fault, but didn't\n");
	} else if (WIFSIGNALED(status) && WTERMSIG(status) == 11) {
		tlib_print(STDOUT_FILENO, "%g[OK]%n");
	} else {
		tlib_test_setfail();
		tlib_print(STDOUT_FILENO, "%r[CRASH]%n");
		__tlib_log_call(call);
		tlib_log_print(" crashed in an unexpected way (status code: %d)\n", status);
	}
}

void	tlib_testresult_char(int actual_value, int expected_value, char *call, ...) {
	t_bool	condition;

	condition = (actual_value == expected_value);
	tlib_testresult_raw(condition);
	if (!condition) {
		__tlib_log_call(call);
		tlib_log_print(" returned an incorrect value\n");
		tlib_log_print("- (expected: %c (%d), returned: %c (%d))\n", expected_value, expected_value, actual_value, actual_value);
	}
}

void	tlib_testresult_int(int actual_value, int expected_value, char *call, ...) {
	t_bool	condition;

	condition = (actual_value == expected_value);
	tlib_testresult_raw(condition);
	if (!condition) {
		__tlib_log_call(call);
		tlib_log_print(" returned an incorrect value\n");
		tlib_log_print("- (expected: %d, returned: %d)\n", expected_value, actual_value);
	}
}

void	tlib_testresult_nonzero(int value, char *call, ...) {
	t_bool	condition;

	condition = (value != 0);
	tlib_testresult_raw(condition);
	if (!condition) {
		__tlib_log_call(call);
		tlib_log_print(" returned an incorrect value\n");
		tlib_log_print("- (expected: nonzero, returned: 0)\n");
	}
}

void	tlib_testresult_size(size_t actual_value, size_t expected_value, char *call, ...) {
	t_bool	condition;

	condition = (actual_value == expected_value);
	tlib_testresult_raw(condition);
	if (!condition) {
		__tlib_log_call(call);
		tlib_log_print(" returned an incorrect value\n");
		tlib_log_print("- (expected: %z, returned: %z)\n", expected_value, actual_value);
	}
}

void	tlib_testresult_str(char *actual_value, char *expected_value, char *call, ...) {
	t_bool	condition;

	condition = tlib_str_cmp(actual_value, expected_value);
	tlib_testresult_raw(condition);
	if (!condition) {
		__tlib_log_call(call);
		tlib_log_print(" returned an incorrect string\n");
		tlib_log_print("- (expected: %S, returned: %S)\n", expected_value, actual_value);
	}
}

void	tlib_testresult_addr(void *actual_value, void *expected_value, char *call, ...) {
	t_bool	condition;

	condition = (actual_value == expected_value);
	tlib_testresult_raw(condition);
	if (!condition) {
		__tlib_log_call(call);
		tlib_log_print(" returned an incorrect value\n");
		tlib_log_print("- (expected: %p, returned: %p)\n", expected_value, actual_value);
	}
}

void	tlib_testresult_notnull(void *value, char *call, ...) {
	t_bool	condition;

	condition = (value != NULL);
	tlib_testresult_raw(condition);
	if (!condition) {
		__tlib_log_call(call);
		tlib_log_print(" returned an incorrect value\n");
		tlib_log_print("- (expected: nonnull, returned: NULL)\n");
	}
}

void	tlib_testresult_mem(void *addr, size_t n, unsigned char expected_c, char *call, ...) {
	t_bool	condition;

	condition = tlib_mem_isset(addr, n, expected_c);
	tlib_testresult_raw(condition);
	if (!condition) {
		__tlib_log_call(call);
		tlib_log_print(" did not fill buffer %p of size %z with byte %u\n", addr, n, expected_c);
	}
}

void	tlib_testresult_custom(t_bool condition, char *message, ...) {
	tlib_testresult_raw(condition);
	if (!condition) {
		__tlib_log_call(message);
	}
}

//TODO add message for all OK, but some functions missing
int	tlib_test_results(void) {
	tlib_print(STDOUT_FILENO, "--- FINAL RESULT ---\n");
	if (!tlib_testfailed) {
		tlib_print(STDOUT_FILENO, "%gAll tests OK!\n%n");
		return (EXIT_SUCCESS);
	} else {
		tlib_print(STDOUT_FILENO, "%rErrors detected; for detailed error messages, see %s\n%n", ERRORLOG_FULLFILE);
		return (EXIT_FAILURE);
	}
}
