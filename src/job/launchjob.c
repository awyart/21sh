/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launchjob.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 21:36:53 by awyart            #+#    #+#             */
/*   Updated: 2017/12/14 19:51:21 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void ft_launch_job(t_sh *sh)
{
	t_process	*process;
	int 		mypipe[2];
	int 		infile = STDIN_FILENO;
	int 		outfile = STDOUT_FILENO;
	int			errfile = STDERR_FILENO;

	process = sh->process;
	dprintf(g_fd, "\n\n\n la liste des process a exec sont \n\n\n");
	ft_print_parsoutput(&process);
	while (process != NULL)
	{
		if (process->next)
		{
			if (pipe (mypipe) < 0)
			{
				dprintf(errfile, "pipe");
				exit (1);
			}
			outfile = mypipe[1];
		}
		process->pid = fork();
		if (process->pid > 0)
		{
			if (infile != STDIN_FILENO)
			{
				dup2 (infile, STDIN_FILENO);
				close (infile);
			}
			if (outfile != STDOUT_FILENO)
			{
				dup2 (outfile, STDOUT_FILENO);
				close (outfile);
			}
			if (errfile != STDERR_FILENO)
			{
				dup2 (errfile, STDERR_FILENO);
				close (errfile);
			}
			if ((waitpid(process->ret, &(process->status), 0)) == -1)
				exit(0);
			if ((WIFSIGNALED(process->status)))
			{
				ft_dprintf(STDOUT_FILENO, "le process s'est terminé anormalement :\n");
				ft_signal(WTERMSIG(process->status));
			}
		}
		if (process->pid == 0)
		{
			process->ret = execve(process->argv[0], process->argv, sh->env.env);
			ft_dprintf(STDERR_FILENO, "exec failed\n");
			exit(process->ret);
		}
		if (infile != STDIN_FILENO)
			close (infile);
		if (outfile != STDOUT_FILENO)
			close (outfile);
		infile = mypipe[0];
		process = process->next;
	}
}
