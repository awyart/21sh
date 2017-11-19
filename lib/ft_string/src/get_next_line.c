/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:45:58 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/08 14:47:36 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void				add_to_rem(const char *buf, const ssize_t cnt, char **rem)
{
	char			*tmp;

	tmp = *rem;
	*rem = ft_strappend(*rem, buf, cnt);
	ft_strdel(&tmp);
}

int					handle_rem(char **rem, char **line, size_t *ret)
{
	int				pos;
	char			*tmp;

	if (*rem == NULL || ((pos = ft_strindex(*rem, '\n')) < 0))
		return (0);
	*line = ft_strsub(*rem, 0, pos);
	tmp = *rem;
	*rem = ft_strdup(tmp + pos + 1);
	if (*line == NULL || *rem == NULL)
		return (-1);
	*ret = (size_t)pos;
	free(tmp);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static char		*rem = NULL;
	char			buf[GNL_BUF_SIZE];
	ssize_t			ret;
	char			*nl[3];
	size_t			cnt;

	if ((ret = handle_rem(&rem, line, &cnt)))
		return (ret == -1 ? ret : (cnt + 1));
	while ((ret = read(fd, buf, GNL_BUF_SIZE)) > 0)
	{
		add_to_rem(buf, ret, &rem);
		if (ft_strdivide(rem, '\n', line, nl + 1))
		{
			free(rem);
			rem = nl[1];
			return (ft_strlen(*line));
		}
	}
	if (ret == -1 || (ret == 0 && rem == NULL))
		return (ret);
	*line = rem;
	rem = NULL;
	return (ft_strlen(*line) + 1);
}
