/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 03:43:21 by awyart            #+#    #+#             */
/*   Updated: 2017/11/24 07:28:45 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**envdup(void)
{
	char	**env;
	int		size;
	int		i;

	size = ft_tablen(environ);
	i = 0;
	if (!(env = (char **)ft_memalloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		env[i] = ft_strdup(environ[i]);
		i++;
	}
	return (env);
}