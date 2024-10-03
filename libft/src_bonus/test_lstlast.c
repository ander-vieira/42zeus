#include "test_bonus.h"

//TODO upgrade tests

static void	test_lstlast_child1(void) {
	t_list	*l1;
	t_list	*l2;
	t_list	*l3;

	tlib_mockmalloc_reset();
	l1 = taux_lstnew(NULL);
	l2 = taux_lstnew(NULL);
	l3 = taux_lstnew(NULL);
	l1->next = l2;
	l2->next = l3;
	tlib_testresult_raw(ft_lstlast(l1) == l3);
	tlib_testresult_raw(ft_lstlast(l2) == l3);
	tlib_testresult_raw(ft_lstlast(l3) == l3);
	tlib_testmalloc_size(l1, sizeof(t_list), NULL);
	tlib_testmalloc_size(l2, sizeof(t_list), NULL);
	tlib_testmalloc_size(l3, sizeof(t_list), NULL);
	free(l1);
	free(l2);
	free(l3);
	tlib_testmalloc_leak(NULL);
}

static void	test_lstlast_child2(void) {
	tlib_testresult_raw(ft_lstlast(NULL) == NULL);
}

void	test_lstlast(void) {
	tlib_testprocess_ok(&test_lstlast_child1);
	tlib_testprocess_ok(&test_lstlast_child2);
}
