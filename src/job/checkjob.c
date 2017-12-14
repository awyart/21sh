/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkjob.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 21:17:19 by awyart            #+#    #+#             */
/*   Updated: 2017/12/13 18:52:06 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/* Find the active job with the indicated pgid.  */
t_job	*find_job (t_sh *sh, pid_t pgid)
{
	t_job *job;

	job = sh->job;
	while (job != NULL)
	{
		if (job->pgid == pgid)
			return (job);
		job = job->next;
	}
	return (NULL);
}

/* Return true if all processes in the job have stopped or completed.  */
int 	*job_is_stopped (t_job *job)
{
	t_process *process;

	process = job->first_process;
	while (process != NULL)
	{
		if (!process->completed && !process->stopped)
			return (0);
		process = process->next;
	}
	return (1);
}

/* Return true if all processes in the job have completed.  */
int job_is_completed (t_job *job)
{
	t_process *process;

	process = job->first_process;
	while (process != NULL)
	{
		if (!(process->completed))
			return (0);
		process = process->next;
	}
	return (1);
}

void put_job_in_foreground (t_sh *sh, t_job *j, int cont)
{
	/* Put the job into the foreground.  */
	tcsetpgrp (sh->term.this_term, j->pgid);

	/* Send the job a continue signal, if necessary.  */
	if (cont)
	{
		tcsetattr (sh->term.this_term, TCSADRAIN, &j->tmodes);
		if (kill (- j->pgid, SIGCONT) < 0)
			perror ("kill (SIGCONT)");
	}

	/* Wait for it to report.  */
	wait_for_job (j);

	/* Put the shell back in the foreground.  */
	tcsetpgrp (sh->term.this_term, shell_pgid);

	/* Restore the shell’s terminal modes.  */
	tcgetattr (sh->term.this_term, &j->tmodes);
	tcsetattr (sh->term.this_term, TCSADRAIN, &shell_tmodes);
}
