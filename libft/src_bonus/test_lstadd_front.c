#include "test_bonus.h"

static void	test_lstadd_front_child1(void) {
	t_list	*l;
	t_list	*l1;

	tlib_mockmalloc_reset();
	l1 = taux_lstnew(NULL);
	l = NULL;
	ft_lstadd_front(&l, l1);
	tlib_testresult_bool(l == l1 && l1->next == NULL);
	tlib_testmalloc_size(l1, sizeof(t_list));
	tlib_testmalloc_count(1);
	free(l1);
}

static void	test_lstadd_front_child2(void) {
	t_list	*l;
	t_list	*l1;
	t_list	*l2;

	tlib_mockmalloc_reset();
	l1 = taux_lstnew(NULL);
	l2 = taux_lstnew(NULL);
	l = l1;
	ft_lstadd_front(&l, l2);
	tlib_testresult_bool(l == l2 && l2->next == l1 && l1->next == NULL);
	tlib_testmalloc_size(l1, sizeof(t_list));
	tlib_testmalloc_size(l2, sizeof(t_list));
	tlib_testmalloc_count(2);
	free(l1);
	free(l2);
}

static void	test_lstadd_front_child3(void) {
	t_list	*l1;

	tlib_mockmalloc_reset();
	l1 = taux_lstnew(NULL);
	ft_lstadd_front(NULL, l1);
	tlib_testmalloc_size(l1, sizeof(t_list));
	tlib_testmalloc_count(1);
	free(l1);
}

static void	test_lstadd_front_child4(void) {
	t_list	*l;
	t_list	*l1;

	tlib_mockmalloc_reset();
	l1 = taux_lstnew(NULL);
	l = l1;
	ft_lstadd_front(&l, NULL);
	tlib_testresult_bool(l == l1 && l->next == NULL);
	tlib_testmalloc_size(l1, sizeof(t_list));
	tlib_testmalloc_count(1);
	free(l1);
}

void	test_lstadd_front(void) {
	tlib_testprocess_ok(&test_lstadd_front_child1);
	tlib_testprocess_ok(&test_lstadd_front_child2);
	tlib_testprocess_ok(&test_lstadd_front_child3);
	tlib_testprocess_ok(&test_lstadd_front_child4);
}
