#include "minishell.h"

void		del_list(void *content, size_t size)
{
	content = (void*)content;
	size = (size_t)size;
}
void		print_lst(t_list *node)
{
	ft_dprintf(g_fd_ou, "%s\n", node->content);
}
