#include "test_bonus.h"

static void	test_lstnew_child1(void)
{
	t_list	*l;

	tlib_mockmalloc_reset();
	l = ft_lstnew(&l);
	tlib_testresult_bool(l != NULL && l->content == &l && l->next == NULL);
	tlib_testmalloc_size(l, sizeof(t_list));
	tlib_testmalloc_count(1);
	free(l);
}

static void	test_lstnew_child2(void)
{
	tlib_mockmalloc_reset();
	tlib_mockmalloc_setmock(1);
	tlib_testresult_bool(ft_lstnew(NULL) == NULL);
	tlib_testmalloc_count(0);
}

void	test_lstnew(void)
{
	tlib_test_process(&test_lstnew_child1, PRESULT_OK);
	tlib_test_process(&test_lstnew_child2, PRESULT_OK);
}
