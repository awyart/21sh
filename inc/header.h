
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:48:57 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/27 14:06:31 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H


# include <unistd.h>
# include <stdlib.h>
# include <term.h>
# include <signal.h>
# include <curses.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <fcntl.h>
# include <stdio.h>
# include "ft_printf.h"
# include "libft.h"
# include "ft_dlist.h"

extern char				**environ;
extern char PC;
extern char * UP;
extern char * BC;
extern unsigned ospeed;

typedef struct termios	t_termios;
typedef struct winsize	t_win;
typedef int				(*t_intfunc)();

int g_fd; // pour interface de controle

/*
unsigned short ws_row;	
unsigned short ws_col;	
unsigned short ws_xpixel;	 horizontal size, pixels 
unsigned short ws_ypixel;	vertical size, pixels 
*/


enum					e_term_status
{
	TERM_NULL,
	TERM_INIT,
	TERM_READY
};

enum    e_toktype
{
	NEW,
	WORD,
	IO_NUMBER,
	NEWLINE,
	PIPE,
	DPIPE,
	AND,
	LAND,
	OR,
	LOR,
	SEMICOL,
	DSEMICOL,
	BSLASH,
	LREDIR,
	RSREDIR,
	HEREDOC,
	RDREDIR
};

typedef struct			s_terms
{
	t_termios			prev_term;
	t_termios			this_term;
	int					status;
	int					current;
	t_win				win;
}						t_terms;

typedef struct			s_environ
{	
	char				**env;
	int 				size;
}						t_environ;

typedef struct			s_dlist_wrap
{
	t_dlist				*head;
	t_dlist				*cursor;
	t_dlist				*last;
	int 				pos;
}						t_dlist_wrap;

typedef struct			s_reader
{
	int					status;
	void				*content;
}						t_reader;

typedef struct			s_token
{
	t_dlist				*first_letter;
	t_dlist				*last_letter;
	t_token				*next;
	enum e_type			type;
}						 t_token;

typedef struct			s_sh
{
	t_environ			*env;
	t_terms				*term;
	t_reader            *reader;
	int 				curr_line;
}						t_sh;
	
//	dprintf(g_fd, "\33[H\33[2Jwrap->pos = <%d>\nwin.ws_col == <%d>\nx = <%d>\ncurr_line = <%d>\noffset = <%d>\ngonl = <%d>", \
//		wrap->pos, win.ws_col, x, curr_line, offset, ft_gonextline(x,wrap->pos, offset, 1));

//term
char					*ft_getterm(char **env);
int						ft_init_term(void);
int						ft_terms_init(t_terms *terms);
int						ft_terms_toggle(t_terms *terms, int on);
void					ft_terms_clear(t_terms **terms);
int						ft_terms_toggle_key(char *key);
int						ft_putc(int c);
t_terms					*ft_terms_get(void);

//env
int						ft_setupenv(t_environ *env);

//signal
void					ft_getsignal(void);

//prompt
int						ft_prompt();
int						len_prompt(void);

//input_reader
int						ft_read(t_sh *sh);
int						handle_char(char c, t_dlist_wrap *wrap, t_sh *sh);
int						handle_del(t_dlist_wrap *wrap, t_sh *sh);
int						handle_non_char(char c, t_dlist_wrap *wrap, t_sh *sh);
int						ft_handle_arrow(char c, t_dlist_wrap *wrap, t_sh *sh);
int						move_up(t_dlist_wrap *wrap, t_sh *sh);
int						move_down(t_dlist_wrap *wrap, t_sh *sh);
int						move_left(t_dlist_wrap *wrap, t_sh *sh);
int						move_right(t_dlist_wrap *wrap, t_sh *sh);
int						ft_add_character(char c, t_dlist_wrap *wrap);
int 					ft_printlist(t_dlist_wrap *wrap);
int 					ft_print_list(t_dlist_wrap *wrap);
int 					ft_print_list_cursor(t_dlist_wrap *wrap);
void					ft_refresh_line(t_dlist_wrap *wrap, t_sh *sh, int mode);

// cursor
int 					ft_mv_cursor(t_dlist_wrap *wrap, int curr_line);
int 					ft_mv_cursor_coord(int x, int y);
int						ft_cur_in_string(t_dlist_wrap *wrap);// return la pos du cursor dans la string
int 					ft_count_string(t_dlist_wrap *wrap); // strlen 
int 					ft_mv_cursor_begin(void);
int 					ft_mv_cursor_wib(t_dlist_wrap *wrap);
int 					ft_get_relpos(t_dlist_wrap *wrap, char c);
int 					ft_get_currline(void);

//lexer
int 					ft_lexer(t_sh *sh);
int						ft_print_input(t_dlist **list);

#endif
