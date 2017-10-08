#include "minishell.h"

int			export_cmd(t_sh *sh_env, char **bin_path)
{
	int		i;
	char	**arg;

	i = 0;
	arg = NULL;
	sh_env->input.split_in = ft_strsplit(&sh_env->input.user_in[6], ' ');
	sh_env->input.input_lst = ft_tab_to_list(sh_env->input.split_in);
	while (sh_env->input.split_in[i])
	{
		if (export_valid_arg(sh_env->input.split_in[i], &arg) == FALSE)
			return (exit_error(INVALID_CMD, arg[1], "export", -1));
		add_var_to_env(arg, &sh_env->cmd_env.env_list);
		i++;
	}
	(void)bin_path;
	return (0);
}
