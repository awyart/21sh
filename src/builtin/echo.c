/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 07:46:36 by awyart            #+#    #+#             */
/*   Updated: 2018/02/26 14:43:39 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

int			ft_echo(t_sh *sh, char **av)
{
	int		i;

	i = 1;
	(void)sh;
	while (av[i] != NULL)
	{
		ft_putstr(av[i++]);
		if (av[i] != NULL)
			ft_putstr(" ");
	}
	ft_putstr("\n");
	return (0);
}
