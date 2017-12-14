#include "../inc/levenshtein.h"

void		add_to_history(char *str, int *fd)
{
	if ((*fd = open(HISTORY, O_RDWR | O_APPEND | O_CREAT)) < 0)
		exit(ft_printf("[open] Bad file descriptor\n"));
	ft_dprintf(*fd, "%s\n", str);
	close(*fd);
}

t_dlist		*history_to_tree(int fd)
{
	t_dlist		*new;
	t_dlist		*history;
	char		*str;
	int			ret;

	str = NULL;
	new = NULL;
	history = NULL;
	if ((fd = open(HISTORY, O_RDONLY | O_CREAT)) < 0)
		exit(printf("bad fd\n"));
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		new = str_to_dlist(str);
		//add_to_child should directly take a string as 'word'//
		add_to_child(&history, new);
		//----------------------------------------------------//
		free_str(&str);
	}
	close(fd);
	return (history);
}
