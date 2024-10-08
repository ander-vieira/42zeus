#include "test_bonus.h"

static t_parg	g_parg;

static void	test_lstdelone_del(void *p) {
	taux_parg_check(&g_parg, p);
}

static void	test_lstdelone_child1(void) {
	t_list	*l1;
	t_list	*l2;

	taux_parg_init(&g_parg, 1, &l1);
	tlib_mockmalloc_reset();
	l1 = taux_lstnew(&l1);
	l2 = taux_lstnew(NULL);
	l1->next = l2;
	ft_lstdelone(l1, &test_lstdelone_del);
	tlib_testresult_raw(taux_parg_ok(g_parg));
	tlib_testresult_raw(g_parg.i == 1);
	tlib_testmalloc_size(l1, 0, "ft_lstdelone(%p, %p)", l1, &test_lstdelone_del);
	tlib_testmalloc_size(l2, sizeof(t_list), "ft_lstdelone(%p, %p)", l1, &test_lstdelone_del);
	free(l1);
	free(l2);
	tlib_testmalloc_leak("ft_lstdelone(%p, %p)", l1, &test_lstdelone_del);
}

static void	test_lstdelone_child2(void) {
	t_list	*l;

	tlib_mockmalloc_reset();
	l = taux_lstnew(NULL);
	ft_lstdelone(l, NULL);
	tlib_testmalloc_size(l, sizeof(t_list), "ft_lstdelone(%p, NULL)", l);
	free(l);
	tlib_testmalloc_leak(NULL);
}

static void	test_lstdelone_child3(void) {
	tlib_mockmalloc_reset();
	taux_parg_init(&g_parg, 0);
	ft_lstdelone(NULL, &test_lstdelone_del);
	tlib_testresult_raw(g_parg.i == 0);
	tlib_testmalloc_leak(NULL);
}

void	test_lstdelone(void) {
	tlib_testprocess_ok(&test_lstdelone_child1);
	tlib_testprocess_ok(&test_lstdelone_child2);
	tlib_testprocess_ok(&test_lstdelone_child3);
}
