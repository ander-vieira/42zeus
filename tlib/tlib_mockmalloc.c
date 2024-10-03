#include "tlib_int.h"

t_alloc	*g_allocs;
t_amock	*g_mocks;

static void	*libc_malloc(size_t len) {
	static void	*(*fun)(size_t);

	if (fun == NULL)
		fun = dlsym(RTLD_NEXT, "malloc");
	return (fun(len));
}

static void	libc_free(void *addr) {
	static void	(*fun)(void *);

	if (fun == NULL)
		fun = dlsym(RTLD_NEXT, "free");
	fun(addr);
}

static void	tlib_mockmalloc_add(void *addr, size_t size) {
	t_alloc	**list;

	list = &g_allocs;
	while (*list != NULL)
		list = &((*list)->next);
	*list = (t_alloc *)libc_malloc(sizeof(t_alloc));
	if (*list == NULL)
		return ;
	(*list)->addr = addr;
	(*list)->size = size;
	(*list)->next = NULL;
}

static t_bool	tlib_mockmalloc_delete(void *addr) {
	t_alloc	**list;
	t_alloc	*current;

	list = &g_allocs;
	while ((*list)->addr != addr)
	{
		if (*list == NULL)
			return (FALSE);
		list = &((*list)->next);
	}
	current = *list;
	*list = current->next;
	libc_free(current);
	return (TRUE);
}

static t_bool	tlib_mockmalloc_tickmocks(void) {
	t_bool	mock;
	t_amock	**list;
	t_amock	*current;

	list = &g_mocks;
	mock = FALSE;
	while (*list != NULL)
	{
		(*list)->timer -= 1;
		if ((*list)->timer == 0) {
			current = *list;
			*list = current->next;
			free(current);
			mock = TRUE;
		} else
			list = &((*list)->next);
	}
	return (mock);
}

static void	tlib_mockmalloc_resetmocks(void) {
	t_amock	**list;
	t_amock	*current;

	list = &g_mocks;
	while (*list != NULL)
	{
		current = *list;
		list = &((*list)->next);
		free(current);
	}
	g_mocks = NULL;
}

void	tlib_mockmalloc_reset(void) {
	t_alloc	**list;
	t_alloc	*current;

	list = &g_allocs;
	while (*list != NULL)
	{
		current = *list;
		list = &((*list)->next);
		free(current);
	}
	g_allocs = NULL;
	tlib_mockmalloc_resetmocks();
}

size_t	tlib_mockmalloc_lookup(void *addr) {
	t_alloc	**list;

	list = &g_allocs;
	while (*list != NULL)
	{
		if ((*list)->addr == addr)
			return ((*list)->size);
		list = &((*list)->next);
	}
	return (0);
}

size_t	tlib_mockmalloc_count(void) {
	t_alloc	**list;
	size_t	count;

	list = &g_allocs;
	count = 0;
	while (*list != NULL)
	{
		count += 1;
		list = &((*list)->next);
	}
	return (count);
}

void	tlib_mockmalloc_setmock(size_t timer) {
	t_amock	**list;

	if (timer == 0)
		return ;
	list = &g_mocks;
	while (*list != NULL)
		list = &((*list)->next);
	*list = (t_amock *)libc_malloc(sizeof(t_amock));
	if (*list == NULL)
		return ;
	(*list)->timer = timer;
	(*list)->next = NULL;
}

/* ************************************************************************** */
/* Redefining malloc and free to log memory allocations                       */

void	*malloc(size_t len) {
	void	*addr;

	if (tlib_mockmalloc_tickmocks())
		return (NULL);
	if (len == 0) {
		//TODO report zero length malloc
		return (NULL);
	}
	addr = libc_malloc(len);
	tlib_mockmalloc_add(addr, len);
	return (addr);
}

void	free(void *addr) {
	if (tlib_mockmalloc_lookup(addr) == 0) {
		//TODO report double free
		return ;
	}
	libc_free(addr);
	tlib_mockmalloc_delete(addr);
}
