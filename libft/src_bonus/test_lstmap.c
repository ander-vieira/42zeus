#include "test_bonus.h"

static t_bool	lstmap_testing;
static t_list	*lstmap_l;
static char		lstmap_fun_checked[FUNPTR_CHECKED];
static char		lstmap_del_checked[FUNPTR_CHECKED];
static size_t	lstmap_fun_called;
static size_t	lstmap_del_called;

static void	test_lstmap_start(t_list *l) {
	size_t	i;

	lstmap_l = l;
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
			"ft_lstmap(%p, %p, %p) called its function fun with an out of range parameter\n- (expected range: %p - %p, actual: %p)\n", lstmap_l, &test_lstmap_fun, &test_lstmap_del, lstmap_fun_checked, lstmap_fun_checked + FUNPTR_CHECKED, addr);
		if (addr >= lstmap_fun_checked && addr < lstmap_fun_checked + FUNPTR_CHECKED) {
			tlib_testresult_custom(*addr == 0,
				"ft_lstmap(%p, %p, %p) called its function fun multiple times for list element %z\n", lstmap_l, &test_lstmap_fun, &test_lstmap_del, addr - lstmap_fun_checked);
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
		"ft_lstmap(%p, %p, %p) called its function del with an out of range parameter\n- (expected range: %p - %p, actual: %p)\n", lstmap_l, &test_lstmap_fun, &test_lstmap_del, lstmap_del_checked, lstmap_del_checked + FUNPTR_CHECKED, addr);
	if (addr >= lstmap_del_checked && addr < lstmap_del_checked + FUNPTR_CHECKED) {
		tlib_testresult_custom(*(lstmap_fun_checked + (addr - lstmap_del_checked)) == 1,
			"ft_lstmap(%p, %p, %p) called its function del without calling fun on list element %z\n", lstmap_l, &test_lstmap_fun, &test_lstmap_del, addr - lstmap_fun_checked);
		tlib_testresult_custom(*addr == 0,
			"ft_lstmap(%p, %p, %p) called its function del multiple times for list element %z\n", lstmap_l, &test_lstmap_fun, &test_lstmap_del, addr - lstmap_fun_checked);
		*addr = 1;
	}
	lstmap_del_called += 1;
}

static void	test_lstmap_child1(void) {
	t_list	*l1, *l2;

	tlib_mockmalloc_reset();
	l1 = taux_lstbuild_range(1, lstmap_fun_checked);
	test_lstmap_start(l1);
	l2 = ft_lstmap(l1, &test_lstmap_fun, &test_lstmap_del);
	test_lstmap_stop();
	tlib_testresult_notnull(l2, "ft_lstmap(%p, %p, %p)", l1, &test_lstmap_fun, &test_lstmap_del);
	tlib_testresult_custom(taux_lstcheck_range(l2, 1, lstmap_del_checked),
		"ft_lstmap(%p, %p, %p) did not return the correct list\n");
	tlib_testresult_custom(lstmap_fun_called == 1,
		"ft_lstmap(%p, %p, %p) called its function fun an incorrect number of times\n- (expected: 1 calls, actual: %z calls)\n", l1, &test_lstmap_fun, &test_lstmap_del, lstmap_fun_called);
	tlib_testresult_custom(lstmap_del_called == 0,
		"ft_lstmap(%p, %p, %p) called its function del an incorrect number of times\n- (expected: 0 calls, actual: %z calls)\n", l1, &test_lstmap_fun, &test_lstmap_del, lstmap_del_called);
	taux_free(l1);
	taux_free(l2);
	tlib_testmalloc_leak("ft_lstmap(%p, %p, %p)", l1, &test_lstmap_fun, &test_lstmap_del);
}

// static void	test_lstmap_child2(void) {
// 	t_list	*l;
// 	t_list	*l1;
// 	t_list	*l2;

// 	tlib_mockmalloc_reset();
// 	taux_parg_init(&g_parg, 2, &l1, &l2);
// 	taux_pget_init(&g_pget, 2, &l, &l + 1);
// 	l1 = taux_lstnew(&l1);
// 	l2 = taux_lstnew(&l2);
// 	l1->next = l2;
// 	tlib_mockmalloc_setmock(1);
// 	l = ft_lstmap(l1, &test_lstmap_fun, &test_lstmap_del);
// 	tlib_testresult_raw(l1->next == l2 && l2->next == NULL);
// 	tlib_testresult_raw(l == NULL);
// 	tlib_testresult_raw(taux_parg_ok(g_parg));
// 	tlib_testresult_raw(taux_pget_ok(g_pget));
// 	tlib_testmalloc_size(l1, sizeof(t_list), "ft_lstmap(TODO)");
// 	tlib_testmalloc_size(l2, sizeof(t_list), "ft_lstmap(TODO)");
// 	free(l1);
// 	free(l2);
// 	tlib_testmalloc_leak(NULL);
// }

// static void	test_lstmap_child3(void) {
// 	t_list	*l;
// 	t_list	*l1;
// 	t_list	*l2;

// 	tlib_mockmalloc_reset();
// 	taux_parg_init(&g_parg, 2, &l1, &l2);
// 	taux_pget_init(&g_pget, 2, &l, &l + 1);
// 	l1 = taux_lstnew(&l1);
// 	l2 = taux_lstnew(&l2);
// 	l1->next = l2;
// 	tlib_mockmalloc_setmock(2);
// 	l = ft_lstmap(l1, &test_lstmap_fun, &test_lstmap_del);
// 	tlib_testresult_raw(l1->next == l2 && l2->next == NULL);
// 	tlib_testresult_raw(l == NULL);
// 	tlib_testresult_raw(taux_parg_ok(g_parg));
// 	tlib_testresult_raw(taux_pget_ok(g_pget));
// 	tlib_testmalloc_size(l1, sizeof(t_list), "ft_lstmap(TODO)");
// 	tlib_testmalloc_size(l2, sizeof(t_list), "ft_lstmap(TODO)");
// 	free(l1);
// 	free(l2);
// 	tlib_testmalloc_leak(NULL);
// }

// static void	test_lstmap_child4(void) {
// 	t_list	*l;

// 	tlib_mockmalloc_reset();
// 	taux_parg_init(&g_parg, 0);
// 	taux_pget_init(&g_pget, 0);
// 	l = ft_lstmap(NULL, &test_lstmap_fun, &test_lstmap_del);
// 	tlib_testresult_raw(l == NULL);
// 	tlib_testresult_raw(taux_parg_ok(g_parg));
// 	tlib_testresult_raw(g_parg.i == 0);
// 	tlib_testresult_raw(taux_pget_ok(g_pget));
// 	tlib_testmalloc_leak(NULL);
// }

// static void	test_lstmap_child5(void) {
// 	t_list	*l;
// 	t_list	*l1;

// 	tlib_mockmalloc_reset();
// 	taux_pget_init(&g_pget, 0);
// 	l1 = taux_lstnew(&l1);
// 	l = ft_lstmap(l1, NULL, &test_lstmap_del);
// 	tlib_testresult_raw(l1->next == NULL);
// 	tlib_testresult_raw(l == NULL);
// 	tlib_testresult_raw(taux_pget_ok(g_pget));
// 	tlib_testresult_raw(g_pget.j == 0);
// 	tlib_testmalloc_size(l1, sizeof(t_list), "ft_lstmap(TODO)");
// 	free(l1);
// 	tlib_testmalloc_leak(NULL);
// }

// static void	test_lstmap_child6(void) {
// 	t_list	*l;
// 	t_list	*l1;

// 	tlib_mockmalloc_reset();
// 	taux_parg_init(&g_parg, 0);
// 	taux_pget_init(&g_pget, 0);
// 	l1 = taux_lstnew(&l1);
// 	l = ft_lstmap(l1, &test_lstmap_fun, NULL);
// 	tlib_testresult_raw(l1->next == NULL);
// 	tlib_testresult_raw(l == NULL);
// 	tlib_testresult_raw(taux_parg_ok(g_parg));
// 	tlib_testresult_raw(g_parg.i == 0);
// 	tlib_testresult_raw(taux_pget_ok(g_pget));
// 	tlib_testmalloc_size(l1, sizeof(t_list), "ft_lstmap(TODO)");
// 	free(l1);
// 	tlib_testmalloc_leak(NULL);
// }

void	test_lstmap(void) {
	tlib_testprocess_ok(&test_lstmap_child1);
	// tlib_testprocess_ok(&test_lstmap_child2);
	// tlib_testprocess_ok(&test_lstmap_child3);
	// tlib_testprocess_ok(&test_lstmap_child4);
	// tlib_testprocess_ok(&test_lstmap_child5);
	// tlib_testprocess_ok(&test_lstmap_child6);
}
