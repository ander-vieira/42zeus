#include "test_bonus.h"

static t_bool	lstiter_testing;
static char		*lstiter_call;
static char		lstiter_checked[FUNPTR_CHECKED];
static size_t	lstiter_called;

static void	test_lstiter_start(char *call) {
	size_t	i;

	lstiter_call = call;
	i = 0;
	while (i < FUNPTR_CHECKED) {
		lstiter_checked[i] = 0;
		i++;
	}
	lstiter_called = 0;
	lstiter_testing = TRUE;
}

static void	test_lstiter_stop() {
	lstiter_testing = FALSE;
}

static void	test_lstiter_fun(void *p) {
	char	*addr;

	if (!lstiter_testing)
		return ;
	addr = (char *)p;
	tlib_testresult_custom(addr >= lstiter_checked && addr < lstiter_checked + FUNPTR_CHECKED,
		"%s called <fun> with an out of range parameter\n- (expected range: %p - %p, actual: %p)\n",
		lstiter_call, lstiter_checked, lstiter_checked + FUNPTR_CHECKED, addr);
	if (addr >= lstiter_checked && addr < lstiter_checked + FUNPTR_CHECKED) {
		tlib_testresult_custom(*addr == 0,
			"%s called <fun> multiple times for list element %z\n",
			lstiter_call, addr - lstiter_checked);
		*addr = 1;
	}
	lstiter_called += 1;
}

static void	test_lstiter_child1(void) {
	t_list	*l;

	tlib_mockmalloc_reset();
	l = taux_lstbuild_range(1, lstiter_checked);
	test_lstiter_start("ft_lstiter(<list(1)>, <fun>)");
	ft_lstiter(l, &test_lstiter_fun);
	test_lstiter_stop();
	tlib_testresult_custom(lstiter_called == 1,
		"ft_lstiter(<list(1)>, <fun>) called <fun> an incorrect number of times\n- (expected: 1 calls, actual: %z calls)\n",
		lstiter_called);
	taux_free(l);
	tlib_testmalloc_leak("ft_lstiter(<list(1)>, <fun>)");
}

static void	test_lstiter_child2(void) {
	t_list	*l;

	tlib_mockmalloc_reset();
	l = taux_lstbuild_range(3, lstiter_checked);
	test_lstiter_start("ft_lstiter(<list(3)>, <fun>)");
	ft_lstiter(l, &test_lstiter_fun);
	test_lstiter_stop();
	tlib_testresult_custom(lstiter_called == 3,
		"ft_lstiter(<list(3)>, <fun>) called <fun> an incorrect number of times\n- (expected: 3 calls, actual: %z calls)\n",
		lstiter_called);
	taux_free(l);
	tlib_testmalloc_leak("ft_lstiter(<list(3)>, <fun>)");
}

static void	test_lstiter_child3(void) {
	tlib_mockmalloc_reset();
	test_lstiter_start("ft_lstiter(NULL, <fun>)");
	ft_lstiter(NULL, &test_lstiter_fun);
	test_lstiter_stop();
	tlib_testresult_custom(lstiter_called == 0,
		"ft_lstiter(NULL, <fun>) called <fun> an incorrect number of times\n- (expected: 0 calls, actual: %z calls)\n",
		lstiter_called);
	tlib_testmalloc_leak("ft_lstiter(NULL, <fun>)");
}

static void	test_lstiter_child4(void) {
	t_list	*l;

	tlib_mockmalloc_reset();
	l = taux_lstbuild(1, lstiter_checked);
	ft_lstiter(l, NULL);
	taux_free(l);
	tlib_testmalloc_leak("ft_lstiter(<list(1)>, NULL)");
}

void	test_lstiter(void) {
	tlib_testprocess_ok(&test_lstiter_child1, "ft_lstiter(<list(1)>, <fun>)");
	tlib_testprocess_ok(&test_lstiter_child2, "ft_lstiter(<list(3)>, <fun>)");
	tlib_testprocess_ok(&test_lstiter_child3, "ft_lstiter(NULL, <fun>)");
	tlib_testprocess_ok(&test_lstiter_child4, "ft_lstiter(<list(1)>, NULL)");
}
