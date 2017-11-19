/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnumber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:50:16 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/08 14:50:17 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int				ft_getnumber(char *str, char **newpos, int *nptr)
{
	int			i;

	if (str == NULL || nptr == NULL)
		return (-1);
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isnumeric(str[i]))
		{
			*nptr = ft_atoi(str + i);
			if (newpos != NULL)
			{
				while (ft_isnumeric(str[i]))
					i++;
				*newpos = str + i;
			}
			return (0);
		}
		i++;
	}
	return (1);
}
