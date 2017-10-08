#include "minishell.h"

void		update_path(t_sh *sh_env)
{
	char	**arg;

	arg = ft_memalloc(sizeof(char *) * 3);
	arg[0] = "PWD";
	arg[1] = sh_env->cur_dir;
	arg[2] = 0;
	add_var_to_env(arg, &sh_env->cmd_env.env_list);
	sh_env->cmd_env.env_tab = ft_list_to_tab(&sh_env->cmd_env.env_list);
}

int			cd_cmd(t_sh *sh_env, char **bin_path)
{
	char	*cur_dir;

	sh_env->input.split_in = ft_arg_split(&sh_env->input.user_in[2],
			&sh_env->input.input_lst);
	if (sh_env->input.split_in[0] != NULL &&
			sh_env->input.split_in[1] != NULL)
		return (exit_error(CD_INVAL, sh_env->input.split_in[1], "cd", -1));
	if (sh_env->input.split_in[0] != NULL)
		cur_dir = sh_env->input.split_in[0];
	else
		cur_dir = get_var_val(&sh_env->cmd_env, "HOME");
	if (chdir(cur_dir) < 0)
		return (exit_error(WRONG_TYPE, sh_env->input.split_in[0], "cd", -1));
	ft_strcpy(sh_env->prev_dir, sh_env->cur_dir);
	(void)**bin_path;
	update_path(sh_env);
	return (0);
}