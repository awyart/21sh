/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:43:03 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/08 14:43:37 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void		*ft_memalloc(size_t size)
{
	void	*ret;

	if ((ret = malloc(size)) == NULL)
		return (NULL);
	ft_bzero(ret, size);
	return (ret);
}

void		*ft_memalloc_err(size_t size, t_err on_error)
{
	void	*ret;

	if ((ret = malloc(size)) == NULL)
		return (on_error());
	ft_bzero(ret, size);
	return (ret);
}
