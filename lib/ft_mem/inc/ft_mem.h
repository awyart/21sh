/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbastion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 11:22:32 by vbastion          #+#    #+#             */
/*   Updated: 2017/08/15 16:34:56 by vbastion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEM_H
# define FT_MEM_H

# include <stdlib.h>
# include <sys/types.h>

typedef void	*(*t_err)();

/*
**	FUNCTIONS
*/

void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *str, size_t n);
int				ft_memcmp(void *lhs, void *rhs, size_t n);
void			ft_memdel(void **content);
void			*ft_memdup(void *src, size_t n);
void			*ft_memalloc(size_t size);
void			*ft_memalloc_err(size_t size, t_err err);
void			ft_bzero(void *mem, size_t len);

#endif
