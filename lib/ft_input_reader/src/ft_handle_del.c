/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:15:31 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/15 15:02:42 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_input_reader.h"

static void				move_cursor_left(int n)
{
	int					i;

	i = 0;
	while (i < n)
	{
		ft_terms_toggle_key("le");
		i++;
	}
}

int						ft_print(t_dlist *list)
{
	int					i;

	i = 0;
	while (list != NULL)
	{
		write(1, (char *)(list->content), 1);
		list = list->next;
		i++;
	}
	return (i);
}

int						handle_del(t_dlist_wrap *wrapper)
{
	t_dlist				*tmp;

	if (wrapper->head == NULL || wrapper->prev == NULL)
		return (1);
	else if (wrapper->prev == wrapper->head)
	{
		tmp = wrapper->head;
		wrapper->head = wrapper->head->next;
		wrapper->current = wrapper->head;
		wrapper->prev = NULL;
	}
	else
	{
		tmp = wrapper->prev;
		wrapper->prev = wrapper->prev->prev;
		wrapper->prev->next = wrapper->current;
	}
	ft_memdel(&tmp->content);
	ft_memdel((void **)(&tmp));
	ft_terms_toggle_key("le");
	ft_terms_toggle_key("ce");
	move_cursor_left(ft_print(wrapper->current));
	return (1);
}
