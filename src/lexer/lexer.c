/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 19:10:42 by awyart            #+#    #+#             */
/*   Updated: 2017/12/09 16:32:57 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int 	ft_lexer(t_sh *sh)
{
	t_dlist	*line;
	t_token	*token;
	t_token *new;

	token = NULL;
	line = sh->reader->content;
	ft_print_lexinput(&line);
	while (line != NULL)
	{
		while (line != NULL && ft_lisspace(line))
			line = line->next;
		if (line == NULL)
			break ;
		if ((new = ft_create_token(line)) == NULL)
			return (0) ;
		ft_get_token(new);
		ft_add_token(new, &token);
		if (new->last_letter)
			line = new->last_letter->next;
		else
			line = NULL;
	}
	ft_print_lexoutput(&token);
	return (0);
}