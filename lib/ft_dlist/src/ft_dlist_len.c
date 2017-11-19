/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:35:39 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/11 20:38:38 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

size_t			ft_dlist_len(t_dlist *head, t_dlist *end)
{
	size_t		len;

	if (head == NULL)
		return ((size_t)-1);
	len = 0;
	while (head != end)
	{
		len++;
		head = head->next;
	}
	return (len);
}
