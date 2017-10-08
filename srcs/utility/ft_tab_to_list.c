#include "minishell.h"

t_list			*ft_tab_to_list(char **str)
{
	t_list		*env_list;

	env_list = NULL;
	while (*str)
	{
		ft_lstback(&env_list, *str, ft_strlen(*str) + 1);
		str++;
	}
	return (env_list);
}
