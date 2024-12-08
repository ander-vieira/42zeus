#include "test_bonus.h"

static void	test_lstlast_child1(void) {
	t_list	*l;

	tlib_mockmalloc_reset();
	l = taux_lstbuild(1, NULL);
	tlib_testresult_addr(ft_lstlast(l), l, "ft_lstlast(<list(1)>)");
	taux_free(l);
	tlib_testmalloc_leak("ft_lstlast(<list(1)>)");
}

static void	test_lstlast_child2(void) {
	t_list	*l;

	tlib_mockmalloc_reset();
	l = taux_lstbuild(3, NULL, NULL, NULL);
	tlib_testresult_addr(ft_lstlast(l), l->next->next, "ft_lstlast(<list(3)>)");
	taux_free(l);
	tlib_testmalloc_leak("ft_lstlast(<list(3)>)");
}

static void	test_lstlast_child3(void) {
	tlib_mockmalloc_reset();
	tlib_testresult_addr(ft_lstlast(NULL), NULL, "ft_lstlast(NULL)");
	tlib_testmalloc_leak("ft_lstlast(NULL)");
}

void	test_lstlast(void) {
	tlib_testprocess_ok(&test_lstlast_child1, "ft_lstlast(<list(1)>)");
	tlib_testprocess_ok(&test_lstlast_child2, "ft_lstlast(<list(3)>)");
	tlib_testprocess_ok(&test_lstlast_child3, "ft_lstlast(NULL)");
}
