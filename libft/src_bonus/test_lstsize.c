#include "test_bonus.h"

static void	test_lstsize_child1(void) {
	t_list	*l;

	tlib_mockmalloc_reset();
	l = taux_lstbuild(3, NULL, NULL, NULL);
	tlib_testresult_int(ft_lstsize(l), 3, "ft_lstsize(%p)", l);
	taux_free(l);
	tlib_testmalloc_leak("ft_lstsize(%p)", l);
}

static void	test_lstsize_child2(void) {
	tlib_mockmalloc_reset();
	tlib_testresult_int(ft_lstsize(NULL), 0, "ft_lstsize(NULL)");
	tlib_testmalloc_leak("ft_lstsize(NULL)");
}

void	test_lstsize(void) {
	tlib_testprocess_ok(&test_lstsize_child1);
	tlib_testprocess_ok(&test_lstsize_child2);
}
