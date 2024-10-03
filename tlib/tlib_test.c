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

void	tlib_testmissing(void (*test)(void), void *fun, char *title) {
	tlib_printf(STDOUT_FILENO, "--- %s ---\n", title);
	if (fun != NULL)
		test();
	else {
		tlib_test_setfail();
		tlib_printf(STDOUT_FILENO, "%r[MISSING]%n");
	}
	tlib_printf(STDOUT_FILENO, "\n");
}

void	tlib_testresult_bool(t_bool ok) {
	if (ok)
		tlib_printf(STDOUT_FILENO, "%g[OK]%n");
	else {
		tlib_test_setfail();
		tlib_printf(STDOUT_FILENO, "%r[KO]%n");
		//TODO add error log
	}
}

void	tlib_testmalloc_size(void *addr, size_t expected_size) {
	size_t	actual_size;

	actual_size = tlib_mockmalloc_lookup(addr);
	if (actual_size == expected_size)
		tlib_printf(STDOUT_FILENO, "%g[OK]%n");
	else {
		tlib_test_setfail();
		tlib_printf(STDOUT_FILENO, "%r[KO]%n");
		//TODO add error log
	}
}

void	tlib_testmalloc_count(size_t expected_count) {
	size_t	actual_count;

	actual_count = tlib_mockmalloc_count();
	if (actual_count == expected_count)
		tlib_printf(STDOUT_FILENO, "%g[OK]%n");
	else {
		tlib_test_setfail();
		tlib_printf(STDOUT_FILENO, "%r[KO]%n");
		//TODO add error log
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
		tlib_printf(STDOUT_FILENO, "%r[SEGFAULT]%n");
		//TODO add error log
	} else {
		tlib_test_setfail();
		tlib_printf(STDOUT_FILENO, "%r[CRASH]%n");
		//TODO add error log
	}
}

void	tlib_testprocess_segfault(void (*fun)(void)) {
	int		status;

	status = tlib_testprocess_run(fun);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
		tlib_test_setfail();
		tlib_printf(STDOUT_FILENO, "%r[NO CRASH]%n");
		//TODO add error log
	} else if (WIFSIGNALED(status) && WTERMSIG(status) == 11) {
		tlib_printf(STDOUT_FILENO, "%g[OK]%n");
	} else {
		tlib_test_setfail();
		tlib_printf(STDOUT_FILENO, "%r[CRASH]%n");
		//TODO add error log
	}
}

int	tlib_test_results(void) {
	tlib_printf(STDOUT_FILENO, "--- FINAL RESULT ---\n");
	if (!tlib_testfailed) {
		tlib_printf(STDOUT_FILENO, "%gAll tests OK!\n%n");
		return (EXIT_SUCCESS);
	} else {
		tlib_printf(STDOUT_FILENO, "%rErrors detected, please review.\n%n");
		return (EXIT_FAILURE);
	}
}
