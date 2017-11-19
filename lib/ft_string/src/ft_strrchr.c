/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <vbastion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 16:23:59 by vbastion          #+#    #+#             */
/*   Updated: 2017/08/09 19:06:59 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned short	len;
	char			cc;

	len = 0;
	cc = (char)c;
	while (*(s + len))
		len++;
	while (1)
	{
		if (*(s + len) == cc)
			return ((char *)(s + len));
		if (len-- == 0)
			break ;
	}
	return (NULL);
}
