#include "header.h"

t_dlist		*create_node(char c)
{
	t_dlist	*tmp;
	t_chr	*schar;

	schar = ft_memalloc(sizeof(t_chr));
	tmp = ft_dlist_create((void *)(schar));
	if (schar == NULL || tmp == NULL)
	{
		ft_memdel((void **)&schar);
		ft_memdel((void **)&tmp);
		return (NULL);
	}
	schar->c = c;
	schar->is_escaped = '0';
	return (tmp);
}
static int add_in_list(t_dlist_wrap *wrap, t_dlist *new)
{
	t_dlist *list;
	t_dlist *next;

	list = cur_list(wrap);
	next = list->next;
	if (next != NULL)
		next->prev = new;
	list->next = new;
	new->next = next;
	new->prev = list;
	return (0);
}

int			handle_char(char buf[3], t_dlist_wrap *wrap)
{
	t_dlist *new;

	new = NULL;
	if ((new = create_node(c)) == NULL)
		return (-1);
	if (wrap->head == NULL)
	{
		wrap->head = new;
		wrap->pos = 1;
		wrap->size = 1;
	}
	else
	{
		if (add_in_list(wrap, new))
		{
			wrap->pos++;
			wrap->size++;
		}
	}
	return (1);
}