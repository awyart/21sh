/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_non_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:39:42 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/15 15:03:53 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_input_reader.h"

int						get_next_char(char *c)
{
	return (read(STDIN_FILENO, c, 1));
}

int						move_left(t_dlist_wrap *wrapper)
{
	if (wrapper->head == NULL
		|| (wrapper->current != NULL && wrapper->current == wrapper->head))
		return (0);
	if (wrapper->prev == NULL)
	{
		dprintf(wrapper->log_fd, "HOW TF IS IT NULL?\n");
		ft_terms_toggle(ft_terms_get(), 0);
		exit(1);
	}
	wrapper->current = wrapper->prev;
	wrapper->prev = wrapper->prev->prev;
	ft_terms_toggle_key("le");
	return (1);
}

int						move_right(t_dlist_wrap *wrapper)
{
	if (wrapper->current == NULL)
		return (0);
	ft_terms_toggle_key("nd");
	wrapper->prev = wrapper->current;
	wrapper->current = wrapper->current->next;
	return (1);
}

int						handle_esc(t_dlist_wrap *wrapper)
{
	const t_intfunc		funcs[4] = { 
		&move_up, &move_down, &move_right, &move_left
	};
	char				c;

	if (get_next_char(&c) == -1)
		return (-1);
	if (c == 91)
	{
		if (get_next_char(&c) == -1 || (c < 65 || c > 68))
			return (-1);
		funcs[c - 65](wrapper);
	}
	return (1);
}

int						handle_non_char(char c, t_dlist_wrap *wrapper)
{
	(void)c;
	(void)wrapper;
	dprintf(wrapper->log_fd, "non_char: %d\n", c);
	if (c == '\n')
		return (0);
	else if (c == 27)
		return (handle_esc(wrapper));
	else if (c == 127)
		return (handle_del(wrapper));
	return (1);
}
