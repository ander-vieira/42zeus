#include "test_bonus.h"

static t_bool	lstclear_testing;
static t_list	**lstclear_l;
static char		lstclear_checked[FUNPTR_CHECKED];
static size_t	lstclear_called;

static void	test_lstclear_start(t_list **l) {
	size_t	i;

	lstclear_l = l;
	lstclear_called = 0;
	i = 0;
	while (i < FUNPTR_CHECKED) {
		lstclear_checked[i] = 0;
		i++;
	}
	lstclear_testing = TRUE;
}

static void	test_lstclear_stop() {
	lstclear_testing = FALSE;
}

static void	test_lstclear_del(void *p) {
	char	*addr;

	if (!lstclear_testing)
		return ;
	addr = (char *)p;
	tlib_testresult_custom(addr >= lstclear_checked && addr < lstclear_checked + FUNPTR_CHECKED,
		"ft_lstclear(%p, %p) called its function with an out of range parameter\n- (expected range: %p - %p, actual: %p)\n", lstclear_l, &test_lstclear_del, lstclear_checked, lstclear_checked + FUNPTR_CHECKED, addr);
	if (addr >= lstclear_checked && addr < lstclear_checked + FUNPTR_CHECKED) {
		tlib_testresult_custom(*addr == 0,
			"ft_lstclear(%p, %p) has been called multiple times for list element %z\n", lstclear_l, &test_lstclear_del, addr - lstclear_checked);
		*addr = 1;
	}
	lstclear_called += 1;
}

static void	test_lstclear_child1(void) {
	t_list	*l, *l1;

	tlib_mockmalloc_reset();
	l1 = taux_lstbuild_range(1, lstclear_checked);
	l = l1;
	test_lstclear_start(&l);
	ft_lstclear(&l, &test_lstclear_del);
	test_lstclear_stop();
	tlib_testresult_addr(l, NULL, "ft_lstclear(%p, %p)", &l, &test_lstclear_del);
	tlib_testresult_custom(!tlib_isalloc(l1),
		"ft_lstclear(%p, %p) did not free the argument list\n", &l, &test_lstclear_del);
	tlib_testresult_custom(lstclear_called == 1,
		"ft_lstclear(%p, %p) called its function an incorrect number of times\n- (expected: 1 calls, actual: %z calls)\n", &l, &test_lstclear_del, lstclear_called);
	taux_free(l1);
	tlib_testmalloc_leak("ft_lstclear(%p, %p)", &l, &test_lstclear_del);
}

static void test_lstclear_child2(void) {
	t_list	*l, *l1;

	tlib_mockmalloc_reset();
	l1 = taux_lstbuild_range(2, lstclear_checked);
	l = l1;
	test_lstclear_start(&l);
	ft_lstclear(&l, &test_lstclear_del);
	test_lstclear_stop();
	tlib_testresult_addr(l, NULL, "ft_lstclear(%p, %p)", &l, &test_lstclear_del);
	tlib_testresult_custom(!tlib_isalloc(l1),
		"ft_lstclear(%p, %p) did not free the argument list\n", &l, &test_lstclear_del);
	tlib_testresult_custom(lstclear_called == 2,
		"ft_lstclear(%p, %p) called its function an incorrect number of times\n- (expected: 2 calls, actual: %z calls)\n", &l, &test_lstclear_del, lstclear_called);
	taux_free(l1);
	tlib_testmalloc_leak("ft_lstclear(%p, %p)", &l, &test_lstclear_del);
}

static void	test_lstclear_child3(void) {
	t_list	*l;

	tlib_mockmalloc_reset();
	l = NULL;
	test_lstclear_start(&l);
	ft_lstclear(&l, &test_lstclear_del);
	test_lstclear_stop();
	tlib_testresult_addr(l, NULL, "ft_lstclear(%p, %p)", &l, &test_lstclear_del);
	tlib_testresult_custom(lstclear_called == 0,
		"ft_lstclear(%p, %p) called its function an incorrect number of times\n- (expected: 0 calls, actual: %z calls)\n", &l, &test_lstclear_del, lstclear_called);
	tlib_testmalloc_leak("ft_lstclear(%p, %p)", &l, &test_lstclear_del);
}

static void	test_lstclear_child4(void) {
	tlib_mockmalloc_reset();
	test_lstclear_start(NULL);
	ft_lstclear(NULL, &test_lstclear_del);
	test_lstclear_stop();
	tlib_testresult_custom(lstclear_called == 0,
		"ft_lstclear(NULL, %p) called its function an incorrect number of times\n- (expected: 0 calls, actual: %z calls)\n", &test_lstclear_del, lstclear_called);
	tlib_testmalloc_leak("ft_lstclear(NULL, %p)", &test_lstclear_del);
}

static void	test_lstclear_child5(void) {
	t_list	*l, *l1;

	tlib_mockmalloc_reset();
	l1 = taux_lstbuild(1, &lstclear_called);
	l = l1;
	ft_lstclear(&l, NULL);
	tlib_testresult_notnull(l, "ft_lstclear(%p, NULL)", &l);
	tlib_testresult_custom(tlib_isalloc(l1),
		"ft_lstclear(%p, NULL) freed the argument list\n", &l);
	taux_free(l1);
	tlib_testmalloc_leak("ft_lstclear(%p, NULL)", &l);
}

void	test_lstclear(void) {
	tlib_testprocess_ok(&test_lstclear_child1);
	tlib_testprocess_ok(&test_lstclear_child2);
	tlib_testprocess_ok(&test_lstclear_child3);
	tlib_testprocess_ok(&test_lstclear_child4);
	tlib_testprocess_ok(&test_lstclear_child5);
}
