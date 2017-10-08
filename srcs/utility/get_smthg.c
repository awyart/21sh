#include "minishell.h"

char		**get_env_path(char **env)
{
	char		*path;
	char		**tab;

	tab = NULL;
	path = NULL;
	while (*env && (ft_strncmp(*env, "PATH", 4) != 0) != 0)
		env++;
	if (*env != NULL)
		path = *env + 5;
	if (path != NULL)
		tab = ft_strsplit(path, ':');
	return (tab);
}

char		*get_cur_dir(char *cur_dir_buff)
{
	char		*tmp;
	int			len;

	tmp = getcwd(cur_dir_buff, PATH_MAX + 1);
	len = ft_strlen(tmp);
	while (len > 0 && tmp[len] != '/')
		len--;
	if (tmp[len] == '/' && ft_strcmp(tmp, "/") != 0)
		len++;
	tmp = &tmp[len];
	return (tmp);
}
