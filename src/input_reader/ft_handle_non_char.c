/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_non_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:50:33 by awyart            #+#    #+#             */
/*   Updated: 2017/12/14 16:45:53 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int						get_next_char(char *c)
{
	int ret;

	ret = read(STDIN_FILENO, c, 1);
	return (ret);
}

//tableau de pointeurs sur fonction a faire
int						handle_esc(t_dlist_wrap *wrap, t_sh *sh)
{
	char				c;

	if (get_next_char(&c) == -1)
		return (-1);
	if (c == 91)
	{
		if (get_next_char(&c) == -1)
			return (-1);
		if (c == 65)
			move_up(wrap, sh);
		else if (c == 66)
			move_down(wrap, sh);
		else if (c == 67)
			move_right(wrap, sh);
		else if (c == 68)
			move_left(wrap, sh);
		else if (c == 70)
			move_end(wrap, sh);
		else if (c == 72)
			move_begin(wrap, sh);
		else if (c == 53)
			move_up_ctrl(wrap, sh);
		else if (c == 54)
			move_down_ctrl(wrap, sh);
		else if (c == 51)
			handle_del_right(wrap, sh);
		else
			dprintf(g_fd, "<%i>\n", c);
	}
	return (1);
}

int						handle_non_char(char c, t_dlist_wrap *wrap, t_sh *sh)
{
	if (c == '\n')
		return (0);
	else if (c == 27)
		return (handle_esc(wrap, sh));
	else if (c == 127)
		return (handle_del(wrap, sh));
	return (1);
}
