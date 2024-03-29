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
# include <sys/wait.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../lib/libft/inc/libft.h"
# include "../lib/ft_printf/inc/ft_printf.h"
# include "../lib/ft_dlist/inc/ft_dlist.h"
# include "../lib/ft_autocomp/inc/autocompletion.h"


# define DICI dprintf(g_fd, "ICI\n");
# define DLA dprintf(g_fd, "LA\n");
# define DSTR(x) dprintf(g_fd, #x " = %s\n", x);
# define HEREFILE "/tmp/.myherefile"

extern char					**environ;

typedef struct termios		t_termios;
typedef struct s_sh			t_sh;
typedef struct winsize		t_win;
typedef struct s_token		t_token;
typedef struct s_dlist_wrap	t_dlist_wrap;
typedef struct s_process	t_process;
typedef struct s_redir		t_redir;
typedef struct s_cap		t_cap;
typedef struct s_op			t_op;
typedef int					(*t_intfunc)();

int							g_shlvl;
int							g_lvl;
t_sh						*g_sh;
int 						g_cur_pid;
int 						g_test;

# define ERR_MALLOC "erreur dans l'attribution de memoire malloc \n"

# define MAX_FD		9
# define SCHAR_NB	8
//(char c,  int (*f)(t_dlist_wrap *, t_sh *))


typedef struct			s_schar
{
	char				sequ[3];
	char				asc;
}						t_schar;

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
	Q_PIPE,
	Q_HEREDOC,
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

//build_in
int						ft_cd(t_sh *sh, char **av);
char					*get_cur_dir(char *cur_dir_buff);
int						ft_env(t_sh *sh, char **av);
int						ft_setenv(t_sh *sh, char **av);
int						ft_exit(t_sh *sh, char **av);
int						ft_unsetenv(t_sh *sh, char **av);
int						ft_echo(t_sh *sh, char **av);
int						detect_bi(char *str, const t_op *cmd_tab);
int						is_builtin(char *av);

enum					e_built
{
	B_ECHO,
	B_CD,
	B_ENV,
	B_SETENV,
	B_UNSETENV,
	B_EXIT,
	BUILD_IN_SIZE
};

enum 					e_cap
{
	K_UP,
	K_DOWN,
	K_RIGHT,
	K_LEFT,
	K_END,
	K_HOME,
	K_PUP,
	K_PDOWN,
	K_PRIGHT,
	K_PLEFT,
	K_DEL,
	K_DELR,
	K_CTRLD,
	K_CUT,
	K_YANK,
	K_TAB,
	K_QUIT,
	CAP_SIZE
};

enum					e_redir
{
	R_LEFT,
	R_RIGHT,
	R_DLEFT,
	R_DRIGHT,
	R_NB
};

typedef struct			s_red
{
	char				*redir;
	int					index;
	int					(*funct)();
}						t_red;

typedef struct			s_op
{
	char				*name;
	int					(*fun_ptr)(t_sh *, char **);
}						t_op;

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
	int					size;
}						t_environ;

typedef struct			s_dlist_wrap
{
	t_dlist				*head;
	t_dlist				*tmp;
	t_dlist				*yanked;
	int					pos;
	int					size;
	int					col;
}						t_dlist_wrap;


typedef struct			s_cap
{	
	char				cap[3];
	int					(*f)();
}						t_cap;

typedef struct			s_dir
{
	char				cur_dir[PATH_MAX + 1];
	char				prev_dir[PATH_MAX + 1];
	char				*dir_name;
}						t_dir;

typedef struct			s_proc
{
	t_dlist				*semicol;
	t_dlist				*pipes;
}						t_proc;

typedef struct			s_sh
{
	t_environ			env;
	t_terms				term;
	t_dir				dir;
	int 				stdio[3];
	t_dlist_wrap 		*wrap;
	t_dlist				*list;
	t_dlist 			*yanked;
	t_hist				*hist;
	int					ret;
	int 				test;
	int 				hist_multi;
}						t_sh;

//init
void					ft_init_keytab(void);
int						init_cap(void);
int 					get_sh_lvl(t_sh *sh);

//term
char					*ft_getterm(char **env);
int						ft_init_term(void);
int						ft_terms_init(t_terms *terms);
int						ft_terms_toggle(t_terms *terms, int on);
void					ft_terms_clear(t_terms **terms);
int						ft_terms_toggle_key(char *key);
int						ft_putc(int c);
t_terms					*ft_terms_get(void);

//build_in
int						ft_cd(t_sh *sh, char **av);
char					*get_cur_dir(char *cur_dir_buff);
int						ft_env(t_sh *sh, char **av);
int						ft_setenv(t_sh *sh, char **av);
int						ft_exit(t_sh *sh, char **av);
int						ft_unsetenv(t_sh *sh, char **av);
int						ft_echo(t_sh *sh, char **av);
int						detect_bi(char *str, const t_op *cmd_tab);
int						is_builtin(char *av);

//reader
int						ft_count_string(t_dlist *lst);
int						handle_char(char buf[3], t_dlist_wrap *wrap);
int						handle_del(t_dlist_wrap *wrap);
int						handle_del_right(t_dlist_wrap *wrap);
int						move_left(t_dlist_wrap *wrap);
int						move_right(t_dlist_wrap *wrap);
int						move_sright(t_dlist_wrap *wrap);
int						move_sleft(t_dlist_wrap *wrap);
int						ft_read(t_sh *sh);
int						get_func(char buf[3]);
int						is_printable(char buf[3]);
int						is_break(char buf[3]);
int						is_updown(char buf[3]);
int						refresh_line(t_dlist_wrap *wrap, t_sh *sh);
// int						ft_printlist(t_dlist_wrap *wrap, t_sh *sh, char buf[3]);
int						reset_cursor(t_dlist_wrap *wrap, t_sh *sh);
int						move_end(t_dlist_wrap  *wrap);
int						move_home(t_dlist_wrap  *wrap);
t_dlist					*cur_list(t_dlist_wrap *wrap);
int						move_updown(t_dlist_wrap *wrap, char buf[3], t_sh *sh);
int						ft_handle_quote(t_dlist *list);
int						ft_quote(t_dlist_wrap *wrap, t_sh *sh);
int						count_tmp(t_dlist_wrap *wrap, int pos);
int						ft_print_list(t_dlist_wrap *wrap, t_sh *sh);

//cap
int						handle_del(t_dlist_wrap *wrap);
int						handle_del_right(t_dlist_wrap *wrap);
int						move_right(t_dlist_wrap *wrap);
int						move_left(t_dlist_wrap *wrap);
int						move_sdown(t_dlist_wrap *wrap);
int						move_sup(t_dlist_wrap *wrap);
int						apply_cap(char buf[3], t_dlist_wrap *wrap, t_sh *sh);
int						cut_list(t_dlist_wrap *wrap);
int						paste_list(t_dlist_wrap *wrap);

//arg_formating
char					*get_str_in_quotes(char *str);
char					**fmt_input_quote(char **av);
void					fmt_input_spec_chr(char **str);
char					**ft_list_to_tab(t_dlist *list);

//env
int						ft_setupenv(t_environ *env);
char					*get_env_var(char *str, char **environ);
int						cmp_env_var(char *var, char *to_cmp, size_t n);
void					add_var_to_env(t_sh *sh, char **var);
char					*add_eq_between(char **arg);
char					**tab_str_remove(char **base, int (*cmp)(),
						char *to_cmp, size_t limit);
char					*ft_getenv(char **env, char *var);

//signal
void					ft_getsignal(void);
void					ft_signal(int sig);
void					exit_error(char *erro_msg, int exit_id);

bool					jump_loop(void);
void					sig_intercepter(void);
void					sighandler(int sigval);

//prompt
int						ft_prompt(t_sh *sh);
int						len_prompt(t_sh *sh);
void					sig_intercepter(void);
bool					jump_loop(void);
void					ft_start_process(t_sh *sh);
int						ft_init(t_sh *sh, t_hist *hist);

//execution
void					ft_execution(t_sh *sh);
void					hl_print_str(t_dlist *list);
int						exec_cmd(t_dlist *input);
int						skip_quotes(char *str, char quote);
t_dlist					*init_proc_list(char *input, char token);
char					*check_bin(char **paths, char *input);
char					*get_cmd_name(char *input);
void					close_fd(int *pfd);
void					flush_sh(t_sh *sh);
bool					is_binary_file(char *bin_name);
bool					is_valid_path(char *path_bin);
int						exec_builtin(int index, t_dlist *curr, int *save);
int						pipe_processes(t_dlist *curr, int *pfd);
char					*handle_heredoc(char *str, t_sh *sh);
void					exec_procs(t_dlist *pipes);

//redirections
int						r_right(char *input);
int						r_dright(char *input);
int						r_left(char *input);
int						r_dleft(char *input);
char					**extract_redir(t_dlist *curr, int *save);
int						get_redir(char *av);
int						redir_id(char *str);
void					redir_fd(int old_fd, int new_fd);
int						fd_to_file(char *file, int perm);
int						check_src_fd(char *input, int default_fd);
int						do_redirs(t_dlist *redirs);
bool					next_is_fd(char *input, int src);
int						save_builtin_stdio(int index, t_dlist *curr);
void					init_stdio(int *stdio);
void					dup_stdio(int *stdio);

//parsing
char					*is_redir(t_dlist **redir, char *input);
char					*is_arg(t_dlist **arg, char *input);
char					*skip_cmd_name(t_dlist **arg, char *input);
int						printlvl(void);
int						ft_quit(void);
void					ft_signal2(int sig);

void					*g_handlenonchar[SCHAR_MAX];
t_schar					g_spec_char[SCHAR_NB];
t_cap					g_handleinput[CAP_SIZE + 1];
t_op					g_built_in[BUILD_IN_SIZE + 1];

#endif
