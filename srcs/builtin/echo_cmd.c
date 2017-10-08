#include "minishell.h"

int			echo_cmd(t_sh *sh_env, char **bin_path)
{
	int		i;

	i = 0;
	sh_env->input.split_in = ft_arg_split(&sh_env->input.user_in[5],
			&sh_env->input.input_lst);
	ft_format_tab_content(sh_env->input.split_in, &format_input);
	while (sh_env->input.split_in[i] != NULL)
	{
		ft_dprintf(g_fd_ou, "%s", sh_env->input.split_in[i++]);
		if (sh_env->input.split_in[i])
			ft_dprintf(g_fd_ou, " ");
	}
	if (g_fd_ou == STDO)
		ft_putstr_fd("\n", g_fd_ou);
	free_tab_str(&sh_env->input.split_in);

	(void)bin_path;
	
	return (0);
}
