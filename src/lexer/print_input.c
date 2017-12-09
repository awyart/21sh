/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 19:16:02 by awyart            #+#    #+#             */
/*   Updated: 2017/12/09 20:37:24 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int 	ft_print_lexinput(t_dlist **list)
{
	t_dlist *tmp;
	int 	count;

	tmp = *list;
	count = 0;
	dprintf(g_fd, "\n Liste fournie au lexer: \n");
	while (tmp != NULL)
	{
		dprintf(g_fd, "%s", tmp->content);
		tmp = tmp->next;
		count++;
	}
	return (count);
}

int 	ft_print_lexoutput(t_token **list)
{
	t_token *tmp;
	t_dlist *begin;
	int 	count;

	tmp = *list;
	count = 0;
	dprintf(g_fd, "\n Sortie au lexer: \n");
	while (tmp != NULL)
	{
		begin = tmp->first_letter;
		dprintf(g_fd, "|");
		while (begin != NULL && begin != tmp->last_letter)
		{
			dprintf(g_fd, "%s", begin->content);
			begin = begin->next;
		}
		if (begin)
			dprintf(g_fd, "%s",begin->content);
		dprintf(g_fd, "|<%d>->", tmp->e_type);
		tmp = tmp->next;
		count++;
	}
	dprintf(g_fd, " NULL\n");
	return (count);
}
