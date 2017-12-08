/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 19:10:42 by awyart            #+#    #+#             */
/*   Updated: 2017/12/05 19:23:36 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int 	ft_lexer(t_sh *sh)
{
	t_dlist	*line;
	t_token	*token;
	t_token *new;

	line = sh->reader->content;
	ft_print_input(&line);
	while (line == NULL)
	{
		if ((new = ft_create_token(line)) == NULL)
			return (0);
		ft_get_token(token);
		ft_add_token(new, &token);
		line = new->last_letter->next;
	}
	return (0);
}