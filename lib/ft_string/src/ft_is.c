/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <vbastion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 17:59:25 by vbastion          #+#    #+#             */
/*   Updated: 2017/08/09 17:59:32 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_iswhitespace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

int			ft_isnum(char c)
{
	return (c >= '0' && c <= '9');
}

int			ft_isnumeric(char c)
{
	return (ft_isnum(c) || c == '-' || c == '+');
}

int			ft_isnumber(char *str)
{
	if (ft_isnumeric(*str) == 0)
		return (0);
	str++;
	while (*str != '\0')
	{
		if (ft_isnum(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}
