/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libenv.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 18:21:28 by narajaon          #+#    #+#             */
/*   Updated: 2017/11/24 03:44:54 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBENV_H
# define LIBENV_H

extern char **environ;

char 	*ft_getterm(char **env);
char	**envdup(void);

#endif
