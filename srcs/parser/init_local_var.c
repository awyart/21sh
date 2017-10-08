#include "minishell.h"

t_bool		is_var_type(void)
{
	int		i;

	i = 0;
	return (FALSE);
}

void		fill_var_struct(char *str, t_local *var)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	var->name = ft_strsub(str, 0, i);
	if (str[i] == '\0')
	{
		var->has_equ = FALSE;
		return ;
	}
	i++;
	var->val = ft_strdup(&str[i]);
	var->has_equ = TRUE;
}
