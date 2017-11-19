/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:04:01 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/11 18:05:30 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

void				ft_dlist_free(t_dlist **elem, void (*free_ptr)(void **))
{
	free_ptr(&((*elem)->content));
	ft_memdel((void **)elem);
}
