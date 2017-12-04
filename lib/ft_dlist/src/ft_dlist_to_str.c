/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_to_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:05:42 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/12 14:10:17 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

char			*ft_dlist_to_str(t_dlist *begin, t_dlist *end)
{
	char		*str;
	size_t		len;
	size_t		pos;

	len = ft_dlist_len(begin, end);
	pos = 0;
	if ((str = (char *)ft_memalloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (begin != end)
	{
		str[pos] = *((char *)(begin->content));
		begin = begin->next;
		pos++;
	}
	return (str);
}
