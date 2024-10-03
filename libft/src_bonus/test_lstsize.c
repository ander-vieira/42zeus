#include "test_bonus.h"

static void	test_lstsize_child1(void) {
	t_list	*l1;
	t_list	*l2;
	t_list	*l3;

	tlib_mockmalloc_reset();
	l1 = taux_lstnew(NULL);
	l2 = taux_lstnew(NULL);
	l3 = taux_lstnew(NULL);
	l1->next = l2;
	l2->next = l3;
	tlib_testresult_raw(ft_lstsize(l1) == 3);
	tlib_testresult_raw(ft_lstsize(l2) == 2);
	tlib_testresult_raw(ft_lstsize(l3) == 1);
	tlib_testmalloc_size(l1, sizeof(t_list), "ft_lstsize(TODO)");
	tlib_testmalloc_size(l2, sizeof(t_list), "ft_lstsize(TODO)");
	tlib_testmalloc_size(l3, sizeof(t_list), "ft_lstsize(TODO)");
	free(l1);
	free(l2);
	free(l3);
	tlib_testmalloc_leak(NULL);
}

static void	test_lstsize_child2(void) {
	tlib_testresult_raw(ft_lstsize(NULL) == 0);
}

void	test_lstsize(void) {
	tlib_testprocess_ok(&test_lstsize_child1);
	tlib_testprocess_ok(&test_lstsize_child2);
}
