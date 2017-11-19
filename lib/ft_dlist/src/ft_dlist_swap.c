/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:02:59 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/11 18:07:16 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dlist.h"

void				ft_dlist_swap(t_dlist *lhs, t_dlist *rhs)
{
	void			*content;

	content = lhs->content;
	lhs->content = rhs->content;
	rhs->content = content;
}
