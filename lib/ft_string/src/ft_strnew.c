/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <vbastion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 14:09:40 by vbastion          #+#    #+#             */
/*   Updated: 2017/08/09 19:07:20 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static void	l_bzero(char *str, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
}

char		*ft_strnew(size_t size)
{
	char	*ret;

	if ((ret = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	l_bzero(ret, size + 1);
	return (ret);
}
