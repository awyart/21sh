/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:50:33 by awyart            #+#    #+#             */
/*   Updated: 2017/12/04 19:28:00 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_dlist					*create_node(char c)
{
	t_dlist				*tmp;
	char				*c_ptr;

	c_ptr = (char *)ft_memalloc(sizeof(char) + 1);
	tmp = ft_dlist_create((void *)(c_ptr));
	if (c_ptr == NULL || tmp == NULL)
	{
		ft_memdel((void **)&c_ptr);
		ft_memdel((void **)&tmp);
		return (NULL);
	}
	*c_ptr = c;
	*(c_ptr + 1) = '\0';
	return (tmp);
}

static int ft_new_wrapper(t_dlist *new, t_dlist_wrap *wrap)
{
	wrap->head = new;
	wrap->last = wrap->head;
	wrap->cursor = NULL;
	return (1);
}

static int ft_add_list(t_dlist *new, t_dlist_wrap *wrap)
{
	new->prev = wrap->last;
	wrap->last->next = new;
	wrap->last = new;
	return (1);
}

static int ft_insert_inlist(t_dlist *new, t_dlist_wrap *wrap, t_sh *sh)
{
	new->next = wrap->cursor;
	new->prev = wrap->last;
	if (wrap->last != NULL)
		wrap->last->next = new;
	else
		wrap->head = new;
	wrap->cursor->prev = new;
	move_right(wrap, sh);
	move_left(wrap, sh);
	return (1);
}

int					handle_char(char c, t_dlist_wrap *wrap, t_sh *sh)
{
	t_dlist 			*new;

	new = NULL;
	if ((new = create_node(c)) == NULL)
		return (-1);
	if (wrap->head == NULL || wrap->head->content == NULL)
	{
		if (ft_new_wrapper(new, wrap) == 0)
			return (0);
	}
	else if (wrap->cursor == NULL || wrap->cursor->content == NULL)
	{
		if (ft_add_list(new, wrap) == 0)
			return (0);
	}
	else
	{
		if (ft_insert_inlist(new, wrap, sh) == 0)
			return (0);
	}
	ft_terms_toggle_key("im");
	ft_terms_toggle_key("ic");
	tputs(&c, 1, &ft_putc);
	ft_terms_toggle_key("ei");
	ft_refresh_line(wrap, sh->term->win, 1);
	wrap->pos += 1;
	return (1);
}
