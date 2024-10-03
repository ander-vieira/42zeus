#include "tlib_int.h"

t_bool	tlib_ischild;
t_bool	tlib_testfailed;

static void	tlib_test_setfail() {
	if (tlib_ischild)
		kill(getppid(), SIGUSR1);
	else
		tlib_testfailed = TRUE;
}

static void	handle_sigusr(int signal) {
	tlib_test_setfail();
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

void	tlib_testresult_raw(t_bool ok) {
	if (ok)
		tlib_print(STDOUT_FILENO, "%g[OK]%n");
	else {
		tlib_test_setfail();
		tlib_print(STDOUT_FILENO, "%r[KO]%n");
	}
}

void	tlib_testresult_true(int value, char *call, ...) {
	t_bool	condition;

	condition = (value != 0);
	tlib_testresult_raw(condition);
	if (!condition) {
		__tlib_log_call(call);
		tlib_log_print(" has returned an incorrect value\n");
		tlib_log_print("- (expected: nonzero, returned: 0)\n");
	}
}

void	tlib_testresult_false(int value, char *call, ...) {
	t_bool	condition;

	condition = (value == 0);
	tlib_testresult_raw(condition);
	if (!condition) {
		__tlib_log_call(call);
		tlib_log_print(" has returned an incorrect value\n");
		tlib_log_print("- (expected: 0, returned: nonzero)\n");
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

void	tlib_testmalloc_size(void *addr, size_t expected_size, char *call, ...) {
	size_t	actual_size;
	t_bool	condition;

	actual_size = tlib_mockmalloc_lookup(addr);
	condition = (actual_size == expected_size);
	tlib_testresult_raw(condition);
	if (!condition) {
		__tlib_log_call(call);
		tlib_log_print(" has returned a memory allocation of the wrong size\n");
		tlib_log_print("- (expected: %z, returned: %z)\n", expected_size, actual_size);
	}
}

static int	tlib_testprocess_run(void (*fun)(void)) {
	pid_t	pid;
	int		status;
	void	(*sighandler)(int);

	sighandler = signal(SIGUSR1, &handle_sigusr);
	pid = fork();
	if (pid == -1)
		return (-1);
	else if (pid == 0) {
		tlib_ischild = TRUE;
		fun();
		tlib_log_end();
		exit(0);
	}
	waitpid(pid, &status, 0);
	signal(SIGUSR1, sighandler);
	return (status);
}

void	tlib_testprocess_ok(void (*fun)(void)) {
	int		status;

	status = tlib_testprocess_run(fun);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
		//Expected result, do nothing
	} else if (WIFSIGNALED(status) && WTERMSIG(status) == 11) {
		tlib_test_setfail();
		tlib_print(STDOUT_FILENO, "%r[SEGFAULT]%n");
		tlib_log_print("A function call caused a segmentation fault\n");
		tlib_log_print("- This is likely caused by a missing null check\n");
	} else {
		tlib_test_setfail();
		tlib_print(STDOUT_FILENO, "%r[CRASH]%n");
		tlib_log_print("A function call crashed in an unexpected way (status code: %d)\n", status);
	}
}

void	tlib_testprocess_segfault(void (*fun)(void)) {
	int		status;

	status = tlib_testprocess_run(fun);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
		tlib_test_setfail();
		tlib_print(STDOUT_FILENO, "%r[NO CRASH]%n");
		tlib_log_print("A function call should have caused a segmentation fault, but didn't\n");
		tlib_log_print("This is likely caused by an unnecessary null check\n");
	} else if (WIFSIGNALED(status) && WTERMSIG(status) == 11) {
		tlib_print(STDOUT_FILENO, "%g[OK]%n");
	} else {
		tlib_test_setfail();
		tlib_print(STDOUT_FILENO, "%r[CRASH]%n");
		tlib_log_print("A function call crashed in an unexpected way (status code: %d)\n", status);
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
