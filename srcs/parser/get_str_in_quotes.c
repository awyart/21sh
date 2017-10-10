#include "minishell.h"

t_bool		is_esc_c(char *str, char *esc)
{
	if (ft_strncmp(str, esc, 2) == 0)
		return (TRUE);
	return (FALSE);
}

char		*get_str_in_quotes(char *str, int *pos)
{
	char	*content;
	int		i;

	i = 0;
	if (str[i] != '"')
	{
		while (str[i] && (!(ft_isspace(str[i])) && str[i] != '"'))
			i++;
		*pos = i;
		return (ft_strndup(str, i));
	}
	i = 0;
	while (str[i])
	{
		if (is_esc_c(&str[i], "\\\"") == TRUE)
			i++;
		else if (str[i] == '"')
			break ;
		i++;
	}
	content = ft_strsub(str, 0, i);
	*pos = i + 2;
	return (content);
}
