#include "test_bonus.h"

static t_bool	lstdelone_testing;
static t_list	*lstdelone_l;
static size_t	lstdelone_called;

static void	test_lstdelone_start(t_list *l) {
	lstdelone_l = l;
	lstdelone_called = 0;
	lstdelone_testing = TRUE;
}

static void	test_lstdelone_stop() {
	lstdelone_testing = FALSE;
}

static void	test_lstdelone_del(void *p) {
	if (!lstdelone_testing)
		return ;
	tlib_testresult_custom(p == &lstdelone_called,
		"ft_lstdelone(%p, %p) called its function with an incorrect parameter\n- (expected: %p, actual: %p)", lstdelone_l, &test_lstdelone_del, &lstdelone_called, p);
	lstdelone_called += 1;
}

static void	test_lstdelone_child1(void) {
	t_list	*l;

	tlib_mockmalloc_reset();
	l = taux_lstbuild(1, &lstdelone_called);
	test_lstdelone_start(l);
	ft_lstdelone(l, &test_lstdelone_del);
	test_lstdelone_stop();
	tlib_testresult_custom(!tlib_isalloc(l),
		"ft_lstdelone(%p, %p) did not free %p\n", l, &test_lstdelone_del, l);
	tlib_testresult_custom(lstdelone_called == 1,
		"ft_lstdelone(%p, %p) called its function an incorrect number of times\n- (expected: 1 calls, actual: %z calls)", l, &test_lstdelone_del, lstdelone_called);
	taux_free(l);
	tlib_testmalloc_leak("ft_lstdelone(%p, %p)", l, &test_lstdelone_del);
}

static void	test_lstdelone_child2(void) {
	t_list	*l1, *l2;

	tlib_mockmalloc_reset();
	l1 = taux_lstbuild(2, &lstdelone_called, NULL);
	l2 = l1->next;
	test_lstdelone_start(l1);
	ft_lstdelone(l1, &test_lstdelone_del);
	test_lstdelone_stop();
	tlib_testresult_custom(!tlib_isalloc(l1),
		"ft_lstdelone(%p, %p) did not free %p\n", l1, &test_lstdelone_del, l1);
	tlib_testresult_custom(tlib_isalloc(l2),
		"ft_lstdelone(%p, %p) freed the next element after %p\n", l1, &test_lstdelone_del, l1);
	tlib_testresult_custom(lstdelone_called == 1,
		"ft_lstdelone(%p, %p) called its function an incorrect number of times\n- (expected: 1 calls, actual: %z calls)", l1, &test_lstdelone_del, lstdelone_called);
	taux_free(l1);
	taux_free(l2);
	tlib_testmalloc_leak("ft_lstdelone(%p, %p)", l1, &test_lstdelone_del);
}

static void	test_lstdelone_child3(void) {
	tlib_mockmalloc_reset();
	ft_lstdelone(NULL, &test_lstdelone_del);
	tlib_testmalloc_leak("ft_lstdelone(NULL, %p)", &test_lstdelone_del);
}

static void	test_lstdelone_child4(void) {
	t_list	*l;

	tlib_mockmalloc_reset();
	l = taux_lstbuild(1, NULL);
	ft_lstdelone(l, NULL);
	tlib_testresult_custom(tlib_isalloc(l),
		"ft_lstdelone(%p, NULL) freed %p", l, l);
	taux_free(l);
	tlib_testmalloc_leak("ft_lstdelone(%p, NULL)", l);
}

void	test_lstdelone(void) {
	tlib_testprocess_ok(&test_lstdelone_child1);
	tlib_testprocess_ok(&test_lstdelone_child2);
	tlib_testprocess_ok(&test_lstdelone_child3);
	tlib_testprocess_ok(&test_lstdelone_child4);
}
