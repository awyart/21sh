/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <vbastion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 12:11:18 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/08 15:00:11 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char			*ft_pathjoin(char *path, char *name)
{
	char		*ret;
	size_t		plen;
	size_t		nlen;

	if (path == NULL)
		return (ft_strjoin("/", name));
	else if (name == NULL)
		return (ft_strdup(path));
	plen = ft_strlen(path);
	nlen = ft_strlen(name);
	if ((ret = (char *)malloc(sizeof(char) * (plen + nlen + 2))) == NULL)
		return (NULL);
	ft_strncpy(ret, path, plen);
	ret[plen] = '/';
	ft_strncpy(ret + plen + 1, name, nlen);
	ret[plen + 1 + nlen] = '\0';
	return (ret);
}
