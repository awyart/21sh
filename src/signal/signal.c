/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:03:12 by awyart            #+#    #+#             */
/*   Updated: 2017/11/28 17:15:53 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_signal(int sig)
{
	if (sig == SIGINT)
		ft_dprintf(STDERR_FILENO, "Ctrl + C");
	else if (sig == SIGABRT)
		ft_dprintf(STDERR_FILENO, "Abort\n");
	else if (sig == SIGSEGV)
		ft_dprintf(STDERR_FILENO, "AHAHAHA c'est un segfault\n");
	else if (sig == SIGBUS)
		ft_dprintf(STDERR_FILENO, "BUS ERROR\n");
	else if (sig == SIGFPE)
		ft_dprintf(STDERR_FILENO, "Floating point exception\n");
	else
		ft_dprintf(STDERR_FILENO, "ERREUR non identifiée par awsh <%d>\n", sig);
}

void	ft_getsignal(void)
{
	signal(SIGWINCH, &ft_signal);
	signal(SIGABRT, &ft_signal);
	signal(SIGINT, &ft_signal);
	signal(SIGCONT, &ft_signal);
	signal(SIGBUS, &ft_signal);
	signal(SIGCONT, &ft_signal);
	signal(SIGTSTP, &ft_signal);
	signal(SIGKILL, &ft_signal);
	signal(SIGSTOP, &ft_signal);
	signal(SIGQUIT, &ft_signal);
}
