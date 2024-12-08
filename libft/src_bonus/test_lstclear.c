#include "test_bonus.h"

static t_bool	lstclear_testing;
static char		*lstclear_param;
static char		lstclear_checked[FUNPTR_CHECKED];
static size_t	lstclear_called;

static void	test_lstclear_start(char *param) {
	size_t	i;

	lstclear_param = param;
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
		"ft_lstclear(%s, <del>) called its function with an out of range parameter\n- (expected range: %p - %p, actual: %p)\n",
		lstclear_param, lstclear_checked, lstclear_checked + FUNPTR_CHECKED, addr);
	if (addr >= lstclear_checked && addr < lstclear_checked + FUNPTR_CHECKED) {
		tlib_testresult_custom(*addr == 0,
			"ft_lstclear(%s, <del>) has been called multiple times for list element %z\n",
			lstclear_param, addr - lstclear_checked);
		*addr = 1;
	}
	lstclear_called += 1;
}

static void	test_lstclear_child1(void) {
	t_list	*l, *l1;

	tlib_mockmalloc_reset();
	l1 = taux_lstbuild_range(1, lstclear_checked);
	l = l1;
	test_lstclear_start("&<list(1)>");
	ft_lstclear(&l, &test_lstclear_del);
	test_lstclear_stop();
	tlib_testresult_addr(l, NULL, "ft_lstclear(&<list(1)>, <del>)");
	tlib_testresult_custom(!tlib_isalloc(l1),
		"ft_lstclear(&<list(1)>, <del>) did not free the argument list\n");
	tlib_testresult_custom(lstclear_called == 1,
		"ft_lstclear(&<list(1)>, <del>) called <del> an incorrect number of times\n- (expected: 1 calls, actual: %z calls)\n",
		lstclear_called);
	taux_free(l1);
	tlib_testmalloc_leak("ft_lstclear(&<list(1)>, <del>)");
}

static void test_lstclear_child2(void) {
	t_list	*l, *l1;

	tlib_mockmalloc_reset();
	l1 = taux_lstbuild_range(2, lstclear_checked);
	l = l1;
	test_lstclear_start("&<list(2)>");
	ft_lstclear(&l, &test_lstclear_del);
	test_lstclear_stop();
	tlib_testresult_addr(l, NULL, "ft_lstclear(&<list(2)>, <del>)");
	tlib_testresult_custom(!tlib_isalloc(l1),
		"ft_lstclear(&<list(2)>, <del>) did not free the argument list\n");
	tlib_testresult_custom(lstclear_called == 2,
		"ft_lstclear(&<list(2)>, <del>) called <del> an incorrect number of times\n- (expected: 2 calls, actual: %z calls)\n",
		lstclear_called);
	taux_free(l1);
	tlib_testmalloc_leak("ft_lstclear(&<list(2)>, <del>)");
}

static void	test_lstclear_child3(void) {
	t_list	*l;

	tlib_mockmalloc_reset();
	l = NULL;
	test_lstclear_start("&NULL");
	ft_lstclear(&l, &test_lstclear_del);
	test_lstclear_stop();
	tlib_testresult_addr(l, NULL, "ft_lstclear(&NULL, <del>)");
	tlib_testresult_custom(lstclear_called == 0,
		"ft_lstclear(&NULL, <del>) called <del> an incorrect number of times\n- (expected: 0 calls, actual: %z calls)\n",
		lstclear_called);
	tlib_testmalloc_leak("ft_lstclear(&NULL, <del>)");
}

static void	test_lstclear_child4(void) {
	tlib_mockmalloc_reset();
	test_lstclear_start("NULL");
	ft_lstclear(NULL, &test_lstclear_del);
	test_lstclear_stop();
	tlib_testresult_custom(lstclear_called == 0,
		"ft_lstclear(NULL, <del>) called its function an incorrect number of times\n- (expected: 0 calls, actual: %z calls)\n",
		lstclear_called);
	tlib_testmalloc_leak("ft_lstclear(NULL, <del>)");
}

static void	test_lstclear_child5(void) {
	t_list	*l, *l1;

	tlib_mockmalloc_reset();
	l1 = taux_lstbuild(1, &lstclear_called);
	l = l1;
	ft_lstclear(&l, NULL);
	tlib_testresult_notnull(l, "ft_lstclear(&<list(1)>, NULL)");
	tlib_testresult_custom(tlib_isalloc(l1),
		"ft_lstclear(&<list(1)>, NULL) freed the argument list\n");
	taux_free(l1);
	tlib_testmalloc_leak("ft_lstclear(&<list(1)>, NULL)");
}

void	test_lstclear(void) {
	tlib_testprocess_ok(&test_lstclear_child1, "ft_lstclear(&<list(1)>, <del>)");
	tlib_testprocess_ok(&test_lstclear_child2, "ft_lstclear(&<list(2)>, <del>)");
	tlib_testprocess_ok(&test_lstclear_child3, "ft_lstclear(&NULL, <del>)");
	tlib_testprocess_ok(&test_lstclear_child4, "ft_lstclear(NULL, <del>)");
	tlib_testprocess_ok(&test_lstclear_child5, "ft_lstclear(&<list(1)>, NULL)");
}
