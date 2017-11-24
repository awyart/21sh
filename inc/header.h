/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:48:57 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/24 08:28:25 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <term.h>
# include <signal.h>
# include <curses.h>
# include <termios.h>
# include <sys/ioctl.h>
# include "ft_printf.h"
# include "libft.h"

typedef struct termios	t_termios;
typedef struct winsize	t_win;

typedef struct		s_termenv
{
	t_termios		prev_term;
	t_termios		this_term;
	t_win			win;
}					t_termenv;

typedef struct		s_environ
{
	char			**environ;
	int 			size;
}					t_environ;

typedef struct		s_sh
{
	t_environ		env;
	t_termenv		term;
}					t_sh;

extern char **environ;

char 	*ft_getterm(char **env);
char	**envdup(void);

int	ft_init_term(void);
 

#endif
