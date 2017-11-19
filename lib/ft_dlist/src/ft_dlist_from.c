/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_from.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:44:34 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/11 15:14:01 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist				*ft_dlist_from_char(char c)
{
	t_dlist			*ret;
	char			*ptr;

	if ((ptr = (char *)ft_memalloc(sizeof(char))) == NULL)
		return (NULL);
	*ptr = c;
	if ((ret = ft_dlist_create(ptr)) == NULL)
	{
		ft_memdel((void **)(&ptr));
		return (NULL);
	}
	return (ret);
}

static void			dlist_change(t_dlist **head, t_dlist **curr, t_dlist *value)
{
	if (*head == NULL)
	{
		*head = value;
		*curr = *head;
	}
	else
	{
		(*curr)->next = value;
		*curr = value;
	}
}

t_dlist				*ft_dlist_from_str(char *str)
{
	t_dlist			*ret;
	t_dlist			*curr;
	t_dlist			*tmp;

	if (str == NULL)
		return (NULL);
	ret = NULL;
	while (*str != '\0')
	{
		if ((tmp = ft_dlist_from_char(*str)) == NULL)
		{
			ft_dlist_clear(&ret, &ft_memdel);
			return (NULL);
		}
		dlist_change(&ret, &curr, tmp);
		str++;
	}
	return (ret);
}
