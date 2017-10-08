#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include <signal.h>
# include <ncurses.h>
# include "define.h"
# include "struct.h"
# include "proto.h"

int				g_errno;
int				g_cmd_ret;

int				g_fd_ou;
int				g_fd_in;
int				g_fd_err;

const t_shcmd	g_sh_struct[PRC_NB + 1];
const t_sherror	g_sh_error[NB_ERR + 1];
const t_schar	g_spec_char[SCHAR_NB];
const t_sighand	g_sig_msg[NB_SIG + 1];

#endif
