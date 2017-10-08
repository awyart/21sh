#include "minishell.h"

void		add_to_path(char *path, char *file_name)
{
	if (*path != 0)
		ft_strcat(path, "/");
	ft_strcat(path, file_name);
}

void		remove_from_path(char *path)
{
	int		stop;

	stop = ft_strlen(path);
	while (path[stop] != '/' && stop > 0)
		stop--;
	path[stop] = '\0';
}
