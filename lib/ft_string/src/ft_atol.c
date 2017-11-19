/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 09:15:21 by vbastion          #+#    #+#             */
/*   Updated: 2017/04/18 09:17:40 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

#include "ft_string.h"

static long	verify(long ret[2], char flags)
{
	long	tmp;

	if (!(flags & 2))
		return ((flags & 1) ? -ret[0] : ret[0]);
	tmp = ret[0];
	if ((ret[1] >= 0 && ret[1] < 0) || (ret[0] < 0 && ret[1] >= 0))
		return ((flags & 1) ? LONG_MIN : LONG_MAX);
	while (tmp > 10)
	{
		if (!((ret[1] % 10) == (tmp % 10)))
			return ((flags & 1) ? LONG_MIN : LONG_MAX);
		ret[1] /= 10;
		tmp /= 10;
	}
	return ((flags & 1) ? -ret[0] : ret[0]);
}

long		ft_atol(const char *str)
{
	long	ret[2];
	char	flags;

	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	flags = 0;
	if (*str == '-' || *str == '+')
		flags |= *(str++) == '-' ? 1 : 0;
	flags |= ((ft_strlen(str) >= 19) * 2);
	ret[0] = 0;
	while (*str && *str >= 0x30 && *str <= 0x39)
	{
		ret[1] = ret[0] != 0 ? ret[1] * 10 + (*str - '0') : 0;
		ret[0] = ret[0] * 10 + (*(str++) - '0');
	}
	return (verify(ret, flags));
}
