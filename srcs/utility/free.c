#include "minishell.h"

void		free_str(char **to_free)
{
	if (to_free != NULL)
	{
		free(*to_free);
		*to_free = NULL;
	}
}

void		free_tab_str(char ***tab)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = *tab;
	if (tmp == NULL)
		return ;
	while (tmp[i])
	{
		free_str(&tmp[i]);
		tmp[i++] = NULL;
	}
	free(*tab);
	*tab = NULL;
}

void			flush_sh_env(t_sh *env)
{
	free_tab_str(&env->input.split_in);
	free_str(&env->input.user_in);
	free_tab_str(&env->cmd_env.bin_path);
	ft_lstdel(&env->input.input_lst, &del_list);
	g_errno = 0;
	g_cmd_ret = 0;
}
