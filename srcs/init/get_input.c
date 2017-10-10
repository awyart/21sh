#include "minishell.h"

int		get_cmd_name(char *cmd_name, char *user_in)
{
	int	i;

	i = 0;
	while (user_in[i] != '\0' && (!(ft_isspace(user_in[i]))))
		i++;
	ft_strncpy(cmd_name, user_in, i);
	cmd_name[i] = '\0';
	return (i);
}

char	*get_input(int fd, char **gnl_leak)
{
	char	*line;

	line = NULL;
	get_next_line(fd, &line, gnl_leak);
	//cmd = ft_split_cmd(line);
	return (line);
}
