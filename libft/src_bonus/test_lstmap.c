#include "test_bonus.h"

static t_bool	lstmap_testing;
static char		*lstmap_call;
static char		lstmap_fun_checked[FUNPTR_CHECKED];
static char		lstmap_del_checked[FUNPTR_CHECKED];
static size_t	lstmap_fun_called;
static size_t	lstmap_del_called;

static void	test_lstmap_start(char *call) {
	size_t	i;

	lstmap_call = call;
	i = 0;
	while (i < FUNPTR_CHECKED) {
		lstmap_fun_checked[i] = 0;
		lstmap_del_checked[i] = 0;
		i++;
	}
	lstmap_fun_called = 0;
	lstmap_del_called = 0;
	lstmap_testing = TRUE;
}

static void	test_lstmap_stop() {
	lstmap_testing = FALSE;
}

static void	test_lstmap_del(void *p);

static void	*test_lstmap_fun(void *p) {
	char	*addr;

	if (lstmap_testing) {
		addr = (char *)p;
		tlib_testresult_custom(addr >= lstmap_fun_checked && addr < lstmap_fun_checked + FUNPTR_CHECKED,
			"%s called <fun> with an out of range parameter\n- (expected range: %p - %p, actual: %p)\n",
			lstmap_call, lstmap_fun_checked, lstmap_fun_checked + FUNPTR_CHECKED, addr);
		if (addr >= lstmap_fun_checked && addr < lstmap_fun_checked + FUNPTR_CHECKED) {
			tlib_testresult_custom(*addr == 0,
				"%s called <fun> multiple times for list element %z\n",
				lstmap_call, addr - lstmap_fun_checked);
			*addr = 1;
		}
		lstmap_fun_called += 1;
	}
	return (lstmap_del_checked + (addr - lstmap_fun_checked));
}

static void	test_lstmap_del(void *p) {
	char	*addr;

	if (!lstmap_testing)
		return ;
	addr = (char *)p;
	tlib_testresult_custom(addr >= lstmap_del_checked && addr < lstmap_del_checked + FUNPTR_CHECKED,
		"%s called <del> with an out of range parameter\n- (expected range: %p - %p, actual: %p)\n",
		lstmap_call, lstmap_del_checked, lstmap_del_checked + FUNPTR_CHECKED, addr);
	if (addr >= lstmap_del_checked && addr < lstmap_del_checked + FUNPTR_CHECKED) {
		tlib_testresult_custom(*(lstmap_fun_checked + (addr - lstmap_del_checked)) == 1,
			"%s called <del> without calling <fun> on list element %z\n",
			lstmap_call, addr - lstmap_fun_checked);
		tlib_testresult_custom(*addr == 0,
			"%s called <del> multiple times for list element %z\n",
			lstmap_call, addr - lstmap_fun_checked);
		*addr = 1;
	}
	lstmap_del_called += 1;
}

static void	test_lstmap_child1(void) {
	t_list	*l1, *l2;

	tlib_mockmalloc_reset();
	l1 = taux_lstbuild_range(1, lstmap_fun_checked);
	test_lstmap_start("ft_lstmap(<list(1)>, <fun>, <del>)");
	l2 = ft_lstmap(l1, &test_lstmap_fun, &test_lstmap_del);
	test_lstmap_stop();
	tlib_testresult_notnull(l2, "ft_lstmap(<list(1)>, <fun>, <del>)");
	tlib_testresult_custom(taux_lstcheck_range(l2, 1, lstmap_del_checked),
		"ft_lstmap(<list(1)>, <fun>, <del>) did not return the correct list\n");
	tlib_testresult_custom(lstmap_fun_called == 1,
		"ft_lstmap(<list(1)>, <fun>, <del>) called <fun> an incorrect number of times\n- (expected: 1 calls, actual: %z calls)\n",
		lstmap_fun_called);
	tlib_testresult_custom(lstmap_del_called == 0,
		"ft_lstmap(<list(1)>, <fun>, <del>) called <del> an incorrect number of times\n- (expected: 0 calls, actual: %z calls)\n",
		lstmap_del_called);
	taux_free(l1);
	taux_free(l2);
	tlib_testmalloc_leak("ft_lstmap(<list(1)>, <fun>, <del>)");
}

static void	test_lstmap_child2(void) {
	t_list	*l1, *l2;

	tlib_mockmalloc_reset();
	l1 = taux_lstbuild_range(3, lstmap_fun_checked);
	test_lstmap_start("ft_lstmap(<list(3)>, <fun>, <del>)");
	l2 = ft_lstmap(l1, &test_lstmap_fun, &test_lstmap_del);
	test_lstmap_stop();
	tlib_testresult_notnull(l2, "ft_lstmap(<list(3)>, <fun>, <del>)");
	tlib_testresult_custom(taux_lstcheck_range(l2, 3, lstmap_del_checked),
		"ft_lstmap(<list(3)>, <fun>, <del>) did not return the correct list\n");
	tlib_testresult_custom(lstmap_fun_called == 3,
		"ft_lstmap(<list(3)>, <fun>, <del>) called <fun> an incorrect number of times\n- (expected: 3 calls, actual: %z calls)\n",
		lstmap_fun_called);
	tlib_testresult_custom(lstmap_del_called == 0,
		"ft_lstmap(<list(3)>, <fun>, <del>) called <del> an incorrect number of times\n- (expected: 0 calls, actual: %z calls)\n",
		lstmap_del_called);
	taux_free(l1);
	taux_free(l2);
	tlib_testmalloc_leak("ft_lstmap(<list(3)>, <fun>, <del>)");
}

static void	test_lstmap_child3(void) {
	t_list	*l1, *l2;

	tlib_mockmalloc_reset();
	l1 = taux_lstbuild_range(3, lstmap_fun_checked);
	test_lstmap_start("ft_lstmap(<list(3)>, <fun>, <del>) (with malloc 1 fail)");
	tlib_mockmalloc_setmock(1);
	l2 = ft_lstmap(l1, &test_lstmap_fun, &test_lstmap_del);
	test_lstmap_stop();
	tlib_testresult_addr(l2, NULL, "ft_lstmap(<list(3)>, <fun>, <del>) (with malloc 1 fail)");
	tlib_testresult_custom(lstmap_fun_called == lstmap_del_called,
		"ft_lstmap(<list(3)>, <fun>, <del>) (with malloc 1 fail) didn't call <del> for every time it called <fun>\n- (<fun>: %z calls, <del>: %z calls)\n",
		lstmap_fun_called, lstmap_del_called);
	taux_free(l1);
	taux_free(l2);
	tlib_testmalloc_leak("ft_lstmap(<list(3)>, <fun>, <del>) (with malloc 1 fail)");
}

static void	test_lstmap_child4(void) {
	t_list	*l1, *l2;

	tlib_mockmalloc_reset();
	l1 = taux_lstbuild_range(3, lstmap_fun_checked);
	test_lstmap_start("ft_lstmap(<list(3)>, <fun>, <del>) (with malloc 2 fail)");
	tlib_mockmalloc_setmock(2);
	l2 = ft_lstmap(l1, &test_lstmap_fun, &test_lstmap_del);
	test_lstmap_stop();
	tlib_testresult_addr(l2, NULL, "ft_lstmap(<list(3)>, <fun>, <del>) (with malloc 2 fail)");
	tlib_testresult_custom(lstmap_fun_called == lstmap_del_called,
		"ft_lstmap(<list(3)>, <fun>, <del>) (with malloc 2 fail) didn't call <del> for every time it called <fun>\n- (<fun>: %z calls, <del>: %z calls)\n",
		lstmap_fun_called, lstmap_del_called);
	taux_free(l1);
	taux_free(l2);
	tlib_testmalloc_leak("ft_lstmap(<list(3)>, <fun>, <del>) (with malloc 2 fail)");
}

static void	test_lstmap_child5(void) {
	t_list	*l;

	tlib_mockmalloc_reset();
	test_lstmap_start("ft_lstmap(NULL, <fun>, <del>)");
	l = ft_lstmap(NULL, &test_lstmap_fun, &test_lstmap_del);
	test_lstmap_stop();
	tlib_testresult_addr(l, NULL, "ft_lstmap(NULL, <fun>, <del>)");
	tlib_testresult_custom(lstmap_fun_called == 0,
		"ft_lstmap(NULL, <fun>, <del>) called <fun> an incorrect number of times\n- (expected: 0 calls, actual: %z calls)\n",
		lstmap_fun_called);
	tlib_testresult_custom(lstmap_del_called == 0,
		"ft_lstmap(NULL, <fun>, <del>) called <del> an incorrect number of times\n- (expected: 0 calls, actual: %z calls)\n",
		lstmap_del_called);
	taux_free(l);
	tlib_testmalloc_leak("ft_lstmap(NULL, <fun>, <del>)");
}

static void	test_lstmap_child6(void) {
	t_list	*l1, *l2;

	tlib_mockmalloc_reset();
	l1 = taux_lstbuild_range(1, lstmap_fun_checked);
	test_lstmap_start("ft_lstmap(<list(1)>, NULL, <del>)");
	l2 = ft_lstmap(l1, NULL, &test_lstmap_del);
	test_lstmap_stop();
	tlib_testresult_addr(l2, NULL, "ft_lstmap(<list(1)>, NULL, <del>)");
	tlib_testresult_custom(lstmap_del_called == 0,
		"ft_lstmap(<list(1)>, NULL, <del>) called <del> an incorrect number of times\n- (expected: 0 calls, actual: %z calls)\n",
		lstmap_del_called);
	taux_free(l1);
	taux_free(l2);
	tlib_testmalloc_leak("ft_lstmap(<list(1)>, NULL, <del>)");
}

static void	test_lstmap_child7(void) {
	t_list	*l1, *l2;

	tlib_mockmalloc_reset();
	l1 = taux_lstbuild_range(1, lstmap_fun_checked);
	test_lstmap_start("ft_lstmap(<list(1)>, <fun>, NULL)");
	l2 = ft_lstmap(l1, &test_lstmap_fun, NULL);
	test_lstmap_stop();
	tlib_testresult_addr(l2, NULL, "ft_lstmap(<list(1)>, <fun>, NULL)");
	tlib_testresult_custom(lstmap_fun_called == 0,
		"ft_lstmap(<list(1)>, <fun>, NULL) called <fun> an incorrect number of times\n- (expected: 0 calls, actual: %z calls)\n",
		lstmap_fun_called);
	taux_free(l1);
	taux_free(l2);
	tlib_testmalloc_leak("ft_lstmap(<list(1)>, <fun>, NULL)");
}

void	test_lstmap(void) {
	tlib_testprocess_ok(&test_lstmap_child1, "ft_lstmap(<list(1)>, <fun>, <del>)");
	tlib_testprocess_ok(&test_lstmap_child2, "ft_lstmap(<list(3)>, <fun>, <del>)");
	tlib_testprocess_ok(&test_lstmap_child3, "ft_lstmap(<list(3)>, <fun>, <del>) (with malloc 1 fail)");
	tlib_testprocess_ok(&test_lstmap_child4, "ft_lstmap(<list(3)>, <fun>, <del>) (with malloc 2 fail)");
	tlib_testprocess_ok(&test_lstmap_child5, "ft_lstmap(NULL, <fun>, <del>)");
	tlib_testprocess_ok(&test_lstmap_child6, "ft_lstmap(<list(1)>, NULL, <del>)");
	tlib_testprocess_ok(&test_lstmap_child7, "ft_lstmap(<list(1)>, <fun>, NULL)");
}
