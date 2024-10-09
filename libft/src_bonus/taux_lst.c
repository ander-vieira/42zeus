#include "test_bonus.h"

static t_list	*taux_lstbuild_va(size_t n, va_list args) {
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->content = va_arg(args, void *);
	if (n > 1) {
		list->next = taux_lstbuild_va(n - 1, args);
		if (list->next == NULL)
			return (free(list), NULL);
	} else
		list->next = NULL;
	return (list);
}

t_list	*taux_lstbuild(size_t n, ...) {
	va_list	args;
	t_list	*list;

	va_start(args, n);
	if (n != 0)
		list = taux_lstbuild_va(n, args);
	else
		list = NULL;
	va_end(args);
	return (list);
}

t_list	*taux_lstbuild_range(size_t n, char *addr) {
	t_list	*list;

	if (n == 0)
		return (NULL);
	list = (t_list *)malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->content = addr;
	if (n > 1) {
		list->next = taux_lstbuild_range(n - 1, addr + 1);
		if (list->next == NULL)
			return (free(list), NULL);
	} else
		list->next = NULL;
	return (list);
}

void	taux_free(t_list *l) {
	if (tlib_isalloc(l)) {
		taux_free(l->next);
		free(l);
	}
}

t_bool	taux_lstcheck(t_list *l, size_t n, ...) {
	va_list	args;
	t_list	**current;
	t_bool	result;
	size_t	i;

	va_start(args, n);
	current = &l;
	result = TRUE;
	i = 0;
	while (*current != NULL) {
		if (!tlib_isalloc(*current))
			result = FALSE;
		if ((*current)->content != va_arg(args, void *))
			result = FALSE;
		current = &((*current)->next);
		i++;
	}
	if (i != n)
		result = FALSE;
	va_end(args);
	return (result);
}

t_bool	taux_lstcheck_range(t_list *l, size_t n, char *addr) {
	t_list	**current;
	t_bool	result;
	size_t	i;

	current = &l;
	result = TRUE;
	i = 0;
	while (*current != NULL) {
		if (!tlib_isalloc(*current))
			result = FALSE;
		if ((*current)->content != addr + i)
			result = FALSE;
		current = &((*current)->next);
		i++;
	}
	if (i != n)
		result = FALSE;
	return (result);
}
