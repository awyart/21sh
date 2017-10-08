#include "minishell.h"

int			env_cmd(t_sh *sh_env, char **bin_path)
{
	t_list	*tmp_env;
	int		i;

	i = 0;
	tmp_env = NULL;
	sh_env->input.split_in = ft_arg_split(sh_env->input.user_in,
			&sh_env->input.input_lst);
	if (sh_env->input.split_in[1] == 0)
		ft_lstiter(sh_env->cmd_env.env_list, &print_lst);
	else
		apply_env_opt(sh_env->input.split_in, bin_path, sh_env);
	return (0);
}
