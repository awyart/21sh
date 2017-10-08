#include "minishell.h"

int			exit_error(int error, char *bad_input, char *cmd_name, int ret)
{
	g_errno = error;
	ft_dprintf(g_fd_err, "%s: %s : %s\n", cmd_name,
			g_sh_error[g_errno].err_str, bad_input);
	return (g_cmd_ret = ret);
}

char		*get_var_val(t_shenv *cmd_env, char *var)
{
	t_list		*tmp;
	char		*home;

	tmp = cmd_env->env_list;
	while (tmp)
	{
		if (is_env_var(tmp->content, var))
			break ;
		tmp = tmp->next;
	}
	if (tmp != NULL)
		home = tmp->content;
	return (&home[5]);
}
