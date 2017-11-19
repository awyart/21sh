/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_reader.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 22:29:20 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/15 15:01:11 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INPUT_READER_H
# define FT_INPUT_READER_H

# include "ft_mem.h"
# include "ft_term.h"
# include "ft_dlist.h"

# include <fcntl.h>
# include <unistd.h>

typedef struct s_reader	t_reader;

typedef int				(*t_intfunc)();

typedef struct			s_dlist_wrap
{
	t_dlist				*head;
	t_dlist				*current;
	t_dlist				*prev;
	int					log_fd;
}						t_dlist_wrap;

struct					s_reader
{
	int					status;
	void				*content;
};

t_reader				*ft_read(void);

int						handle_char(char c, t_dlist_wrap *wrapper);
int						handle_del(t_dlist_wrap *wrapper);
int						handle_non_char(char c, t_dlist_wrap *wrapper);

int						move_up(t_dlist_wrap *wrapper);
int						move_down(t_dlist_wrap *wrapper);
int						move_left(t_dlist_wrap *wrapper);
int						move_right(t_dlist_wrap *wrapper);

#endif
