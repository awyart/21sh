/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 22:29:05 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/06 17:25:43 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_input_reader.h"


t_reader				*ft_read(void)
{
	static t_reader		reader;
	t_dlist_wrap		wrap;
	char				c;
	int					ret;

	ft_bzero(&wrap, sizeof(t_dlist_wrap));
	wrap.log_fd = open("log.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	while (1)
	{
		read(0, &c, 1);
		if (c == 4)
			break ;
		if (c < 32 || c == 127)
		{
			if ((ret = handle_non_char(c, &wrap)) == 0)
				break ;
		}
		else
			handle_char(c, &wrap);
	}
	reader.status = 0;
	reader.content = (void *)wrap.head;
	close(wrap.log_fd);
	return (&reader);
}
