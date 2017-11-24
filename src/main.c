/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:46:12 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/24 08:56:47 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"



static void ft_start_process(t_sh *sh)
{
	while (1)
	{
		ft_prompt();
		ft_input_reader();
		ft_lexer();
		ft_parser();
		ft_extension();
		ft_execution();
		if (QUIT)
			break ;
	}
}


static void	ft_init(t_sh *sh)
{
	ft_init_term();
	ft_setupenv();
	ft_init_conf();

}

int		main(void)
{
	t_sh sh;

	setlocale(LC_ALL, "");
	ft_init(&sh);
	ft_getsignal();
	ft_start_process(&sh);
	free(&sh);
	return (0);
}
