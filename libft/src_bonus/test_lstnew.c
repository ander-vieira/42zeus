#include "test_bonus.h"

static void	test_lstnew_child1(void) {
	t_list	*l;
	char	c;

	tlib_mockmalloc_reset();
	l = ft_lstnew(&c);
	tlib_testresult_notnull(l, "ft_lstnew(%p)", &c);
	if (l != NULL) {
		tlib_testmalloc_size(l, sizeof(t_list), "ft_lstnew(%p)", &c);
		tlib_testresult_custom(l->content == &c,
			"ft_lstnew(%p) set t_list content incorrectly\n- (expected: %p, actual: %p)\n", &c, &c, l->content);
		tlib_testresult_custom(l->next == NULL,
			"ft_lstnew(%p) didn't set t_list next pointer to NULL (actual value: %p)\n", &c, l->next);
	}
	free(l);
	tlib_testmalloc_leak("ft_lstnew(%p)", &c);
}

static void	test_lstnew_child2(void) {
	char	c;

	tlib_mockmalloc_reset();
	tlib_mockmalloc_setmock(1);
	tlib_testresult_addr(ft_lstnew(&c), NULL, "ft_lstnew(%p) (with malloc fail)", &c);
	tlib_testmalloc_leak("ft_lstnew(%p) (with malloc fail)", &c);
}

void	test_lstnew(void) {
	tlib_testprocess_ok(&test_lstnew_child1);
	tlib_testprocess_ok(&test_lstnew_child2);
}
