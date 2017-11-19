/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:42:55 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/08 14:42:55 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

int			ft_memcmp(void *lhs, void *rhs, size_t n)
{
	size_t	i;
	u_char	*bfl;
	u_char	*bfr;

	i = 0;
	bfl = (u_char *)lhs;
	bfr = (u_char *)rhs;
	while (i < n)
	{
		if (bfl[i] != bfr[i])
			return (bfl[i] - bfr[i]);
		i++;
	}
	return (bfl[i] - bfr[i]);
}
