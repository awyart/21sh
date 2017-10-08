#include "minishell.h"

t_bool			is_env_var(char *str, char *var)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (ft_strncmp(str, var, i) == 0)
		return (TRUE);
	return (FALSE);
}

t_bool			contains_esc_char(char *str)
{
	while (*str)
	{
		if (is_esc_char(str) >= 0)
			return (TRUE);
		str++;
	}
	return (FALSE);
}

char			**format_equal_args(char **arg, char *str, int i)
{
	char		*tmp_1;
	char		*tmp_2;

	arg = ft_memalloc(sizeof(char *) * 3);
	arg[0] = ft_strsub(str, 0, i);
	if (ft_strlen(&str[i + 1]) > 0)
		arg[1] = ft_strsub(&str[i + 1], 0, ft_strlen(&str[i + 1]));
	else
		arg[1] = ft_strdup("");
	arg[2] = 0;
	tmp_1 = arg[0];
	tmp_2 = arg[1];
	arg[0] = ft_strtrimc(arg[0], '"');
	arg[1] = ft_strtrimc(arg[1], '"');
	arg[2] = 0;
	free_str(&tmp_1);
	free_str(&tmp_2);
	return (arg);
}

t_bool			export_valid_arg(char *str, char ***arg)
{
	int			nb_equ;
	int			i;

	i = 0;
	nb_equ = 0;
	while (str[i] && str[i] != '=')
		i++;
	*arg = format_equal_args(*arg, str, i);
	if (contains_esc_char(**arg) == TRUE)
		return (FALSE);
	while (*str)
	{
		if (*str == '=')
			nb_equ++;
		if (nb_equ > 1 || ft_isprint(*str) == FALSE)
			return (FALSE);
		str++;
	}
	return (TRUE);
}

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
