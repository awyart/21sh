#include "minishell.h"

int			unsetenv_cmd(t_sh *sh_env, char **bin_path)
{
	sh_env->input.split_in = ft_arg_split(&sh_env->input.user_in[10],
			&sh_env->input.input_lst);
	if (sh_env->input.split_in[0] == NULL)
		return (exit_error(LES_ARG, "", "unsetenv", -1));
	(void)bin_path;
	return (0);
}
