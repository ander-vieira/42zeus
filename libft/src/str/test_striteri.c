#include "test.h"

//TODO upgrade tests

static t_bool	striteri_testing;
static char		striteri_str[5];
static size_t	striteri_str_len;
static char		striteri_checked[5];
static size_t	striteri_called;

static void	test_striteri_start(char *str) {
	size_t	i;

	tlib_str_cpy(striteri_str, str);
	striteri_str_len = tlib_str_len(str);
	i = 0;
	while (i < striteri_str_len) {
		striteri_checked[i] = 0;
		i++;
	}
	striteri_called = 0;
	striteri_testing = TRUE;
}

static void	test_striteri_stop() {
	striteri_testing = FALSE;
}

static void	test_striteri_fun(unsigned int i, char *c) {
	if (!striteri_testing)
		return ;
	tlib_testresult_custom(i < striteri_str_len,
		"ft_striteri(%S, %p) has been called with an out of bounds index (%d)\n", striteri_str, &test_striteri_fun, i);
	tlib_testresult_custom(c == striteri_str + i,
		"ft_striteri(%S, %p) has been called with an incorrect parameter\n- (expected: %p, actual: %p)\n", striteri_str, &test_striteri_fun, striteri_str + i, c);
	if (i < striteri_str_len) {
		tlib_testresult_custom(striteri_checked[i] == 0,
			"ft_striteri(%S, %p) has been called multiple times on position %u\n", striteri_str, &test_striteri_fun, i);
		striteri_checked[i] = 1;
	}
	striteri_called += 1;
}

static void	test_striteri_testone(char *str) {
	tlib_mockmalloc_reset();
	test_striteri_start(str);
	ft_striteri(striteri_str, &test_striteri_fun);
	test_striteri_stop();
	tlib_testresult_custom(striteri_called == tlib_str_len(str),
		"ft_striteri(%S, %p) has been called an incorrect number of times\n- (expected: %z calls, actual: %z calls)\n", str, &test_striteri_fun, tlib_str_len(str), striteri_called);
	tlib_testmalloc_leak("ft_striteri(%S, %p)", str, &test_striteri_fun);
}

static void	test_striteri_child1(void) {
	test_striteri_testone("HOLA");
	test_striteri_testone("");
}

static void	test_striteri_child2(void) {
	striteri_testing = FALSE;
	ft_striteri(NULL, &test_striteri_fun);
}

static void	test_striteri_child3(void) {
	ft_striteri("HOLA", NULL);
}

void	test_striteri(void) {
	tlib_testprocess_ok(&test_striteri_child1);
	tlib_testprocess_ok(&test_striteri_child2);
	tlib_testprocess_ok(&test_striteri_child3);
}
