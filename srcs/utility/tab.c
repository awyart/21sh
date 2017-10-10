#include "minishell.h"

char		**ft_tab_dup(char **tab)
{
	char	**dup;
	int		size;
	int		i;

	i = 0;
	size = ft_tab_size(tab);
	dup = ft_memalloc(sizeof(char *) * (size + 1));
	while (tab[i])
	{
		dup[i] = ft_strdup(tab[i]);
		i++;
	}
	dup[i] = 0;
	return (dup);
}

void		ft_print_tab(char **tab)
{
	while (*tab)
	{
		ft_printf("<%s>\n", *tab);
		tab++;
	}
}

char		**ft_format_tab_content(char **arg, void (*fmt)())
{
	char	**tab;

	tab = arg;
	while (*tab)
	{
		fmt(&*tab);
		tab++;
	}
	return (arg);
}

int			ft_tab_size(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
