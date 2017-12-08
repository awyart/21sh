/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 19:16:02 by awyart            #+#    #+#             */
/*   Updated: 2017/12/05 19:28:18 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_token 	*ft_create_token(t_dlist *line)
{
	t_token	*token;


	if ((token = (t_token *)malloc(sizeof(t_token))) == NULL)
		return (NULL);
	token->first_letter = line;
	token->last_letter = NULL;
	token->next = NULL;
	token->e_type = NEW;
	return (token);
}

int 	ft_get_token(t_token *token)
{
	if (is_char(token->first_letter))
		ft_handle_word(token);
	else if (is_)
}