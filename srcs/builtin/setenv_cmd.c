#include "minishell.h"

int			setenv_cmd(t_sh *sh_env, char **bin_path)
{
	int		i;
	char	**arg;

	i = 0;
	arg = NULL;
	if (is_valid_setenv_arg(&sh_env->input.user_in[6], &i) == FALSE)
	{
		return (exit_error(SETENV_INVAL,
					&sh_env->input.user_in[6], "setenv", -1));
	}
	if (setenv_has_args(&sh_env->input.user_in[6]) == FALSE)
		return (env_cmd(sh_env, bin_path));
	sh_env->input.split_in = ft_arg_split(&sh_env->input.user_in[6],
			&sh_env->input.input_lst);
	if (sh_env->input.split_in[0] != NULL &&
			sh_env->input.split_in[1] != NULL &&
			sh_env->input.split_in[2] != NULL)
		return (exit_error(EX_ARG, sh_env->input.split_in[2], "setenv", -1));
	add_var_to_env(sh_env->input.split_in, &sh_env->cmd_env.env_list);
	sh_env->cmd_env.env_tab = ft_list_to_tab(&sh_env->cmd_env.env_list);
	return (0);
}
