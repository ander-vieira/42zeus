#include "test_bonus.h"

static t_parg	g_parg;

static void	test_lstiter_fun(void *p) {
	taux_parg_check(&g_parg, p);
}

static void	test_lstiter_child1(void) {
	t_list	*l1;
	t_list	*l2;

	tlib_mockmalloc_reset();
	taux_parg_init(&g_parg, 2, &l1, &l2);
	l1 = taux_lstnew(&l1);
	l2 = taux_lstnew(&l2);
	l1->next = l2;
	ft_lstiter(l1, &test_lstiter_fun);
	tlib_testresult_raw(l1->next == l2 && l2->next == NULL);
	tlib_testresult_raw(taux_parg_ok(g_parg));
	tlib_testresult_raw(g_parg.i == 2);
	tlib_testmalloc_size(l1, sizeof(t_list), "ft_lstiter(TODO)");
	tlib_testmalloc_size(l2, sizeof(t_list), "ft_lstiter(TODO)");
	tlib_testmalloc_count(2);
	free(l1);
	free(l2);
}

static void	test_lstiter_child2(void) {
	tlib_mockmalloc_reset();
	taux_parg_init(&g_parg, 0);
	ft_lstiter(NULL, &test_lstiter_fun);
	tlib_testresult_raw(g_parg.i == 0);
	tlib_testmalloc_count(0);
}

static void	test_lstiter_child3(void) {
	t_list	*l1;

	tlib_mockmalloc_reset();
	l1 = taux_lstnew(NULL);
	ft_lstiter(l1, NULL);
	tlib_testresult_raw(l1->next == NULL);
	tlib_testmalloc_size(l1, sizeof(t_list), "ft_lstiter(TODO)");
	tlib_testmalloc_count(1);
	free(l1);
}

void	test_lstiter(void) {
	tlib_testprocess_ok(&test_lstiter_child1);
	tlib_testprocess_ok(&test_lstiter_child2);
	tlib_testprocess_ok(&test_lstiter_child3);
}
