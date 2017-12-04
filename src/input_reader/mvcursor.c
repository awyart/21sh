/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvcursor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:22:40 by awyart            #+#    #+#             */
/*   Updated: 2017/12/04 19:17:17 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int 	ft_mv_cursor_wib(t_dlist_wrap *wrap)
{
	char *gotostr;
	int x;
	int y;

	x = ft_get_relpos(wrap, 'x');
	y = ft_get_relpos(wrap, 'y');
	gotostr = tgetstr("cm", NULL);
	tputs(tgoto(gotostr, x, y), 1, &ft_putc);
	return (1);
}

int 	ft_mv_cursor_begin(void)
{
	char *gotostr;
	int x;
	int y;

	x = 0;
	y = 0;
	gotostr = tgetstr("cm", NULL);
	tputs(tgoto(gotostr, x, y), 1, &ft_putc);
	return (1);
}

int ft_printlist(t_dlist_wrap *wrap)
{
	t_dlist 	*list;

	list = wrap->head;
	dprintf(g_fd, "\n LIST \n");
	while (list != NULL)
	{
		if (list != wrap->cursor)
			dprintf(g_fd, "%s>", list->content);
		else
			dprintf(g_fd, "\033[0;7;37;40m %s \033[0;0;0;0m->", list->content);
		list = list->next;
	}
	dprintf(g_fd,"NULL\n");
	if (wrap)
	{
		if (wrap->head)
			dprintf(g_fd, " head <%s>", wrap->head->content);
		if (wrap->last)
			dprintf(g_fd, "last <%s>", wrap->last->content);
		if (wrap->cursor)
			dprintf(g_fd, " cursor <%s>", wrap->cursor->content);
	}
	dprintf(g_fd, "\n curr_line<%d>\n", ft_get_currline());
	return (0);
}