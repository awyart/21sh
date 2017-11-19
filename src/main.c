/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:46:12 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/17 15:54:36 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh42.h"

char				*ft_getenv(char *key)
{
	return (getenv(key));
}

/*
**	NOT MEANT TO STAY
*/
void				print_chars(t_dlist *list)
{
	if (list != NULL)
		write(1, "\n", 1);
	while (list != NULL)
	{
		write(1, (char *)(list->content), 1);
		list = list->next;
	}
}

int					main(int ac, char **av)
{
	t_terms			*terms;
	t_reader		*result;
	char			*name;

	if ((terms = (t_terms *)ft_memalloc(sizeof(t_terms))) == NULL)
		return (0);
	ft_terms_init(terms);
	ft_terms_toggle(terms, 1);
	name = ft_getenv("TERM");
	if (tgetent(STDIN_FILENO, name) == ERR)
		return (0);
	while (1)
	{
		ft_putstr(PS1);
		if ((result = ft_read())->status == 0)
			print_chars((t_dlist *)(result->content));
		write(1, "\n", 1);
	}
	(void)ac;
	(void)av;
	return (0);
}
