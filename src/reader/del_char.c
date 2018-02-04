#include "header"

int				handle_del(t_dlist_wrap *wrap)
{
	t_dlist *todel = NULL;

 	if ((todel = cur_list(wrap)) == NULL)
		return (0);
 	if (todel->prev)
		todel->prev->next = todel->next;
	if (todel->next)
		todel->next->prev = todel->prev;
	todel->prev = NULL;
	todel->next = NULL;
	ft_dlist_free(&todel, ft_memdel);
   	wrap->pos--;
   	wrap->size--;
 	return (1);
}

int				handle_del_right(t_dlist_wrap *wrap)
{
	t_dlist *todel = NULL;

 	if ((todel = cur_list(wrap)) == NULL || todel->next == NULL)
 		return (0);
 	todel = todel->next;
 	if (todel->prev)
		todel->prev->next = todel->next;
	if (todel->next)
		todel->next->prev = todel->prev;
	todel->prev = NULL;
	todel->next = NULL;
	ft_dlist_free(&todel, ft_memdel);
	wrap->size--;
 	return (1);
}