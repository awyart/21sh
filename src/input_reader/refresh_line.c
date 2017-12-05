/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:46:42 by awyart            #+#    #+#             */
/*   Updated: 2017/12/05 18:59:12 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int ft_print_list(t_dlist_wrap *wrap)
{
	t_dlist 	*list;

	ft_prompt();
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

static void ft_reset_cursor(t_win win, t_dlist_wrap *wrap)
{
	int x;

	x = ft_count_string(wrap) - wrap->pos;
	while (x > 0)
	{
		if ((wrap->pos + x + len_prompt()) % win.ws_col > 0)
			ft_terms_toggle_key("le");
		else
		{
			ft_terms_toggle_key("up");
			tputs(tgoto(tgetstr("ch", NULL), 0, win.ws_col - 1), 1, &ft_putc);
		}
		x--;
	}
}

void		ft_refresh_line(t_dlist_wrap *wrap, t_sh *sh, int mode)
{
	int size;

	(void)mode;
	size = ft_count_string(wrap);
	size += len_prompt();
	while (1)
	{
		ft_terms_toggle_key("ce");
		if (size < sh->term->win.ws_col)
		{
			ft_terms_toggle_key("cr");
			break ;
		}
		ft_terms_toggle_key("up");
		size -= sh->term->win.ws_col;
	}
	ft_print_list(wrap);
	ft_reset_cursor(sh->term->win, wrap);
}