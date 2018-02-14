#include "header.h"

int 	reset_cursor(t_dlist_wrap *wrap, t_sh *sh)
{
	int offset;
	int i;
	int col;

	offset = wrap->size - wrap->pos + 1;
	i = wrap->size + len_prompt(sh);
	col = sh->term.win.ws_col;
	if ((wrap->size + len_prompt(sh)) % col == 0)
	{
		ft_terms_toggle_key("cr");
		ft_terms_toggle_key("do");
	}
	g_i1 = offset;
	g_i2 = i;
	while (--offset)
	{
		if (offset <= 0)
			break;
		col = sh->term.win.ws_col;
		if (i % sh->term.win.ws_col == 0)
		{
			ft_terms_toggle_key("cr");
			ft_terms_toggle_key("up");
			while (--col)
				ft_terms_toggle_key("nd");
		}
		else
			ft_terms_toggle_key("le");
		i--;
	}	return (wrap->size - wrap->pos);
}

int				ft_print_list(t_dlist_wrap *wrap, t_sh *sh)
{
	t_chr	*schar;
	t_dlist	*list;

	ft_prompt(sh);
	list = wrap->head;
	while (list != NULL)
	{
		schar = list->content;
		write(STDOUT_FILENO, &schar->c, 1);
		list = list->next;
	}
	return (0);
}

int 	refresh_line(t_dlist_wrap *wrap, t_sh *sh)
{
	int i;
	int col;
	static int pos = 0;

	//dprintf(g_fd, "\33[H\33[2JLIST \n");
	col = wrap->col;
	if (col < 10)
	{
		dprintf(g_fd, "fenetre trop petite\n");
		exit(0);
	}
	i = (pos + len_prompt(sh)) / (col) + 1; // ajout  a la fin ok et mouvement gauche droite
	dprintf(g_fd, "i <%d> col <%d> pos <%d>", i, col, pos);
	while (--i)
  	{
		if (i <= 0)
			break ;
		ft_terms_toggle_key("cr");
		ft_terms_toggle_key("cd");
		ft_terms_toggle_key("al");
		ft_terms_toggle_key("up");
	}
	ft_terms_toggle_key("cr");
	ft_terms_toggle_key("cd");
	ft_terms_toggle_key("al");
	ft_print_list(wrap, sh);
	pos = wrap->pos;
	return (1);
}