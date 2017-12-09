/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   htok.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 18:03:03 by awyart            #+#    #+#             */
/*   Updated: 2017/12/09 20:47:40 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int ft_listok(t_dlist *list)
{
	char *c = NULL;
	char *a = NULL;

	c = (char *)list->content;
	if (list->prev)
		a = (char *)list->prev->content;
	if (a && *a == '\\')
		return (0);
	if (*c == '|' || *c == '&' || *c == '<')
		return (1);
	if (*c == '>' || *c == ';')
		return (1);
	return (0);
}

int ft_lisspace(t_dlist *list)
{
	char *c;

	c = (char *)list->content;
	if (*c == '\n' || *c == ' ' || *c == '\v'
		|| *c == '\r' || *c == '\f' || *c == '\t')
		return (1);
	return (0);
}

char ft_lisquote(t_dlist *list, char etalon)
{
	char *c;

	c = (char *)list->content;
	if (etalon == 0)
	{
		if (*c == '\"' || *c == '\'')
			return (*c);
	}
	else
	{
		if (*c == etalon)
			return (1);
	}
	return (0);
}

int ft_listop(t_dlist *list)
{
	if (ft_lisspace(list) || ft_listok(list))
		return (1);
	return (0);
}
