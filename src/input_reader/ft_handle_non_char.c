/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_non_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:50:33 by awyart            #+#    #+#             */
/*   Updated: 2017/11/30 19:44:37 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int						get_next_char(char *c)
{
	int ret;

	ret = read(STDIN_FILENO, c, 1);
	return (ret);
}

int						handle_esc(t_dlist_wrap *wrapper, t_sh *sh)
{
	char				c;

	if (get_next_char(&c) == -1)
		return (-1);
	if (c == 91)
	{
		if (get_next_char(&c) == -1 || (c < 65 || c > 68))
			return (-1);
		ft_handle_arrow(c, wrapper, sh);
	}
	return (1);
}

int						handle_non_char(char c, t_dlist_wrap *wrapper, t_sh *sh)
{
	if (c == '\n')
		return (0);
	else if (c == 27)
		return (handle_esc(wrapper, sh));
	else if (c == 127)
		return (handle_del(wrapper, sh));
	return (1);
}
