/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 19:38:47 by awyart            #+#    #+#             */
/*   Updated: 2017/12/14 16:49:22 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	ft_get_value(char buf[1024])
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	while (buf[i])
	{
		if (buf[i] >= 48 && buf[i] <= 57)
		{
			result = ft_atoi((&buf[i])) - 1;
			break ;
		}
		i++;
	}
	return (result);
}

int			ft_get_currline(void)
{
	static char		buf[1024];
	int				pos;

	pos = 0;
	ft_bzero(buf, 1024);
	write(1, "\033[6n", 4);
	while (1)
	{
		if (read(1, buf + pos, 1) == 0)
			break ;
		if (buf[pos] == 82)
		{
			buf[pos] = '\0';
			break ;
		}
		pos++;
	}
	return (ft_get_value(buf));
}

int			ft_count_string(t_dlist *lst)
{
	t_dlist	*list;
	int		count;

	count = 0;
	list = lst;
	while (list != NULL)
	{
		count++;
		list = list->next;
	}
	return (count);
}
