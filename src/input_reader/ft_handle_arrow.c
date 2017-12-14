/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_arrow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:29:19 by awyart            #+#    #+#             */
/*   Updated: 2017/12/14 16:41:26 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		move_left(t_dlist_wrap *wrap, t_sh *sh)
{
	int y;

	if (wrap->head == NULL || wrap->last == NULL)
		return (0);
	if (wrap->tmp && wrap->cursor == wrap->tmp->next)
		return (0);
	wrap->pos -= 1;
	wrap->cursor = wrap->last;
	wrap->last = wrap->last->prev;
	y = sh->term.win.ws_col;
	if ((wrap->pos + len_prompt(sh->ret))
		% sh->term.win.ws_col == sh->term.win.ws_col - 1)
	{
		while (--y)
			ft_terms_toggle_key("nd");
		ft_terms_toggle_key("up");
		return (1);
	}
	ft_terms_toggle_key("le");
	return (2);
}

int		move_right(t_dlist_wrap *wrap, t_sh *sh)
{
	if (wrap->cursor == NULL)
		return (0);
	wrap->pos += 1;
	wrap->last = wrap->cursor;
	wrap->cursor = wrap->cursor->next;
	if ((wrap->pos + len_prompt(sh->ret)) % sh->term.win.ws_col == 0)
	{
		ft_terms_toggle_key("cr");
		ft_terms_toggle_key("do");
		return (1);
	}
	ft_terms_toggle_key("nd");
	return (2);
}

int		move_up(t_dlist_wrap *wrap, t_sh *sh)
{
	move_up_ctrl(wrap, sh);
	return (1);
}

int		move_down(t_dlist_wrap *wrap, t_sh *sh)
{
	move_down_ctrl(wrap, sh);
	return (1);
}
