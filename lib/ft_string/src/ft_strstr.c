/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <vbastion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:26:43 by vbastion          #+#    #+#             */
/*   Updated: 2017/08/09 19:06:18 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char		*ft_strstr(const char *big, const char *little)
{
	unsigned short	i;
	unsigned short	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (*(big + i))
	{
		if (*(big + i) == *little)
		{
			j = 0;
			while (*(big + i + j) == *(little + j) &&
					*(big + i + j) && *(little + j))
				j++;
			if (*(little + j) == '\0')
				return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}
