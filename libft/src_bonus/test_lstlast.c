#include "test_bonus.h"

static void	test_lstlast_child1(void)
{
	t_list	*l1;
	t_list	*l2;
	t_list	*l3;

	tlib_mockmalloc_reset();
	l1 = taux_lstnew(NULL);
	l2 = taux_lstnew(NULL);
	l3 = taux_lstnew(NULL);
	l1->next = l2;
	l2->next = l3;
	tlib_testresult_bool(ft_lstlast(l1) == l3);
	tlib_testresult_bool(ft_lstlast(l2) == l3);
	tlib_testresult_bool(ft_lstlast(l3) == l3);
	tlib_testmalloc_size(l1, sizeof(t_list));
	tlib_testmalloc_size(l2, sizeof(t_list));
	tlib_testmalloc_size(l3, sizeof(t_list));
	tlib_testmalloc_count(3);
	free(l1);
	free(l2);
	free(l3);
}

static void	test_lstlast_child2(void)
{
	tlib_testresult_bool(ft_lstlast(NULL) == NULL);
}

void	test_lstlast(void)
{
	tlib_test_process(&test_lstlast_child1, PRESULT_OK);
	tlib_test_process(&test_lstlast_child2, PRESULT_OK);
}
