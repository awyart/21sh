/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:50:09 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/08 14:50:10 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "ft_string.h"

# ifdef FT_BUF_SIZE
#  undef GNL_BUF_SIZE
# endif
# define GNL_BUF_SIZE 1024

int			get_next_line(const int fd, char **line);

#endif
