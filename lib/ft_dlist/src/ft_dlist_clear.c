/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:45:07 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/11 14:48:15 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

void				ft_dlist_clear(t_dlist **list, void (*free_ptr)(void **))
{
	t_dlist			*tmp;
	t_dlist			*curr;

	curr = *list;
	while (curr != NULL)
	{
		tmp = curr;
		free_ptr((void **)(&(tmp->content)));
		ft_memdel((void **)(&tmp));
		curr = curr->next;
	}
}
