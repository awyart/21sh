/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_handling.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 13:32:21 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/15 16:12:45 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERM_HANDLING
# define FT_TERM_HANDLING

# include <termios.h>
# include <term.h>
# include <unistd.h>
# include <curses.h>

# include "ft_mem.h"

typedef struct s_terms	t_terms;
typedef struct termios	t_term;

enum					e_term_status
{
	TERM_NULL,
	TERM_INIT,
	TERM_READY
};

struct					s_terms
{
	int					status;
	t_term				old;
	t_term				curr;
	int					current;
};

int						ft_terms_init(t_terms *terms);
int						ft_terms_toggle(t_terms *terms, int on);
void					ft_terms_clear(t_terms **terms);

int						ft_terms_toggle_key(char *key);
int						ft_putc(int c);

t_terms					*ft_terms_get(void);

#endif
