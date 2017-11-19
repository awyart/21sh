/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 13:25:10 by vbastion          #+#    #+#             */
/*   Updated: 2017/08/15 14:09:58 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void		ft_strforeach(char **arr, void (*action)())
{
	while (*arr != NULL)
	{
		ft_putendl(*arr);
		action(*arr);
		arr++;
	}
}

void		ft_strforn(char **arr, size_t n, void (*action)())
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		action(*(arr + i));
		i++;
	}
}

void		ft_strforeach_data(char **arr, void (*action)(), void *data)
{
	while (*arr != NULL)
	{
		action(*arr, data);
		arr++;
	}
}

void		ft_strforn_data(char **arr, size_t n, void (*action)(), void *data)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		action(*(arr + i), data);
		i++;
	}
}
