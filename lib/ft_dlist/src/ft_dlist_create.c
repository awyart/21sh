/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:15:42 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/11 14:46:58 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

t_dlist				*ft_dlist_create(void *content)
{
	t_dlist			*ret;

	if ((ret = (t_dlist *)ft_memalloc(sizeof(t_dlist))) == NULL)
		return (NULL);
	ret->content = content;
	return (ret);
}
