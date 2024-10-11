#include "test_bonus.h"

static t_bool	lstdelone_testing;
static t_list	*lstdelone_l;
static char		lstdelone_checked[FUNPTR_CHECKED];
static size_t	lstdelone_called;

static void	test_lstdelone_start(t_list *l) {
	size_t	i;

	lstdelone_l = l;
	i = 0;
	while (i < FUNPTR_CHECKED) {
		lstdelone_checked[i] = 0;
		i++;
	}
	lstdelone_called = 0;
	lstdelone_testing = TRUE;
}

static void	test_lstdelone_stop() {
	lstdelone_testing = FALSE;
}

static void	test_lstdelone_del(void *p) {
	char	*addr;

	if (!lstdelone_testing)
		return ;
	addr = (char *)p;
	tlib_testresult_custom(addr >= lstdelone_checked && addr < lstdelone_checked + FUNPTR_CHECKED,
		"ft_lstdelone(%p, %p) called its function with an out of range parameter\n- (expected range: %p - %p, actual: %p)\n", lstdelone_l, &test_lstdelone_del, lstdelone_checked, lstdelone_checked + FUNPTR_CHECKED, addr);
	if (addr >= lstdelone_checked && addr < lstdelone_checked + FUNPTR_CHECKED) {
		tlib_testresult_custom(*addr == 0,
			"ft_lstdelone(%p, %p) has been called multiple times for list element %z\n", lstdelone_l, &test_lstdelone_del, addr - lstdelone_checked);
		*addr = 1;
	}
	lstdelone_called += 1;
}

static void	test_lstdelone_child1(void) {
	t_list	*l;

	tlib_mockmalloc_reset();
	l = taux_lstbuild_range(1, lstdelone_checked);
	test_lstdelone_start(l);
	ft_lstdelone(l, &test_lstdelone_del);
	test_lstdelone_stop();
	tlib_testresult_custom(!tlib_isalloc(l),
		"ft_lstdelone(<list(1)>, %p) did not free the argument node\n", &test_lstdelone_del);
	tlib_testresult_custom(lstdelone_called == 1,
		"ft_lstdelone(<list(1)>, %p) called its function an incorrect number of times\n- (expected: 1 calls, actual: %z calls)\n", &test_lstdelone_del, lstdelone_called);
	taux_free(l);
	tlib_testmalloc_leak("ft_lstdelone(<list(1)>, %p)", &test_lstdelone_del);
}

static void	test_lstdelone_child2(void) {
	t_list	*l1, *l2;

	tlib_mockmalloc_reset();
	l1 = taux_lstbuild_range(2, lstdelone_checked);
	l2 = l1->next;
	test_lstdelone_start(l1);
	ft_lstdelone(l1, &test_lstdelone_del);
	test_lstdelone_stop();
	tlib_testresult_custom(!tlib_isalloc(l1),
		"ft_lstdelone(<list(2)>, %p) did not free the argument node\n", &test_lstdelone_del);
	tlib_testresult_custom(tlib_isalloc(l2),
		"ft_lstdelone(<list(2)>, %p) freed the next node after argument node\n", &test_lstdelone_del);
	tlib_testresult_custom(lstdelone_called == 1,
		"ft_lstdelone(<list(2)>, %p) called its function an incorrect number of times\n- (expected: 1 calls, actual: %z calls)\n", &test_lstdelone_del, lstdelone_called);
	taux_free(l1);
	taux_free(l2);
	tlib_testmalloc_leak("ft_lstdelone(<list(2)>, %p)", &test_lstdelone_del);
}

static void	test_lstdelone_child3(void) {
	tlib_mockmalloc_reset();
	test_lstdelone_start(NULL);
	ft_lstdelone(NULL, &test_lstdelone_del);
	test_lstdelone_stop();
	tlib_testresult_custom(lstdelone_called == 0,
		"ft_lstdelone(NULL, %p) called its function an incorrect number of times\n- (expected: 0 calls, actual: %z calls)\n", &test_lstdelone_del, lstdelone_called);
	tlib_testmalloc_leak("ft_lstdelone(NULL, %p)", &test_lstdelone_del);
}

static void	test_lstdelone_child4(void) {
	t_list	*l;

	tlib_mockmalloc_reset();
	l = taux_lstbuild(1, NULL);
	ft_lstdelone(l, NULL);
	tlib_testresult_custom(tlib_isalloc(l),
		"ft_lstdelone(<list(1)>, NULL) freed its argument node\n");
	taux_free(l);
	tlib_testmalloc_leak("ft_lstdelone(<list(1)>, NULL)");
}

void	test_lstdelone(void) {
	tlib_testprocess_ok(&test_lstdelone_child1, "ft_lstdelone(<list(1)>, %p)", &test_lstdelone_del);
	tlib_testprocess_ok(&test_lstdelone_child2, "ft_lstdelone(<list(2)>, %p)", &test_lstdelone_del);
	tlib_testprocess_ok(&test_lstdelone_child3, "ft_lstdelone(NULL, %p)", &test_lstdelone_del);
	tlib_testprocess_ok(&test_lstdelone_child4, "ft_lstdelone(<list(1)>, NULL)");
}
