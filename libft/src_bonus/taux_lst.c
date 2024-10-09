#include "test_bonus.h"

t_list	*taux_lstnew(void *content) {
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

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

void	taux_parg_init(t_parg *parg, size_t len, ...) {
	va_list	args;
	size_t	i;

	va_start(args, len);
	if (len > 3)
		len = 3;
	parg->len = len;
	parg->i = 0;
	parg->err = FALSE;
	i = 0;
	while (i < len) {
		parg->p[i] = va_arg(args, void *);
		i++;
	}
	va_end(args);
}

void	taux_parg_check(t_parg *parg, void *p) {
	size_t	i;

	parg->i++;
	if (p != NULL) {
		i = 0;
		while (i < parg->len) {
			if (p == parg->p[i]) {
				parg->p[i] = NULL;
				return ;
			}
			i++;
		}
	}
	parg->err = TRUE;
}

t_bool	taux_parg_ok(t_parg parg) {
	return (!parg.err);
}

void	taux_pget_init(t_pget *pget, size_t len, ...) {
	va_list	args;
	size_t	i;

	va_start(args, len);
	if (len > 3)
		len = 3;
	pget->len = len;
	pget->i = 0;
	pget->j = 0;
	pget->err = FALSE;
	i = 0;
	while (i < len) {
		pget->p[i] = va_arg(args, void *);
		i++;
	}
	va_end(args);
}

void	*taux_pget_get(t_pget *pget) {
	size_t	i;

	i = pget->i;
	pget->i++;
	if (i >= pget->len)
		return (NULL);
	return (pget->p[i]);
}

void	taux_pget_check(t_pget *pget, void *p) {
	size_t	i;

	pget->j++;
	if (p != NULL) {
		i = 0;
		while (i < pget->len && i < pget->i) {
			if (p == pget->p[i]) {
				pget->p[i] = NULL;
				return ;
			}
			i++;
		}
	}
	pget->err = TRUE;
}

t_bool	taux_pget_ok(t_pget pget) {
	return (!pget.err && pget.i == pget.j);
}
