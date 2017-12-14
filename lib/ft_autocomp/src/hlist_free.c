#include "../inc/levenshtein.h"

void		hlst_free(t_dlist **list)
{
	t_dlist		*next;

	while (*list)
	{
		next = (*list)->next;
		free((*list)->content);
		free(*list);
		*list = next;
	}
}
