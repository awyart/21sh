/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_arrow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:29:19 by awyart            #+#    #+#             */
/*   Updated: 2017/11/30 22:47:35 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int				ft_handle_arrow(char c, t_dlist_wrap *wrapper, t_sh *sh)
{
	if (c == 65)
		move_up(wrapper, sh);
	else if (c == 66)
		move_down(wrapper, sh);
	else if (c == 67)
		move_right(wrapper, sh);
	else if (c == 68)
		move_left(wrapper, sh);
	else
		return (0);
	return (1);
}

int						move_left(t_dlist_wrap *wrapper, t_sh *sh)
{
	int x;

	ioctl(1, TIOCGWINSZ, &(sh->term->win));
	if (wrapper->head == NULL || wrapper->last == NULL )
		return (0);
	wrapper->pos -= 1;
	wrapper->cursor = wrapper->last;
	wrapper->last = wrapper->last->prev;
	x = wrapper->pos;
	if ((x + len_prompt()) % sh->term->win.ws_col == sh->term->win.ws_col - 1)
	{
		tputs(tgoto(tgetstr("cm", NULL), sh->term->win.ws_col - 1, ft_get_currline() - 1), 1, &ft_putc);
	}
	else
		ft_terms_toggle_key("le");
	return (1);
}

int						move_right(t_dlist_wrap *wrapper, t_sh *sh)
{
	int x;

	ioctl(1, TIOCGWINSZ, &(sh->term->win));
	if (wrapper->cursor == NULL)
		return (0);
	wrapper->pos += 1;
	x = wrapper->pos;
	wrapper->last = wrapper->cursor;
	wrapper->cursor = wrapper->cursor->next;
	if ((x + len_prompt()) % sh->term->win.ws_col == 0)
	{
		tputs(tgoto(tgetstr("cm", NULL), 0, ft_get_currline() + 1), 1, &ft_putc);
	}
	else
		ft_terms_toggle_key("nd");
	return (1);
}

int					move_up(t_dlist_wrap *wrapper, t_sh *sh)
{
	(void)wrapper;
	(void)sh;
	ft_dprintf(STDOUT_FILENO, "UP");
	return (1);
}

int					move_down(t_dlist_wrap *wrapper, t_sh *sh)
{
	(void)wrapper;
	(void)sh;
	ft_dprintf(STDOUT_FILENO, "DOWN");
	return (1);
}
