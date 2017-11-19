/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <vbastion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:56:50 by vbastion          #+#    #+#             */
/*   Updated: 2017/08/15 13:31:51 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void		ft_putstr_fd(char const *s, int fd)
{
	unsigned short	len;

	if (!s || fd < 0)
		return ;
	len = ft_strlen(s);
	write(fd, s, len);
}

void		ft_putstr(char const *s)
{
	unsigned short	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	write(1, s, len);
}

void		ft_putendl(char const *s)
{
	unsigned short	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	write(1, s, len);
	write(1, "\n", 1);
}

void		ft_putendl_fd(char const *s, int fd)
{
	unsigned short	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	write(fd, s, len);
	write(fd, "\n", 1);
}
