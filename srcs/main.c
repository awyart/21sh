#include "minishell.h"

int			get_cmd_name(char *cmd_name, char *user_in)
{
	int		i;

	i = 0;
	while (user_in[i] != '\0' && user_in[i] != ' ')
		i++;
	ft_strncpy(cmd_name, user_in, i);
	cmd_name[i] = '\0';
	return (i);
}

void		ft_exec_cmd(char *comd, t_sh *sh_env, char *cur_dir)
{
	int			(*cmd)();

	sh_env->input.user_in = ft_strdup(comd);
	get_cmd_name(sh_env->input.cmd_name, sh_env->input.user_in);
	sh_env->proc.proc_id = get_proc_index(sh_env->input.cmd_name, g_sh_struct);
	cmd = g_sh_struct[sh_env->proc.proc_id].fun_ptr;
	fork_process(sh_env->proc.proc_id, cmd, sh_env, sh_env->cmd_env.bin_path);
	cur_dir = get_cur_dir(sh_env->cur_dir);
	free_tab_str(&sh_env->input.split_in);
	free_str(&sh_env->input.user_in);
	ft_lstdel(&sh_env->input.input_lst, &del_list);
	g_errno = 0;
	g_cmd_ret = 0;
}

char 		**get_input(int fd, char **gnl_leak)
{
	char 	*line;
	char	**cmd;

	line = NULL;
	get_next_line(fd, &line, gnl_leak);
	if (line)
		cmd = ft_split_cmd(line);
	return (cmd);
}

void			fork_process(int proc_id, int (*cmd)(),
		t_sh *sh_env, char **bin_path)
{
	pid_t		pid;
	int			status;

	if (proc_id >= 0)
	{
		status = cmd(sh_env, bin_path);
		return ;
	}
	if ((pid = fork()) == 0)
	{
		status = exec_cmd(sh_env, bin_path);
		exit(status);
	}
	if ((waitpid(pid, &status, 0) < 0))
		exit_error(PID, 0, "my_sh", -1);
}

void			exec_sh(t_sh *sh_env)
{
	char		*cur_dir;
	char		**comd;
	int			i;

	cur_dir = get_cur_dir(sh_env->cur_dir);
	ft_strcpy(sh_env->prev_dir, sh_env->cur_dir);
	while (1)
	{
		i = 0;
		sh_env->cmd_env.bin_path = get_env_path(sh_env->cmd_env.env_tab);
		ft_printf("%s%s%s %C  > ", KCYN, cur_dir, KNRM, UPDOWN);
		comd = get_input(g_fd_in, &(sh_env->gnl_leak));
		while (i < ft_tab_size(comd))
		{
			ft_exec_cmd(comd[i], sh_env, cur_dir);
			i++;
		}
		flush_sh_env(sh_env);
	}
}

int				main(int ac, char **av, char **env)
{
	t_sh		sh_env;

	sig_intercepter();
	ft_init_all(&sh_env, env);
	if (ac == 2 && ft_strcmp(av[1], "-c") == 0)
		write(g_fd_ou, "\e[1;1H\e[2J", 11);
	exec_sh(&sh_env);
	return (0);
}
