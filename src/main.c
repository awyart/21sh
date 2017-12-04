/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:46:12 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/30 18:06:12 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void ft_start_process(t_sh *sh)
{
	while (1)
	{
		sh->curr_line = ft_get_currline();
		ft_prompt();
		ft_read(sh);
		//ft_lexer();
		//ft_parser();
		//ft_extension();
		//ft_execution();
		write(STDOUT_FILENO, "\n", 1);
		if (1)
			break ;
	}
}


static int	ft_init(t_sh *sh)
{
	if ((sh->term = (t_terms *)ft_memalloc(sizeof(t_terms))) == NULL)
		return (0);
	ft_init_term();
	ft_terms_init(sh->term);
	ft_terms_toggle(sh->term, 1);
	if ((sh->env = (t_environ *)ft_memalloc(sizeof(t_environ))) == NULL)
		return (0);
	ft_setupenv(sh->env);
	return (1);
}

int		main(void)
{
	t_sh	*sh;

	
	g_fd = open("/dev/ttys001", O_WRONLY);
 	if ((sh = (t_sh *)ft_memalloc(sizeof(t_sh))) == NULL)
		return (0);
	setlocale(LC_ALL, "");
	if (!(ft_init(sh)))
		return (0);
	//ft_getsignal();
	tputs(tgetstr("cl", NULL), 1, &ft_putc);
	ft_start_process(sh);
	//free(&sh);
	return (0);
}
