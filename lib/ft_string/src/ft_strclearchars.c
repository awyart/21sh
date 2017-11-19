/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclearchars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:49:27 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/08 14:50:04 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char			*ft_strclearchars(char *str, char *chars)
{
	char		*ret;
	char		*tmp;
	int			i;
	int			j;

	if ((tmp = ft_strnew(ft_strlen(str))) == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (ft_strindex(chars, str[i]) == -1)
		{
			tmp[j] = str[i];
			j++;
		}
		i++;
	}
	ret = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (ret);
}
