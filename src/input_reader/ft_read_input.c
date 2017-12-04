/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:50:33 by awyart            #+#    #+#             */
/*   Updated: 2017/12/04 18:30:52 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int 	ft_no_printable(char c)
{
	if (c < 32 || c == 127)
		return (1);
	return (0);
}

int				ft_read(t_sh *sh)
{
	t_dlist_wrap		wrap;
	char				c;
	int					ret;

	
	ioctl(1, TIOCGWINSZ, &(sh->term->win));
	ft_bzero(&wrap, sizeof(t_dlist_wrap));
	while (1)
	{
		read(0, &c, 1);
		if (c == 4)
			break ;
		if (ft_no_printable(c))
		{
			if ((ret = handle_non_char(c, &wrap, sh)) == 0)
				break ;
		}
		else
			handle_char(c, &wrap, sh);
		ft_printlist(&wrap);
	}
	if (!(sh->reader = (t_reader *)ft_memalloc(sizeof(t_reader))))
		return (0);
	sh->reader->status = 0;
	sh->reader->content = (void *)wrap.head;
	return (1);
}
