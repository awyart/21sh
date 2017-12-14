/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 18:53:45 by awyart            #+#    #+#             */
/*   Updated: 2017/12/14 18:50:13 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int ft_print_parsoutput(t_process **proc)
{
	t_process *tmp;
	int 	count;
	int 	i;

	count = 0;
	tmp  = *proc;
	while (tmp != NULL)
	{
		i = 0;
		dprintf(g_fd, " process %d : \n", count);
		while (tmp->argv[i] != NULL)
		{
			dprintf(g_fd, "<%s> ", tmp->argv[i]);
			i++;
		}
		count++;
		tmp = tmp->next;
	}
	return (count);
}

int	ft_parser(t_sh *sh)
{
	t_process 	*list_proc;
	t_token		*token;
	t_process	*process;

	ft_print_lexoutput(&(sh->token));
	token = sh->token;
	// faire un tableau de pointeur dsur fonctions
	while (1)
	{
		if (token == NULL)
			break ;
		else if (token->e_type == WORD)
		{
			process = ft_new_process(token);
			while (token != NULL && token->e_type == WORD)
				token = token->next;
			ft_add_process(process, &list_proc);
		}
		else
		{
			token = token->next;
		}
	}
	ft_print_parsoutput(&list_proc);
	sh->process = list_proc;
	return (1);
}
