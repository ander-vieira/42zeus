#include "test_bonus.h"

static t_parg	g_parg;
static t_pget	g_pget;

static void	*test_lstmap_fun(void *p) {
	taux_parg_check(&g_parg, p);
	return (taux_pget_get(&g_pget));
}

static void	test_lstmap_del(void *p) {
	taux_pget_check(&g_pget, p);
}

static void	test_lstmap_child1(void) {
	t_list	*l;
	t_list	*l1;
	t_list	*l2;

	tlib_mockmalloc_reset();
	taux_parg_init(&g_parg, 2, &l1, &l2);
	taux_pget_init(&g_pget, 2, &l, &l + 1);
	l1 = taux_lstnew(&l1);
	l2 = taux_lstnew(&l2);
	l1->next = l2;
	l = ft_lstmap(l1, &test_lstmap_fun, &test_lstmap_del);
	if (l != NULL)
		taux_pget_check(&g_pget, l->content);
	if (l != NULL && l->next != NULL)
		taux_pget_check(&g_pget, l->next->content);
	tlib_testresult_bool(l1->next == l2 && l2->next == NULL);
	tlib_testresult_bool(l != NULL && l->next != NULL && l->next->next == NULL);
	tlib_testresult_bool(taux_parg_ok(g_parg));
	tlib_testresult_bool(g_parg.i == 2);
	tlib_testresult_bool(taux_pget_ok(g_pget));
	tlib_testmalloc_size(l1, sizeof(t_list));
	tlib_testmalloc_size(l2, sizeof(t_list));
	tlib_testmalloc_size(l, sizeof(t_list));
	tlib_testmalloc_size(l->next, sizeof(t_list));
	tlib_testmalloc_count(4);
	free(l1);
	free(l2);
	free(l->next);
	free(l);
}

static void	test_lstmap_child2(void) {
	t_list	*l;
	t_list	*l1;
	t_list	*l2;

	tlib_mockmalloc_reset();
	taux_parg_init(&g_parg, 2, &l1, &l2);
	taux_pget_init(&g_pget, 2, &l, &l + 1);
	l1 = taux_lstnew(&l1);
	l2 = taux_lstnew(&l2);
	l1->next = l2;
	tlib_mockmalloc_setmock(1);
	l = ft_lstmap(l1, &test_lstmap_fun, &test_lstmap_del);
	tlib_testresult_bool(l1->next == l2 && l2->next == NULL);
	tlib_testresult_bool(l == NULL);
	tlib_testresult_bool(taux_parg_ok(g_parg));
	tlib_testresult_bool(taux_pget_ok(g_pget));
	tlib_testmalloc_size(l1, sizeof(t_list));
	tlib_testmalloc_size(l2, sizeof(t_list));
	tlib_testmalloc_count(2);
	free(l1);
	free(l2);
}

static void	test_lstmap_child3(void) {
	t_list	*l;
	t_list	*l1;
	t_list	*l2;

	tlib_mockmalloc_reset();
	taux_parg_init(&g_parg, 2, &l1, &l2);
	taux_pget_init(&g_pget, 2, &l, &l + 1);
	l1 = taux_lstnew(&l1);
	l2 = taux_lstnew(&l2);
	l1->next = l2;
	tlib_mockmalloc_setmock(2);
	l = ft_lstmap(l1, &test_lstmap_fun, &test_lstmap_del);
	tlib_testresult_bool(l1->next == l2 && l2->next == NULL);
	tlib_testresult_bool(l == NULL);
	tlib_testresult_bool(taux_parg_ok(g_parg));
	tlib_testresult_bool(taux_pget_ok(g_pget));
	tlib_testmalloc_size(l1, sizeof(t_list));
	tlib_testmalloc_size(l2, sizeof(t_list));
	tlib_testmalloc_count(2);
	free(l1);
	free(l2);
}

static void	test_lstmap_child4(void) {
	t_list	*l;

	tlib_mockmalloc_reset();
	taux_parg_init(&g_parg, 0);
	taux_pget_init(&g_pget, 0);
	l = ft_lstmap(NULL, &test_lstmap_fun, &test_lstmap_del);
	tlib_testresult_bool(l == NULL);
	tlib_testresult_bool(taux_parg_ok(g_parg));
	tlib_testresult_bool(g_parg.i == 0);
	tlib_testresult_bool(taux_pget_ok(g_pget));
	tlib_testmalloc_count(0);
}

static void	test_lstmap_child5(void) {
	t_list	*l;
	t_list	*l1;

	tlib_mockmalloc_reset();
	taux_pget_init(&g_pget, 0);
	l1 = taux_lstnew(&l1);
	l = ft_lstmap(l1, NULL, &test_lstmap_del);
	tlib_testresult_bool(l1->next == NULL);
	tlib_testresult_bool(l == NULL);
	tlib_testresult_bool(taux_pget_ok(g_pget));
	tlib_testresult_bool(g_pget.j == 0);
	tlib_testmalloc_size(l1, sizeof(t_list));
	tlib_testmalloc_count(1);
	free(l1);
}

static void	test_lstmap_child6(void) {
	t_list	*l;
	t_list	*l1;

	tlib_mockmalloc_reset();
	taux_parg_init(&g_parg, 0);
	taux_pget_init(&g_pget, 0);
	l1 = taux_lstnew(&l1);
	l = ft_lstmap(l1, &test_lstmap_fun, NULL);
	tlib_testresult_bool(l1->next == NULL);
	tlib_testresult_bool(l == NULL);
	tlib_testresult_bool(taux_parg_ok(g_parg));
	tlib_testresult_bool(g_parg.i == 0);
	tlib_testresult_bool(taux_pget_ok(g_pget));
	tlib_testmalloc_size(l1, sizeof(t_list));
	tlib_testmalloc_count(1);
	free(l1);
}

void	test_lstmap(void) {
	tlib_test_process(&test_lstmap_child1, PRESULT_OK);
	tlib_test_process(&test_lstmap_child2, PRESULT_OK);
	tlib_test_process(&test_lstmap_child3, PRESULT_OK);
	tlib_test_process(&test_lstmap_child4, PRESULT_OK);
	tlib_test_process(&test_lstmap_child5, PRESULT_OK);
	tlib_test_process(&test_lstmap_child6, PRESULT_OK);
}
