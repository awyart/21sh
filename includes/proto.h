#ifndef PROTO_H
# define PROTO_H

int			echo_cmd(t_sh *sh_env, char **env);
int			cd_cmd(t_sh *sh_env, char **env);
int			setenv_cmd(t_sh *sh_env, char **env);
int			unsetenv_cmd(t_sh *sh_env, char **bin_path);
int			env_cmd(t_sh *sh_env, char **env);
int			exit_cmd(t_sh *sh_env, char **env);
int			exec_cmd(t_sh *sh_env, char **env);

int			export_cmd(t_sh *sh_env, char **bin_path);

/*minishell*/

void		parse_input(t_in *input);
int			is_esc_char(char *str);
int			get_proc_index(char *cmd, const t_shcmd *cmd_tab);
char		**get_input(int fd,  char **gnl_leak);
int			get_cmd_name(char *cmd_name, char *user_in);
char		**ft_arg_split(char *str, t_list **list);
char		*check_bin(char **paths, t_in *input);
void		format_input(char **str);
char		**ft_format_tab_content(char **tab, void (*fmt)());
char		*replace_spec_char(char *user_in, int size);
t_bool		export_valid_arg(char *str, char ***arg);
t_bool		is_valid_setenv_arg(char *str, int *pos);
char		*get_str_in_quotes(char *str, int *pos);
void		fork_process(int proc_id, int (*cmd)(),
		t_sh *sh_env, char **bin_path);
void		apply_env_opt(char **arg, char **bin_path, t_sh *env);

t_bool		is_env_var(char *str, char *var);
void		add_var_to_env(char **arg, t_list **env);
t_bool		setenv_has_args(char *str);

void		update_path(t_sh *sh_env);
void		remove_from_path(char *path);
void		add_to_path(char *path, char *file_name);
char		*get_var_val(t_shenv *cmd_env, char *var);

int			exit_error(int error, char *bad_input, char *cmd_name, int ret);
void		sighandler(int sigval);
void		sig_intercepter(void);
void		flush_sh_env(t_sh *env);
void		ft_init_all(t_sh *sh_env, char **env);

/*utilitary*/

void		free_str(char **to_free);
char		**ft_split_cmd(char *s);

void		free_tab_str(char ***tab);

t_list		*ft_tab_to_list(char **str);
void		print_lst(t_list *node);
void		ft_print_tab(char **tab);
int			ft_tab_size(char **tab);
char		**ft_list_to_tab(t_list **list);
char		**ft_tab_dup(char **tab);
char		*get_cur_dir(char *cur_dir_buff);
char		**get_env_path(char **env);
void		remove_var_from_env(char *var, t_list **env);
void		del_list(void *content, size_t size);

#endif