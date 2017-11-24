/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 03:30:20 by awyart            #+#    #+#             */
/*   Updated: 2017/11/24 03:35:49 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM_H
# define TERM_H

typedef struct termios	t_termios;
typedef struct winsize	t_win;

typedef struct		s_term
{
	t_termios		prev_term;
	t_termios		this_term;
	t_win			win;
}					t_term;

typedef struct		s_env
{
	char			**env;
	int				size;
}					t_env;

/*
**about term
*/

int	ft_init_term(void);

/*
**about env
*/

#endif
