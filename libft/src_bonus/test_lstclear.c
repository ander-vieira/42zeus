#include "test_bonus.h"

static t_bool	lstclear_testing;
static t_list	**lstclear_l;
static size_t	lstclear_called;

static void	test_lstclear_start(t_list **l) {
	lstclear_l = l;
	lstclear_called = 0;
	lstclear_testing = TRUE;
}

static void	test_lstclear_stop() {
	lstclear_testing = FALSE;
}

static void	test_lstclear_del(void *p) {
	if (!lstclear_testing)
		return ;
	tlib_testresult_custom(p == &lstclear_called,
		"ft_lstclear(%p, %p) called its function with an incorrect parameter\n- (expected: %p, actual: %p)", lstclear_l, &test_lstclear_del, &lstclear_called, p);
	lstclear_called += 1;
}

static void	test_lstclear_child1(void) {
	t_list	*l, *l1;

	tlib_mockmalloc_reset();
	l1 = taux_lstbuild(1, &lstclear_called);
	l = l1;
	test_lstclear_start(&l);
	ft_lstclear(&l, &test_lstclear_del);
	test_lstclear_stop();
	tlib_testresult_addr(l, NULL, "ft_lstclear(%p, %p)", &l, &test_lstclear_del);
	tlib_testresult_custom(!tlib_isalloc(l1),
		"ft_lstclear(%p, %p) did not free the argument list\n", &l, &test_lstclear_del);
	tlib_testresult_custom(lstclear_called == 1,
		"ft_lstclear(%p, %p) called its function an incorrect number of times\n- (expected: 1 calls, actual: %z calls)", &l, &test_lstclear_del, lstclear_called);
	taux_free(l1);
	tlib_testmalloc_leak("ft_lstclear(%p, %p)", &l, &test_lstclear_del);
}

static void test_lstclear_child2(void) {
	t_list	*l, *l1;

	tlib_mockmalloc_reset();
	l1 = taux_lstbuild(2, &lstclear_called, &lstclear_called);
	l = l1;
	test_lstclear_start(&l);
	ft_lstclear(&l, &test_lstclear_del);
	test_lstclear_stop();
	tlib_testresult_addr(l, NULL, "ft_lstclear(%p, %p)", &l, &test_lstclear_del);
	tlib_testresult_custom(!tlib_isalloc(l1),
		"ft_lstclear(%p, %p) did not free the argument list\n", &l, &test_lstclear_del);
	tlib_testresult_custom(lstclear_called == 2,
		"ft_lstclear(%p, %p) called its function an incorrect number of times\n- (expected: 2 calls, actual: %z calls)", &l, &test_lstclear_del, lstclear_called);
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
		"ft_lstclear(%p, %p) called its function an incorrect number of times\n- (expected: 0 calls, actual: %z calls)", &l, &test_lstclear_del, lstclear_called);
	tlib_testmalloc_leak("ft_lstclear(%p, %p)", &l, &test_lstclear_del);
}

static void	test_lstclear_child4(void) {
	tlib_mockmalloc_reset();
	test_lstclear_start(NULL);
	ft_lstclear(NULL, &test_lstclear_del);
	test_lstclear_stop();
	tlib_testresult_custom(lstclear_called == 0,
		"ft_lstclear(NULL, %p) called its function an incorrect number of times\n- (expected: 0 calls, actual: %z calls)", &test_lstclear_del, lstclear_called);
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
