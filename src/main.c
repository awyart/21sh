/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:46:12 by vbastion          #+#    #+#             */
/*   Updated: 2017/12/14 19:58:35 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_exit(int c)
{
	exit(c);
}

static void	ft_start_process(t_sh *sh)
{
	while (1)
	{
		sh->curr_line = ft_get_currline();
		ft_prompt(sh->ret);
		ft_read(sh);
		write(STDOUT_FILENO, "\n", 1);
		ft_lexer(sh);
		dprintf(g_fd, "\n --<Lexer OK>---\n ");
		ft_parser(sh);
		dprintf(g_fd, "\n --<Parser ok>---\n ");
		//ft_extension();
		ft_execution(sh);

		//free d truks
	}
}

static int	ft_init(t_sh *sh)
{
	ft_init_term();
	ft_terms_init(&sh->term);
	ft_terms_toggle(&sh->term, 1);
	ft_setupenv(&sh->env);
	return (1);
}

int			main(void)
{
	t_sh				sh;
	static t_hist		hist;

	sh.hist = &hist;
	g_fd = open("/dev/ttys001", O_WRONLY);
	sh.ret = Q_OK;
	setlocale(LC_ALL, "");
	if (!(ft_init(&sh)))
		return (0);
	ft_getsignal();
	tputs(tgetstr("cl", NULL), 1, &ft_putc);
	ft_start_process(&sh);
	//free(&sh);
	return (0);
}
