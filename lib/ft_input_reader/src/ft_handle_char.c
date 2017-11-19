/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:39:19 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/15 14:44:35 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_input_reader.h"

# include <stdio.h>

void					__log__(t_dlist_wrap *wrapper)
{
	t_dlist				*list;
	static int			cnt = 0;

	dprintf(wrapper->log_fd, "%-.4d: ",cnt++);
	list = wrapper->head;
	while (list != NULL)
	{
		write(wrapper->log_fd, (char *)(list->content), 1);
		list = list->next;
	}
	write(wrapper->log_fd, "\n", 1);
}

t_dlist					*create_node(char c)
{
	t_dlist				*tmp;
	char				*c_ptr;

	c_ptr = (char *)ft_memalloc(sizeof(char));
	tmp = ft_dlist_create((void *)(c_ptr));
	if (c_ptr == NULL || tmp == NULL)
	{
		ft_memdel((void **)&c_ptr);
		ft_memdel((void **)&tmp);
		return (NULL);
	}
	*c_ptr = c;
	return (tmp);
}

int						add(t_dlist_wrap *wrapper, char c)
{
	t_dlist				*tmp;

	if ((tmp = create_node(c)) == NULL)
		return (-1);
	wrapper->head = tmp;
	wrapper->prev = wrapper->head;
	wrapper->current = NULL;
	__log__(wrapper);
	return (1);
}

int						append(t_dlist_wrap *wrapper, char c)
{
	t_dlist				*tmp;

	if ((tmp = create_node(c)) == NULL)
		return (-1);
	tmp->prev = wrapper->prev;
	wrapper->prev->next = tmp;
	wrapper->prev = tmp;
	__log__(wrapper);
	return (1);
}

int						handle_char(char c, t_dlist_wrap *wrapper)
{
	if (wrapper->head == NULL)
	{
		if (add(wrapper, c) == -1)
			return (-1);
	}
	else if (wrapper->current == NULL)
	{
		if (append(wrapper, c) == -1)
			return (-1);
	}
	else
	{
		*((char *)(wrapper->current->content)) = c;
		wrapper->prev = wrapper->current;
		wrapper->current = wrapper->current->next;
	}
	write(1, &c, 1);
	return (1);
}
