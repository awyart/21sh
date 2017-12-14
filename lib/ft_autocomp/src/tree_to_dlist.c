#include "../inc/autocompletion.h"
#include "../inc/levenshtein.h"

t_dlist			*new_hlist_dlist(t_dlist *list)
{
	t_dlist		*new;

	if ((new = (t_dlist *)malloc(sizeof(t_dlist))) == NULL)
		return (NULL);
	new->content = list;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_dlist			*hlist_cpy(t_dlist *tree)
{
	t_dlist		*result;

	result = NULL;
	while (tree)
	{
		ft_hlstadd_back(&result, ft_hlstnew(tree->content));
		tree = tree->next;
	}
	return (result);
}

t_dlist			*get_child(t_dlist *node)
{
	t_lev		*content;

	if (node == NULL)
		return (NULL);
	content = node->content;
	return (content->child);
}

void			tree_to_list(t_dlist *prev, t_dlist *cur, t_dlist **res)
{
	t_lev		*content;
	t_dlist		*list;

	list = NULL;
	if (prev != NULL)
		list = hlist_cpy(prev);
	while (cur)
	{
		content = cur->content;
		if (cur->next != NULL)
			tree_to_list(list, cur->next, res);
		ft_hlstadd_back_void(&list, &content->content);
		cur = content->child;
	}
	ft_hlstadd_void(res, list);
}
