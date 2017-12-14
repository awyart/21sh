/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 14:42:43 by awyart            #+#    #+#             */
/*   Updated: 2017/12/14 16:48:19 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_put_wrap_end(t_dlist_wrap *wrap, t_sh *sh)
{
	while (wrap->cursor != NULL)
	{
		move_right(wrap, sh);
	}
	wrap->tmp = wrap->last;
	return (1);
}

int		ft_quote(t_dlist_wrap *wrap, t_sh *sh)
{
	char c;

	if (sh->ret == Q_OK)
		return (sh->ret);
	ft_put_wrap_end(wrap, sh);
	ft_terms_toggle_key("do");
	ft_terms_toggle_key("cr");
	ft_prompt(sh->ret);
	while (1)
	{
		read(0, &c, 1);
		if (c == 4)
			break ;
		if (ft_no_printable(c))
		{
			if ((handle_non_char(c, wrap, sh)) == 0)
				break ;
		}
		else
			handle_char(c, wrap, sh);
		ft_printlist(wrap);
	}
	if ((sh->ret = ft_handle_quote(wrap->head)) != Q_OK)
		sh->ret = ft_quote(wrap, sh);
	return (sh->ret);
}

int		ft_handle_quote(t_dlist *list)
{
	char	c;
	char	last;
	t_chr	*schar;

	last = '.';
	while (list != NULL)
	{
		schar = list->content;
		c = schar->c;
		if (c == '\"' && last == '\"')
			last = '.';
		else if (c == '\'' && last == '\'')
			last = '.';
		else if (c == '\"' && last == '.')
			last = '\"';
		else if (c == '\'' && last == '.')
			last = '\'';
		list = list->next;
	}
	if (last == '\'')
		return (QUOTE);
	if (last == '\"')
		return (DQUOTE);
	if (c == '\\')
	{
		schar->c = '\n';
		return (SLASH);
	}
	return (Q_OK);
}
