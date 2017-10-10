#include "minishell.h"

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
	char		*line;
	int			i;

	cur_dir = get_cur_dir(sh_env->cur_dir);
	ft_strcpy(sh_env->prev_dir, sh_env->cur_dir);
	while (1)
	{
		i = 0;
		sh_env->cmd_env.bin_path = get_env_path(sh_env->cmd_env.env_tab);
		ft_printf("%s%s%s %C  > ", KCYN, cur_dir, KNRM, UPDOWN);
		line = get_input(g_fd_in, &(sh_env->gnl_leak));
		ft_start(line, sh_env, &cur_dir);
		//while (i < ft_tab_size(comd))
		//{
		//	ft_exec_cmd(comd[i], sh_env, &cur_dir);
		//	i++;
		//}
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
