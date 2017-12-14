#include "../inc/levenshtein.h"

t_lev		*new_lev_node(t_dlist *c)
{
	t_lev	*new;
	char	*content;

	content = c->content;
	new = (t_lev *)malloc(sizeof(t_lev));
	new->content = *content;
	new->child = NULL;
	return (new);
}

t_lev		*new_lev_node_c(char *c)
{
	t_lev	*new;

	new = (t_lev *)malloc(sizeof(t_lev));
	new->content = *c;
	new->child = NULL;
	return (new);
}
