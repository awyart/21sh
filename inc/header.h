/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:48:57 by vbastion          #+#    #+#             */
/*   Updated: 2017/11/24 03:35:44 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include "libft.h"
#include "ft_printf.h"
#include "term_h"

typedef struct		s_sh
{
	t_env			env;
	t_term			term;
}					t_sh;


#endif
