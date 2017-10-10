/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 16:44:17 by pkirsch           #+#    #+#             */
/*   Updated: 2017/10/09 14:23:56 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFF_SIZE
#  define BUFF_SIZE 2048
# endif
# define END_FILE 0
# define FAILURE -1
# define FOUND_SOMETHING 1
# define FOUND_LINE 1

# define MAL_ERR_GNL -1221

# include <fcntl.h>
# include "libft.h"

int			get_next_line(int fd, char **line, char **rem);

#endif
