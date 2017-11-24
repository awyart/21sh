/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 03:43:21 by awyart            #+#    #+#             */
/*   Updated: 2017/11/24 03:50:08 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libenv.h"

char	**envdup(void)
{
	char	**env;
	int		size;

	size = ft_tablen(environ);
	if (!(env = (char **)ft_memalloc(sizeof(char *) * (size + 1))))
		return (NULL);


}