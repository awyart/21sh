/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:41:19 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/11 14:44:26 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist				*ft_dlist_insert(t_dlist *curr, t_dlist *chain)
{
	t_dlist			*last;

	last = ft_dlist_last(chain);
	last->next = curr->next;
	curr->next = chain;
	return (last);
}
