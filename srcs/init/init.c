#include "minishell.h"

void	ft_init_all(t_sh *sh_env, char **env)
{
	char	**local_env;

	setlocale(LC_ALL, "");
	g_fd_ou = STDO;
	g_fd_in = STDI;
	g_fd_err = STDE;
	g_cmd_ret = 0;
	sh_env->input.user_in = NULL;
	sh_env->input.input_lst = NULL;
	sh_env->cmd_env.env_list = NULL;
	sh_env->gnl_leak = NULL;
	local_env = ft_tab_dup(env);
	sh_env->cmd_env.env_tab = local_env;
	sh_env->cmd_env.env_tab = env;
	sh_env->cmd_env.env_list = ft_tab_to_list(env);
}
