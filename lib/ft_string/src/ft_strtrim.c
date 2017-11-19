/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <vbastion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 15:50:14 by vbastion          #+#    #+#             */
/*   Updated: 2017/08/09 19:14:47 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void		ft_strptrcpy(char *buf, char const *beg, char const *end)
{
	int			i;

	i = 0;
	while ((beg + i) != end)
	{
		*(buf + i) = *(beg + i);
		i++;
	}
}

char		*ft_strtrim(char const *s)
{
	char const	*first;
	char const	*last;
	char		*ret;

	if (!s)
		return (NULL);
	while (ft_iswhitespace(*s))
		s++;
	first = s;
	last = s;
	while (*s)
	{
		if (!ft_iswhitespace(*s))
			last = s;
		s++;
	}
	last++;
	if (!(ret = (char *)malloc(sizeof(char) * (last - first + 1))))
		return (NULL);
	if ((last - first) > 0)
		ft_strptrcpy(ret, first, last);
	*(ret + (last - first)) = '\0';
	return (ret);
}
