/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdivide.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:48:24 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/08 14:49:07 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int			ft_strdivide(const char *str, const char c, char **lhs, char **rhs)
{
	int		c_pos;

	if ((c_pos = ft_strindex(str, c)) == -1)
		return (0);
	*lhs = ft_strsub(str, 0, c_pos);
	*rhs = ft_strdup(str + c_pos + 1);
	if (*lhs == NULL || *rhs == NULL)
	{
		ft_strdel(lhs);
		ft_strdel(rhs);
		return (0);
	}
	return (1);
}
