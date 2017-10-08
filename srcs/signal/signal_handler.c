#include "minishell.h"

void		sighandler(int sigval)
{
	if (sigval == SIGINT)
		ft_dprintf(g_fd_ou, "\b\b");
	if (sigval == SIGSEGV)
	{
		ft_dprintf(g_fd_ou, "\n/!\\ Segmentation fault, not funny\n");
		exit(1);
	}
}

void		sig_intercepter(void)
{
	signal(SIGINT, &sighandler);
	signal(SIGSEGV, &sighandler);
}
