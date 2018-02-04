#include "header.h"

t_dlist 	*cur_list(t_dlist_wrap *wrap)
{
	int pos;
	t_dlist *list;

	list = wrap->head;
	pos = wrap->pos;
	while (--pos && list != NULL)
		list = list->next;
	return (list);
}


// faire une belle fonc
int 	get_func(char buf[3], t_dlist_wrap *wrap, t_sh *sh)
{
	int i;

	i = -1;
	if (is_printable(buf))
		return (0);
	while (++i)
	{
		if (ft_strncmp(buf, g_handleinput[i].cap, 3) == 0)
			return (g_handleinput[i].func);
	}
	return (-1);
}

int		ft_read(t_sh *sh)
{
	char	buf[3];
	int		(*ptr)() = NULL;
	int 	ret = 0;

	ft_bzero(&wrap, sizeof(t_dlist_wrap));
	ft_bzero(buf, 3);
	while (1)
	{
		ioctl(1, TIOCGWINSZ, &(sh->term.win));
		read(STDIN_FILENO, buf,  3);
		dprintf(1, "<%s>", buf);
		if (is_break(buf))
			break ;
		ret = get_func(buf);
		if (ret > 0)
		{
			ptr = g_handleinput[ret];
			ret = ptr(&wrap, sh);
		}
		else if (ret == 0)
			handle_char(buf, &wrap, sh);
		//clearbuf
		//ft_printlist(&wrap, sh);
	}
	sh->list = wrap.head;
	return (1);
}