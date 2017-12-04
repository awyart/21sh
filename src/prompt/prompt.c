/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:51:28 by awyart            #+#    #+#             */
/*   Updated: 2017/11/29 20:20:25 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int ft_prompt(void)
{
	//afficher des trucs cools ici
	//tputs("$> ", 1 , &ft_putc);
	ft_dprintf(STDERR_FILENO, "$> ");
	return (1);
}

int len_prompt(void)
{
	return (3);
}