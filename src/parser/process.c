/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:24:25 by awyart            #+#    #+#             */
/*   Updated: 2017/12/14 18:17:10 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_add_process(t_process *new, t_process **list_proc)
{
	t_process *tmp;

	tmp = *list_proc;
	if (tmp == NULL)
		*list_proc = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

static int ft_count_av(t_token *token)
{
	int i;

	i = 0;
	while (token != NULL && token->e_type == WORD)
	{
		i++;
		token = token->next;
	}
	return (i);
};


t_process *ft_new_process(t_token *token)
{
	t_process	*process;
	char		**argv;
	int			i;

	if (!(process = ft_memalloc(sizeof(t_process))))
		return (NULL);
	if (!(argv = (char **)ft_memalloc(sizeof(char *) * (ft_count_av(token) + 1))))
		return (NULL);
	i = 0;
	while (token != NULL && token->e_type == WORD)
	{
		argv[i] = spe_strdup(token);
		i++;
		token = token->next;
	}	
	argv[i] = NULL;	
	process->argv = argv;
	process->next = NULL;
	return (process);
}