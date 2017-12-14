
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
# include "../lib/libft/inc/libft.h"
# include "../lib/ft_printf/inc/ft_printf.h"
# include "../lib/ft_dlist/inc/ft_dlist.h"
# include "../lib/ft_autocomp/inc/autocompletion.h"

extern char				**environ;

typedef struct termios		t_termios;
typedef struct winsize		t_win;
typedef struct s_token		t_token;
typedef struct s_dlist_wrap	t_dlist_wrap;
typedef struct s_process	t_process;
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

enum					e_quote_status
{
	Q_OK,
	QUOTE,
	DQUOTE,
	SLASH,
	QUOT_SIZE
};

enum 					e_type
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
	RDREDIR,
	ETYPE_SIZE
};

typedef struct			s_chr
{
	char 				c;
	char 				is_escaped;
}						t_chr;

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
	t_dlist				*tmp;
	int 				pos;
}						t_dlist_wrap;

typedef struct			s_token
{
	t_dlist				*first_letter;
	t_dlist				*last_letter;
	t_token				*next;
	enum e_type			e_type;
}						t_token;

typedef struct			s_process
{
	t_process			*next;		/* next process in pipeline */
	char				**argv;		/* for exec */
	pid_t				pid;		/* process ID */
	char				completed;	/* true if process has completed */
	char				stopped;	/* true if process has stopped */
	int					status;
	int 				ret;		/* reported status value */
}						t_process;

typedef struct			s_sh
{
	t_environ			env;
	t_terms				term;
	t_dlist				*list;
	t_token 			*token;
	t_process			*process;
	t_hist				*hist;
	int 				curr_line;
	int 				ret;
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
void 					ft_exit(int c);

//env
int						ft_setupenv(t_environ *env);

//signal
void					ft_getsignal(void);
void					ft_signal(int sig);

//prompt
int						ft_prompt(char c);
int						len_prompt(char c);

//input_reader
int						ft_read(t_sh *sh);
int						handle_char(char c, t_dlist_wrap *wrap, t_sh *sh);
int						handle_del(t_dlist_wrap *wrap, t_sh *sh);
int						handle_del_right(t_dlist_wrap *wrap, t_sh *sh);
int						handle_non_char(char c, t_dlist_wrap *wrap, t_sh *sh);
int						move_up(t_dlist_wrap *wrap, t_sh *sh);
int						move_down(t_dlist_wrap *wrap, t_sh *sh);
int						move_left(t_dlist_wrap *wrap, t_sh *sh);
int						move_right(t_dlist_wrap *wrap, t_sh *sh);
int						ft_add_character(char c, t_dlist_wrap *wrap);
int 					ft_printlist(t_dlist_wrap *wrap);
int 					ft_print_list(t_dlist_wrap *wrap, t_sh *sh);
void					ft_refresh_line(t_dlist_wrap *wrap, t_sh *sh);
int 					ft_handle_quote(t_dlist *list);
int 					ft_quote(t_dlist_wrap *wrap, t_sh *sh);
int 					ft_put_wrap_end(t_dlist_wrap *wrap, t_sh *sh);
int 					ft_no_printable(char c);
int						move_left_word(t_dlist_wrap *wrap, t_sh *sh);
int						move_up_ctrl(t_dlist_wrap *wrap, t_sh *sh);
int						move_down_ctrl(t_dlist_wrap *wrap, t_sh *sh);
int						move_begin(t_dlist_wrap *wrap, t_sh *sh);
int						move_end(t_dlist_wrap *wrap, t_sh *sh);
// cursor

int 					ft_count_string(t_dlist *list);
int 					ft_get_currline(void);

//lexer
void 					ft_handle_backslash(t_dlist **line);
int						ft_lexer(t_sh *sh);
int						ft_print_lexinput(t_dlist **list);
t_token					*ft_create_token(t_dlist *line);
int						ft_get_token(t_token *token, t_token **ttoken);
int						ft_print_lexoutput(t_token **list);
int						ft_detect_type(t_dlist *list);
int 					ft_lisspace(t_dlist *list);
char 					ft_lisquote(t_dlist *list, char etalon);
int 					ft_listok(t_dlist *list);
int 					ft_listop(t_dlist *list);

//parser
int 					ft_parser(t_sh *sh);
t_process 				*ft_new_process(t_token *token);
char 					*spe_strdup(t_token *token);
void					ft_add_process(t_process *new,
							t_process **list_proc);
int 					ft_print_parsoutput(t_process **proc);

//job
void 					ft_launch_job(t_sh *sh);

//execution
void 					ft_execution(t_sh *sh);

#endif
