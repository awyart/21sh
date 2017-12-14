/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvcursor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:22:40 by awyart            #+#    #+#             */
/*   Updated: 2017/12/14 16:23:39 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int ft_printlist(t_dlist_wrap *wrap)
{
	t_dlist 	*list;
	t_chr		*schar;

	list = wrap->head;
	dprintf(g_fd, "\33[H\33[2JLIST \n");
	while (list != NULL)
	{
		schar = list->content;
		if (list != wrap->cursor)
			dprintf(g_fd, "%c>", schar->c);
		else
			dprintf(g_fd, "\033[0;7;37;40m %c \033[0;0;0;0m->", schar->c);
		list = list->next;
	}
	dprintf(g_fd,"NULL\n");
	if (wrap)
	{
		if (wrap->head)
		{
			schar = wrap->head->content;
			dprintf(g_fd, " head <%c>", schar->c);
		}
		if (wrap->last)
		{
			schar = wrap->last->content;
			dprintf(g_fd, "last <%c>", schar->c);
		}
		if (wrap->cursor)
		{
			schar = wrap->cursor->content;
			dprintf(g_fd, " cursor <%c>", schar->c);
		}
	}
	dprintf(g_fd, "\n curr_line<%d>\n", ft_get_currline());
	return (0);
}