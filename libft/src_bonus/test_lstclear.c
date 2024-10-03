#include "test_bonus.h"

static t_parg	g_parg;

static void	test_lstclear_del(void *p) {
	taux_parg_check(&g_parg, p);
}

static void	test_lstclear_child1(void) {
	t_list	*l;
	t_list	*l1;
	t_list	*l2;

	tlib_mockmalloc_reset();
	taux_parg_init(&g_parg, 2, &l1, &l2);
	l1 = taux_lstnew(&l1);
	l2 = taux_lstnew(&l2);
	l = l1;
	l->next = l2;
	ft_lstclear(&l, &test_lstclear_del);
	tlib_testresult_raw(l == NULL);
	tlib_testresult_raw(taux_parg_ok(g_parg));
	tlib_testresult_raw(g_parg.i == 2);
	tlib_testmalloc_size(l1, 0, "ft_lstclear(TODO)");
	tlib_testmalloc_size(l2, 0, "ft_lstclear(TODO)");
	tlib_testmalloc_count(0);
	free(l1);
	free(l2);
}

static void	test_lstclear_child2(void) {
	t_list	*l;

	tlib_mockmalloc_reset();
	taux_parg_init(&g_parg, 0);
	l = NULL;
	ft_lstclear(&l, &test_lstclear_del);
	tlib_testresult_raw(l == NULL);
	tlib_testresult_raw(g_parg.i == 0);
	tlib_testmalloc_count(0);
}

static void	test_lstclear_child3(void) {
	tlib_mockmalloc_reset();
	taux_parg_init(&g_parg, 0);
	ft_lstclear(NULL, &test_lstclear_del);
	tlib_testresult_raw(g_parg.i == 0);
	tlib_testmalloc_count(0);
}

static void	test_lstclear_child4(void) {
	t_list	*l;
	t_list	*l1;

	tlib_mockmalloc_reset();
	l1 = taux_lstnew(NULL);
	l = l1;
	ft_lstclear(&l, NULL);
	tlib_testresult_raw(l == l1 && l->next == NULL);
	tlib_testmalloc_size(l1, sizeof(t_list), "ft_lstclear(TODO)");
	tlib_testmalloc_count(1);
	free(l1);
}

void	test_lstclear(void) {
	tlib_testprocess_ok(&test_lstclear_child1);
	tlib_testprocess_ok(&test_lstclear_child2);
	tlib_testprocess_ok(&test_lstclear_child3);
	tlib_testprocess_ok(&test_lstclear_child4);
}
