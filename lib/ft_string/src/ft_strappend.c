/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:50:42 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/08 14:51:18 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char		*ft_strappend(const char *str, const char *apd, ssize_t n)
{
	char	*ret;
	size_t	len;

	if (str == NULL)
		return (ft_strsub(apd, 0, n));
	len = ft_strlen(str);
	if ((ret = (char *)malloc(sizeof(char) * (len + n + 1))) == NULL)
		return (NULL);
	ft_strcpy(ret, str);
	ft_strncpy(ret + len, apd, n);
	ret[len + n] = '\0';
	return (ret);
}
