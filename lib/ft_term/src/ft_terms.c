/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terms.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:06:03 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/15 16:09:30 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"

int					ft_terms_init(t_terms *terms)
{
	if (tcgetattr(0, &terms->old) == -1)
		return (-1);
	ft_memcpy((void *)&terms->curr, (const void *)&terms->old, sizeof(t_term));
	terms->curr.c_lflag &= ~(ICANON);
	terms->curr.c_lflag &= ~(ECHO);
	terms->curr.c_cc[VMIN] = 1;
	terms->curr.c_cc[VTIME] = 0;
	terms->status = TERM_READY;
	return (1);
}

int						ft_terms_toggle(t_terms *terms, int on)
{
	if (tcsetattr(0, TCSADRAIN, on ? &terms->curr : &terms->old) == -1)
		return (-1);
	return (1);
}

void					ft_terms_clear(t_terms **terms)
{
	free(*terms);
	*terms = NULL;
}

int						ft_putc(int c)
{
	write(0, &c, 1);
	return (0);
}

int						ft_terms_toggle_key(char *str)
{
	char				*tmp;

	if ((tmp = tgetstr(str, NULL)) == NULL)
		return (0);
	tputs(tmp, 1, &ft_putc);
	return (1);
}
