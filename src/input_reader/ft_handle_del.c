/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:28:02 by awyart            #+#    #+#             */
/*   Updated: 2017/12/14 16:43:47 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		move_left_del(t_dlist_wrap *wrap, t_sh *sh)
{
	int x;

	ioctl(1, TIOCGWINSZ, &(sh->term.win));
	if (wrap->head == NULL || wrap->last == NULL)
		return (0);
	wrap->pos -= 1;
	wrap->cursor = wrap->last;
	wrap->last = wrap->last->prev;
	x = wrap->pos;
	if ((x + len_prompt(sh->ret)) %
		sh->term.win.ws_col == sh->term.win.ws_col - 1)
	{
		tputs(tgoto(tgetstr("cm", NULL),
			sh->term.win.ws_col - 1, ft_get_currline() - 1), 1, &ft_putc);
	}
	else
		ft_terms_toggle_key("le");
	return (1);
}

int				handle_del(t_dlist_wrap *wrap, t_sh *sh)
{
	t_dlist *todel;
	t_dlist *list;

	if (!wrap || !wrap->head || !wrap->last)
		return (-1);
	todel = wrap->last;
	list = wrap->cursor;
	move_left_del(wrap, sh);
	wrap->cursor = list;
	if (todel->prev)
		todel->prev->next = todel->next;
	if (todel->next)
		todel->next->prev = todel->prev;
	todel->prev = NULL;
	todel->next = NULL;
	ft_dlist_free(&todel, ft_memdel);
	if (wrap->head == NULL || wrap->head->content == NULL)
		wrap->head = list;
	ft_refresh_line(wrap, sh);
	return (1);
}

int				handle_del_right(t_dlist_wrap *wrap, t_sh *sh)
{
	t_dlist *list;

	if ((!wrap || !wrap->head || !wrap->cursor))
		return (-1);
	list = wrap->cursor;
	wrap->cursor = wrap->cursor->next;
	ft_dlist_delone(&list);
	if (wrap->head == NULL || wrap->head->content == NULL)
		wrap->head = wrap->cursor;
	ft_refresh_line(wrap, sh);
	return (1);
}
