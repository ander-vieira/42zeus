#ifndef TEST_BONUS_H
# define TEST_BONUS_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# include "../../tlib/tlib.h"

# define FUNPTR_CHECKED	10

/* ************************************************************************** */
/* Fake definition to get VSCode dependency detection working                */

typedef struct s_list {
	void			*content;
	struct s_list	*next;
}				t_list;

/* ************************************************************************** */
/* Weak declarations to check for missing functions                           */

# pragma weak ft_lstnew
# pragma weak ft_lstadd_front
# pragma weak ft_lstadd_back
# pragma weak ft_lstlast
# pragma weak ft_lstsize
# pragma weak ft_lstdelone
# pragma weak ft_lstclear
# pragma weak ft_lstiter
# pragma weak ft_lstmap

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *n);
void	ft_lstadd_back(t_list **lst, t_list *n);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*fun)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*fun)(void *), void (*del)(void *));

/* ************************************************************************** */
/* Utility unctions for testing lists                                         */

typedef struct s_pcall {
	void	*p[3];
	size_t	len;
	size_t	i;
	t_bool	err;
}	t_parg;

typedef struct s_pget {
	void	*p[3];
	size_t	len;
	size_t	i;
	size_t	j;
	t_bool	err;
}	t_pget;

t_list	*taux_lstnew(void *content);
t_list	*taux_lstbuild(size_t n, ...);
t_list	*taux_lstbuild_range(size_t n, char *addr);
void	taux_free(t_list *l);
t_bool	taux_lstcheck(t_list *l, size_t n, ...);
t_bool	taux_lstcheck_range(t_list *l, size_t n, char *addr);
void	taux_parg_init(t_parg *parg, size_t len, ...);
void	taux_parg_check(t_parg *parg, void *p);
t_bool	taux_parg_ok(t_parg parg);
void	taux_pget_init(t_pget *pget, size_t len, ...);
void	*taux_pget_get(t_pget *pget);
void	taux_pget_check(t_pget *pget, void *p);
t_bool	taux_pget_ok(t_pget pget);

/* ************************************************************************** */
/* Test functions                                                             */

void	test_lstnew(void);
void	test_lstadd_front(void);
void	test_lstsize(void);
void	test_lstlast(void);
void	test_lstadd_back(void);
void	test_lstdelone(void);
void	test_lstclear(void);
void	test_lstiter(void);
void	test_lstmap(void);

#endif