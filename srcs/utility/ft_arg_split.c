#include "minishell.h"

void		add_arg(char **str, t_list **list)
{
	char		*tmp;
	char		*sub;
	int			i;

	i = 0;
	tmp = *str;
	sub = NULL;
	sub = get_str_in_quotes(*str, &i);
	*str = tmp + i;
	ft_lstback(list, sub, ft_strlen(sub) + 1);
	free(sub);
}

int			ft_lst_size(t_list *list)
{
	t_list		*ptr;
	int			size;

	size = 0;
	ptr = list;
	while (ptr)
	{
		size++;
		ptr = ptr->next;
	}
	return (size);
}

char		**ft_list_to_tab(t_list **list)
{
	char	**tab;
	t_list	*tmp;
	int		lst_size;
	int		i;

	i = 0;
	tmp = *list;
	lst_size = ft_lst_size(tmp);
	tab = ft_memalloc(sizeof(char *) * (lst_size + 1));
	while (tmp)
	{
		tab[i++] = tmp->content;
		tmp = tmp->next;
	}
	tab[i] = NULL;
	return (tab);
}

char		**ft_arg_split(char *str, t_list **list)
{
	char	**split_input;

	split_input = NULL;
	while (*str)
	{
		while (*str == ' ')
			str++;
		if (*str != '\0')
			add_arg(&str, list);
	}
	split_input = ft_list_to_tab(list);
	return (split_input);
}
