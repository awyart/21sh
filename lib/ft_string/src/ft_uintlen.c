/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 12:28:05 by vbastion          #+#    #+#             */
/*   Updated: 2017/08/30 10:50:02 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

size_t			ft_uintlen(u_int n)
{
	size_t		i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

size_t			ft_ulonglen(u_long n)
{
	size_t		i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

size_t			ft_intlen(int n)
{
	size_t		i;

	if (n == 0)
		return (1);
	i = n < 0;
	if (i)
		n = -n;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

size_t			ft_longlen(long n)
{
	size_t		i;

	if (n == 0)
		return (1);
	i = n < 0;
	if (i)
		n = -n;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}
