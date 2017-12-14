/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:51:28 by awyart            #+#    #+#             */
/*   Updated: 2017/12/14 17:06:57 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_prompt(char c)
{
	if (c == DQUOTE)
		ft_dprintf(STDERR_FILENO, "dquote> ");
	else if (c == QUOTE)
		ft_dprintf(STDERR_FILENO, "quote> ");
	else if (c == SLASH)
		ft_dprintf(STDERR_FILENO, "> ");
	else if (c == Q_OK)
		ft_dprintf(STDERR_FILENO, "$> ");
	return (1);
}

int	len_prompt(char c)
{
	if (c == DQUOTE)
		return (8);
	else if (c == QUOTE)
		return (7);
	else if (c == SLASH)
		return (2);
	else if (c == Q_OK)
		return (3);
	return (0);
}
