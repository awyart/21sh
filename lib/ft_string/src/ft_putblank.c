/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putblank.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:50:23 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/08 14:50:23 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void			ft_putblank_fd(size_t cnt, int fd)
{
	while (cnt > FT_STR_BLK_SZ)
	{
		write(fd, FT_STR_BLK, FT_STR_BLK_SZ);
		cnt -= FT_STR_BLK_SZ;
	}
	write(fd, FT_STR_BLK, cnt);
}

void			ft_putblank(size_t cnt)
{
	ft_putblank_fd(cnt, 1);
}
