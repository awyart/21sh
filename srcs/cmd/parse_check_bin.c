#include "minishell.h"

int			get_proc_index(char *cmd, const t_shcmd *cmd_tab)
{
	int		i;
	int		ret;

	i = 0;
	while (cmd_tab[i].fun_ptr != NULL)
	{
		if ((ret = ft_strcmp(cmd, cmd_tab[i].name)) == 0)
			return (i);
		i++;
	}
	return (-1);
}

t_bool		is_valid_path(char *path_bin)
{
	if (access(path_bin, X_OK) == 0)
		return (TRUE);
	return (FALSE);
}

char		*check_bin(char **paths, t_in *input)
{
	const char		*path;
	char			*slashed;
	char			**tab_tmp;
	char			*tmp;

	if (paths == NULL)
		return (NULL);
	tab_tmp = paths;
	path = input->cmd_name;
	while (*paths != NULL)
	{
		slashed = ft_strjoin(*paths, "/");
		if (is_valid_path((tmp = ft_strjoin(slashed, path))) == TRUE)
			return (tmp);
		free_str(&tmp);
		free_str(&slashed);
		paths++;
	}
	return (NULL);
}

int			exec_cmd(t_sh *sh_env, char **bin_path)
{
	int		ret;
	char	*path;

	path = NULL;
	sh_env->input.split_in = ft_arg_split(sh_env->input.user_in,
			&sh_env->input.input_lst);
	ft_format_tab_content(sh_env->input.split_in, &format_input);
	path = check_bin(bin_path, &sh_env->input);
	if (path == NULL)
		return (exit_error(USAGE, sh_env->input.cmd_name, "my_sh", -1));
	ret = execve(path, sh_env->input.split_in, sh_env->cmd_env.env_tab);
	return (ret);
}
