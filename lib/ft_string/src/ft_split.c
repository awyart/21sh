/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:50:48 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/08 14:57:56 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int						split(char **str, char **ret, size_t pos)
{
	char				*new_str;

	if (str == NULL || ret == NULL)
		return (0);
	if ((*ret = ft_strsub(*str, 0, pos)) == NULL)
		return (-1);
	if ((*str)[pos + 1] == '\0')
	{
		ft_strdel(str);
		return (pos);
	}
	if ((new_str = ft_strdup(*str + pos + 1)) == NULL)
	{
		ft_strdel(ret);
		ft_strdel(str);
		return (-1);
	}
	ft_strdel(str);
	*str = new_str;
	return (pos);
}

int						ft_splitc(char **str, char **ret, const char c)
{
	int					pos;

	if (str == NULL || ret == NULL)
		return (-1);
	if ((pos = ft_strindex(*str, c)) == -1)
		return (0);
	return (split(str, ret, pos));
}
