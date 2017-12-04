/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:04:01 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/30 22:00:15 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

void				ft_dlist_free(t_dlist **elem, void (*free_ptr)(void **))
{
	if (*elem)
	{
		free_ptr(&((*elem)->content));
		ft_memdel((void **)elem);
	}
}
