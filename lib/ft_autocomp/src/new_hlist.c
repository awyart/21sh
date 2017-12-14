#include "../inc/levenshtein.h"

void		ft_hlstadd(t_dlist **alst, t_dlist *new)
{
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	new->next = *alst;
	(*alst)->prev = new;
	*alst = new;
}

void		ft_hlstadd_void(t_dlist **alst, void *new)
{
	t_dlist		*node;

	node = ft_hlstnew_void(new);
	if (*alst == NULL)
	{
		*alst = node;
		return ;
	}
	node->next = *alst;
	(*alst)->prev = node;
	*alst = node;
}

void		ft_hlstadd_back_void(t_dlist **alst, void *new)
{
	t_dlist		*tmp;
	t_dlist		*node;

	tmp = *alst;
	node = ft_hlstnew_void(new);
	if (*alst == NULL)
	{
		*alst = node;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	node->prev = tmp;
}

void		ft_hlstadd_back(t_dlist **alst, t_dlist *new)
{
	t_dlist	*tmp;

	tmp = *alst;
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

t_dlist		*hlget_last(t_dlist *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next != NULL && list->next->next != NULL)
		list = list->next;
	return (list);
}

t_dlist		*ft_hlstnew(t_lev *new)
{
	t_dlist	*child;

	if ((child = (t_dlist *)malloc(sizeof(t_dlist))) == NULL)
		return (NULL);
	child->content = new;
	child->prev = NULL;
	child->next = NULL;
	return (child);
}

t_dlist		*ft_hlstnew_void(void *new)
{
	t_dlist	*child;

	if ((child = (t_dlist *)malloc(sizeof(t_dlist))) == NULL)
		return (NULL);
	child->content = new;
	child->prev = NULL;
	child->next = NULL;
	return (child);
}

t_dlist		*hl_node_dup(t_dlist *node, size_t size)
{
	t_dlist		*dup;

	if (node == NULL)
		return (NULL);
	if ((dup = (t_dlist *)malloc(sizeof(t_dlist))) == NULL)
		return (NULL);
	dup->content = ft_memalloc(size);
	ft_memcpy(dup->content, node, size);
	dup->next = NULL;
	dup->prev = NULL;
	return (dup);
}
