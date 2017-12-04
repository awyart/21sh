/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_findchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 13:57:20 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/12 13:59:12 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist				*ft_dlist_findchar(t_dlist *lhs, char c)
{
	while (lhs != NULL)
	{
		if (*((char *)(lhs->content)) == c)
			return (lhs);
		lhs = lhs->next;
	}
	return (NULL);
}
