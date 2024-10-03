#include "test_bonus.h"

static void	test_lstnew_child1(void) {
	t_list	*l;

	tlib_mockmalloc_reset();
	l = ft_lstnew(&l);
	tlib_testresult_raw(l != NULL && l->content == &l && l->next == NULL);
	tlib_testmalloc_size(l, sizeof(t_list), "ft_lstnew(TODO)");
	free(l);
	tlib_testmalloc_leak();
}

static void	test_lstnew_child2(void) {
	tlib_mockmalloc_reset();
	tlib_mockmalloc_setmock(1);
	tlib_testresult_raw(ft_lstnew(NULL) == NULL);
	tlib_testmalloc_leak();
}

void	test_lstnew(void) {
	tlib_testprocess_ok(&test_lstnew_child1);
	tlib_testprocess_ok(&test_lstnew_child2);
}
