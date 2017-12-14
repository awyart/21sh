/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 03:43:21 by awyart            #+#    #+#             */
/*   Updated: 2017/12/14 16:34:13 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	**envdup(void)
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

int			ft_setupenv(t_environ *env)
{
	if (!(env->env = envdup()))
		return (0);
	env->size = ft_tablen(env->env);
	return (1);
}
