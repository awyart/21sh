/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:37:02 by awyart            #+#    #+#             */
/*   Updated: 2017/12/09 20:19:25 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int 	ft_detect_type(t_dlist *list)
{
	char *a;
	char *b;
	char *c;

	c = (char *)list->content;
	if (list->next)
		b = (char *)list->next->content;
	if (list->next->next)
		a = (char *)list->next->next->content;
	if (*c == '\\')
	{
		if (*b == 'n')
			return (NEWLINE);
		if (*b == '\\')
			return (BSLASH);
	}
	if (*c == '|')
	{
		if (*b == '|')
			return (LOR);
		if (*b == '&')
			return (DPIPE);
		return (PIPE);
	}
	if (*c == '&')
	{
		if (*b == '&')
			return (LAND);
		return (AND);
	}
	if (*c == '>')
	{
		if (*b == '>')
			return (RDREDIR);
		return (RSREDIR);
	}
	if (*c == '<')
		return (LREDIR);
	if (*c == ';')
	{
		if (*b == ';')
			return (DSEMICOL);
		return (SEMICOL);
	}
	if (ft_isdigit((int)*c))
	{
		if (ft_isdigit((int)*b))
			if (*a == '>')
				return (IO_NUMBER);
		if (*b == '>')
			return (IO_NUMBER);
	}
 	return (WORD);
}

