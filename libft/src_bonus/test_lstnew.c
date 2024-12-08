#include "test_bonus.h"

static char	lstnew_c;

static void	test_lstnew_child1(void) {
	t_list	*l;

	tlib_mockmalloc_reset();
	l = ft_lstnew(&lstnew_c);
	tlib_testresult_notnull(l, "ft_lstnew(%p)", &lstnew_c);
	if (l != NULL) {
		tlib_testmalloc_size(l, sizeof(t_list), "ft_lstnew(%p)", &lstnew_c);
		tlib_testresult_custom(l->content == &lstnew_c,
			"ft_lstnew(%p) set t_list content incorrectly\n- (expected: %p, actual: %p)\n", &lstnew_c, &lstnew_c, l->content);
		tlib_testresult_custom(l->next == NULL,
			"ft_lstnew(%p) didn't set t_list next pointer to NULL (actual value: %p)\n", &lstnew_c, l->next);
	}
	free(l);
	tlib_testmalloc_leak("ft_lstnew(%p)", &lstnew_c);
}

static void	test_lstnew_child2(void) {
	tlib_mockmalloc_reset();
	tlib_mockmalloc_setmock(1);
	tlib_testresult_addr(ft_lstnew(&lstnew_c), NULL, "ft_lstnew(%p) (with malloc fail)", &lstnew_c);
	tlib_testmalloc_leak("ft_lstnew(%p) (with malloc fail)", &lstnew_c);
}

static void	test_lstnew_child3(void) {
	t_list	*l;

	tlib_mockmalloc_reset();
	l = ft_lstnew(NULL);
	tlib_testresult_notnull(l, "ft_lstnew(NULL)");
	if (l != NULL) {
		tlib_testmalloc_size(l, sizeof(t_list), "ft_lstnew(NULL)");
		tlib_testresult_custom(l->content == NULL,
			"ft_lstnew(NULL) set t_list content incorrectly\n- (expected: NULL, actual: %p)\n",
			l->content);
		tlib_testresult_custom(l->next == NULL,
			"ft_lstnew(NULL) didn't set t_list next pointer to NULL (actual value: %p)\n",
			l->next);
	}
	free(l);
	tlib_testmalloc_leak("ft_lstnew(NULL)");
}

void	test_lstnew(void) {
	tlib_testprocess_ok(&test_lstnew_child1, "ft_lstnew(%p)", &lstnew_c);
	tlib_testprocess_ok(&test_lstnew_child2, "ft_lstnew(%p) (with malloc fail)", &lstnew_c);
	tlib_testprocess_ok(&test_lstnew_child3, "ft_lstnew(NULL)");
}
