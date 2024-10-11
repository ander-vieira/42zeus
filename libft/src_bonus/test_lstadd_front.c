#include "test_bonus.h"

static void	test_lstadd_front_child1(void) {
	t_list	*l, *l1;

	tlib_mockmalloc_reset();
	l1 = taux_lstbuild(1, &l);
	l = NULL;
	ft_lstadd_front(&l, l1);
	tlib_testresult_custom(taux_lstcheck(l, 1, &l), "ft_lstadd_front(&NULL, <list(1)>) did not return the correct list\n");
	taux_free(l1);
	tlib_testmalloc_leak("ft_lstadd_front(&NULL, <list(1)>)");
}

static void	test_lstadd_front_child2(void) {
	t_list	*l, *l1, *l2;

	tlib_mockmalloc_reset();
	l1 = taux_lstbuild(1, &l);
	l2 = taux_lstbuild(1, &l + 1);
	l = l1;
	ft_lstadd_front(&l, l2);
	tlib_testresult_custom(taux_lstcheck(l, 2, &l + 1, &l), "ft_lstadd_front(&<list(1)>, <list(1)>) did not return the correct list\n");
	taux_free(l1);
	taux_free(l2);
	tlib_testmalloc_leak("ft_lstadd_front(&<list(1)>, <list(1)>)");
}

static void	test_lstadd_front_child3(void) {
	t_list	*l, *l1, *l2;

	tlib_mockmalloc_reset();
	l1 = taux_lstbuild(2, &l, &l + 1);
	l2 = taux_lstbuild(1, &l + 2);
	l = l1;
	ft_lstadd_front(&l, l2);
	tlib_testresult_custom(taux_lstcheck(l, 3, &l + 2, &l, &l + 1), "ft_lstadd_front(&<list(2)>, <list(1)>) did not return the correct list\n");
	taux_free(l1);
	taux_free(l2);
	tlib_testmalloc_leak("ft_lstadd_front(&<list(2)>, <list(1)>)");
}

static void	test_lstadd_front_child4(void) {
	t_list	*l1;

	tlib_mockmalloc_reset();
	l1 = taux_lstbuild(1, NULL);
	ft_lstadd_front(NULL, l1);
	taux_free(l1);
	tlib_testmalloc_leak("ft_lstadd_front(NULL, <list(1)>)");
}

static void	test_lstadd_front_child5(void) {
	t_list	*l, *l1;

	tlib_mockmalloc_reset();
	l1 = taux_lstbuild(1, &l);
	l = l1;
	ft_lstadd_front(&l, NULL);
	tlib_testresult_custom(taux_lstcheck(l, 1, &l), "ft_lstadd_front(&<list(1)>, NULL) did not return the correct list\n");
	taux_free(l1);
	tlib_testmalloc_leak("ft_lstadd_front(&<list(1)>, NULL)");
}

void	test_lstadd_front(void) {
	tlib_testprocess_ok(&test_lstadd_front_child1, "ft_lstadd_front(&NULL, <list(1)>)");
	tlib_testprocess_ok(&test_lstadd_front_child2, "ft_lstadd_front(&<list(1)>, <list(1)>)");
	tlib_testprocess_ok(&test_lstadd_front_child3, "ft_lstadd_front(&<list(2)>, <list(1)>)");
	tlib_testprocess_ok(&test_lstadd_front_child4, "ft_lstadd_front(NULL, <list(1)>)");
	tlib_testprocess_ok(&test_lstadd_front_child5, "ft_lstadd_front(&<list(1)>, NULL)");
}
