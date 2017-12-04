/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:46:42 by awyart            #+#    #+#             */
/*   Updated: 2017/12/04 19:26:10 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int ft_print_list(t_dlist_wrap *wrap)
{
	t_dlist 	*list;

	list = wrap->head;
	while (list != NULL)
	{
		tputs(list->content, 1, &ft_putc);
		list = list->next;
	}
	return (0);
}

int ft_print_list_cursor(t_dlist_wrap *wrap)
{
	t_dlist 	*list;

	list = wrap->cursor;
	while (list != NULL)
	{
		tputs(list->content, 1, &ft_putc);
		list = list->next;
	}
	return (0);
}

int		ft_add_character(char c, t_dlist_wrap *wrap)
{
	(void)wrap;
	//ft_terms_toggle_key("ic");
	write(STDOUT_FILENO, &c, 1);
	return (1);
}

static int ft_gonextline(int x, int offset, int mode)
{
	(void)x;
	if (mode == 1)
		return (offset);
	else
		return (offset);
}

void		ft_refresh_line(t_dlist_wrap *wrap, t_win win, int mode)
{
	char	*gotostr;
	int		curr_line;
	int		x;

	//ft_terms_toggle_key("sf"); // scroll 1 up;

	gotostr = tgetstr("cm", NULL);
	curr_line = ft_get_currline();
	x = wrap->pos + mode + len_prompt();
	dprintf(g_fd, "\33[H\33[2Jwrap->pos = <%d>\nwin.ws_col == <%d>\nx = <%d>\ncurr_line = <%d>\noffset = <%d>\ngonl = <%d>\nmode = <%d>", \
		wrap->pos, win.ws_col, x, curr_line,0, ft_gonextline(x, 0, mode), mode);
	ft_terms_toggle_key("cd");
	tputs(tgoto(gotostr, 0, curr_line), 1, ft_putc);
	ft_print_list_cursor(wrap);
	// repositioner le curseur
	
}