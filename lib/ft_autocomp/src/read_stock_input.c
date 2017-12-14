#include "../inc/levenshtein.h"

char		*read_input(void)
{
	char	*str;

	str = NULL;
	if (get_next_line(STDI, &str) < 0)
		return (NULL);
	return (str);
}

void		add_dlist_to_child(t_dlist **parent, t_dlist *child)
{
	t_lev	*new;

	new = NULL;
	if (*parent == NULL)
		*parent = child;
	else
	{
		new = (*parent)->content;
		//maybe some leaks HERE
		if (new->content == '\0')
			return ;
		if (new->child == NULL)
			new->child = child;
		else
			add_dlist_to_child(&new->child, child);
	}
}

t_dlist		*str_to_dlist(char *input)
{
	t_dlist		*word;
	t_dlist		*entire;
	int			i;

	i = 0;
	word = NULL;
	entire = NULL;
	while (input[i])
	{
		word = ft_hlstnew(new_lev_node_c(&input[i]));
		ft_hlstadd_back(&entire, word);
		i++;
	}
	word = ft_hlstnew(new_lev_node_c(""));
	ft_hlstadd_back(&entire, word);
	return (entire);
}

t_dlist		*input_to_dlist(char *input)
{
	t_dlist		*word;
	t_dlist		*entire;
	int			i;

	i = 0;
	word = NULL;
	entire = NULL;
	while (input[i])
	{
		word = ft_hlstnew(new_lev_node_c(&input[i]));
		ft_hlstadd_back(&entire, word);
		i++;
	}
	return (entire);
}
