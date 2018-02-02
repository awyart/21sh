/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narajaon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 11:12:02 by narajaon          #+#    #+#             */
/*   Updated: 2018/01/12 09:59:34 by narajaon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		free_str(char **to_free)
{
	if (to_free != NULL)
	{
		free(*to_free);
		*to_free = NULL;
	}
}