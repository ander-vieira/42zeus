#include "test_bonus.h"

//TODO upgrade tests

static void	test_lstlast_child1(void) {
	t_list	*l;

	tlib_mockmalloc_reset();
	l = taux_lstbuild(3, NULL, NULL, NULL);
	tlib_testresult_addr(ft_lstlast(l), l->next->next, "ft_lstlast(%p)", l);
	taux_free(l);
	tlib_testmalloc_leak("ft_lstlast(%p)", l);
}

static void	test_lstlast_child2(void) {
	tlib_mockmalloc_reset();
	tlib_testresult_addr(ft_lstlast(NULL), NULL, "ft_lstlast(NULL)");
	tlib_testmalloc_leak("ft_lstlast(NULL)");
}

void	test_lstlast(void) {
	tlib_testprocess_ok(&test_lstlast_child1);
	tlib_testprocess_ok(&test_lstlast_child2);
}
