/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:46:42 by awyart            #+#    #+#             */
/*   Updated: 2017/12/14 16:50:35 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int				ft_print_list(t_dlist_wrap *wrap, t_sh *sh)
{
	t_chr	*schar;
	t_dlist	*list;

	ft_prompt(sh->ret);
	if (sh->ret == Q_OK)
		list = wrap->head;
	else
		list = wrap->tmp;
	if (sh->ret != Q_OK && list)
		list = list->next;
	while (list != NULL)
	{
		schar = list->content;
		ft_dprintf(STDOUT_FILENO, "%c", schar->c);
		list = list->next;
	}
	return (0);
}

static void		ft_reset_cursor(t_win win, t_dlist_wrap *wrap, t_sh *sh)
{
	int				x;

	x = ft_count_string(wrap->head) - wrap->pos;
	while (x > 0)
	{
		if ((wrap->pos + x + len_prompt(sh->ret)) % win.ws_col > 0)
			ft_terms_toggle_key("le");
		else
		{
			ft_terms_toggle_key("up");
			tputs(tgoto(tgetstr("ch", NULL), 0, win.ws_col - 1), 1, &ft_putc);
		}
		x--;
	}
}

static void		wrap_copy(t_dlist_wrap *temp, t_dlist_wrap *wrap)
{
	temp->tmp = wrap->tmp;
	temp->pos = wrap->pos;
	temp->cursor = wrap->cursor;
	temp->last = wrap->last;
}

static int		get_coord(t_dlist_wrap *wrap, int ret)
{
	int				size;

	size = 0;
	if (ret != Q_OK)
		size = ft_count_string(wrap->tmp) - 1;
	else
		size = ft_count_string(wrap->head);
	size += len_prompt(ret);
	return (size);
}

void			ft_refresh_line(t_dlist_wrap *wrap, t_sh *sh)
{
	int				size;
	t_dlist_wrap	temp;

	size = get_coord(wrap, sh->ret);
	wrap_copy(&temp, wrap);
	ft_put_wrap_end(wrap, sh);
	while (1)
	{
		ft_terms_toggle_key("cr");
		ft_terms_toggle_key("ce");
		if (size <= sh->term.win.ws_col)
			break ;
		ft_terms_toggle_key("up");
		size -= sh->term.win.ws_col;
	}
	wrap_copy(wrap, &temp);
	ft_print_list(wrap, sh);
	ft_reset_cursor(sh->term.win, wrap, sh);
	if (get_coord(wrap, sh->ret) % sh->term.win.ws_col == 0)
	{
		ft_terms_toggle_key("cr");
		ft_terms_toggle_key("do");
	}
}
