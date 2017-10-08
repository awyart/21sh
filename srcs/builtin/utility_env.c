#include "minishell.h"

t_bool		is_valid_setenv_arg(char *str, int *pos)
{
	int		i;

	i = 0;
	while (str[i] == ' ')
		i++;
	while (str[i] && str[i] != ' ')
	{
		if (ft_isalnum(str[i]) == FALSE && str[i] != '_')
			return (FALSE);
		i++;
	}
	while (str[i] == ' ')
		i++;
	*pos = i;
	return (TRUE);
}

t_bool		setenv_has_args(char *str)
{
	while (*str == ' ')
		str++;
	if (*str == '\0')
		return (FALSE);
	return (TRUE);
}

int			exec_cmd_w_env(char **arg, char **bin_path,
		char **cmd_env, t_sh *sh_env)
{
	int		status;
	char	*path;

	status = 0;
	ft_format_tab_content(arg, &format_input);
	path = check_bin(bin_path, &sh_env->input);
	if (path == NULL)
		return (exit_error(USAGE, arg[2], "my_sh", -1));
	status = execve(path, &arg[1], cmd_env);
	return (status);
}

char		**exec_env_u_op(char **arg, char ***env_tmp,
		t_sh *env, t_list **lst_env_tmp)
{
	*env_tmp = ft_tab_dup(env->cmd_env.env_tab);
	*lst_env_tmp = ft_tab_to_list(*env_tmp);
	remove_var_from_env(arg[2], lst_env_tmp);
	free(*env_tmp);
	*env_tmp = ft_list_to_tab(lst_env_tmp);
	free(*lst_env_tmp);
	arg++;
	return (arg);
}

void		apply_env_opt(char **arg, char **bin_path, t_sh *env)
{
	int		pid;
	int		status;
	char	**env_tmp;
	t_list	*lst_env_tmp;

	pid = fork();
	if (ft_strcmp(arg[1], "-i") == 0 && arg[2] != NULL)
		env_tmp = NULL;
	else if (ft_strcmp(arg[1], "-u") == 0 && arg[2] != NULL)
		arg = exec_env_u_op(arg, &env_tmp, env, &lst_env_tmp);
	if (pid == 0)
	{
		status = exec_cmd_w_env(arg, bin_path, env_tmp, env);
		if (env_tmp != NULL)
			free_tab_str(&env_tmp);
		exit(status);
	}
	if ((waitpid(pid, &status, 0) < 0))
		exit_error(PID, 0, "my_sh", -1);
}
