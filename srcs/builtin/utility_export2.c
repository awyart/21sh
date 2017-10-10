#include "minishell.h"

void			ft_lstpop(t_list **list, t_bool (*cmp)(), void *to_cmp)
{
	t_list		*tmp;

	tmp = *list;
	if (tmp != NULL)
	{
		if (cmp(tmp->content, to_cmp) == TRUE)
		{
			*list = tmp->next;
			free(tmp->content);
			free(tmp);
			tmp = NULL;
		}
		else
		{
			while (tmp->next && cmp(tmp->next->content, to_cmp) == FALSE)
				tmp = tmp->next;
			if (tmp != NULL)
			{
				free(tmp->next->content);
				free(tmp->next);
				tmp->next = tmp->next->next;
			}
		}
	}
}

void			remove_var_from_env(char *var, t_list **env)
{
	t_list		*tmp;

	tmp = *env;
	if (var == NULL)
		return ;
	while (tmp)
	{
		if (is_env_var(tmp->content, var))
		{
			ft_lstpop(env, &is_env_var, var);
			break ;
		}
		tmp = tmp->next;
	}
}

void			add_var_to_env(char **arg, t_list **env)
{
	t_list		*tmp;
	char		*join;
	char		*str_tmp;

	tmp = *env;
	join = ft_strjoin(arg[0], "=");
	str_tmp = join;
	if (arg[1] != NULL)
	{
		join = ft_strjoin(join, arg[1]);
		free_str(&str_tmp);
	}
	while (tmp)
	{
		if (is_env_var(tmp->content, arg[0]))
		{
			ft_lstpop(env, &is_env_var, join);
			break ;
		}
		tmp = tmp->next;
	}
	ft_lstback(env, join, ft_strlen(join) + 1);
	free_str(&join);
}
