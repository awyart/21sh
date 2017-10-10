#include "minishell.h"

int			exit_cmd(t_sh *sh_env, char **bin_path)
{
	if (sh_env->gnl_leak)
		free_str(&(sh_env->gnl_leak));
	exit(1);
	(void)bin_path;
	return (0);
}
