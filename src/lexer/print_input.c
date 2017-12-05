/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 19:16:02 by awyart            #+#    #+#             */
/*   Updated: 2017/12/05 19:28:18 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int 	ft_print_input(t_dlist **list)
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