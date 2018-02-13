#include "header.h"

// int init_cap_del(char b, char c, int i , int (*f)(t_sh *, char **))
// {

// }

int init_cap_esc(char b, char c, int i, int (*f)(t_dlist_wrap *))
{
	if (f == NULL)
		return (0);
	g_handleinput[i].cap[0] = 27;
	g_handleinput[i].cap[1] = b;
	g_handleinput[i].cap[2] = c;
	g_handleinput[i].f = f;
	return (1);
}


int 	init_cap(void)
{
	int i;

	i = -1;
	while (++i < CAP_SIZE)
	{
		g_handleinput[i].f = NULL;
		g_handleinput[i].cap[0] = 0;
		g_handleinput[i].cap[1] = 0;
		g_handleinput[i].cap[2] = 0;
	}
	// init_cap_esc(91, 65, K_UP, &move_updown);
	// init_cap_esc(91, 66, K_DOWN, &move_updown);
	init_cap_esc(91, 67, K_RIGHT, &move_right);
	init_cap_esc(91, 68, K_LEFT, &move_left);
	// init_cap_esc(K_END);
	// init_cap_esc(K_PUP);
	// init_cap_esc(K_PDOWN);
	// init_cap_esc(K_DEL);
	// init_cap_esc(K_DELR);
	// init_cap_esc(K_CUT);
	// init_cap_esc(K_YANK);
// 	//g_handleinput[K_UP].f = &move_updown;
// 	//g_handleinput[K_DOWN].f = &move_updown;
// 	g_handleinput[K_LEFT].f = &move_left;
// 	//g_handleinput[K_END].f = &move_end;
// 	//g_handleinput[K_HOME].f = &move_begin;
// 	//g_handleinput[K_PUP].f = &move_up_ctrl;
// 	//g_handleinput[K_PDOWN].f = &move_down_ctrl;
// 	g_handleinput[K_DEL].f = &handle_del;
// 	g_handleinput[K_DELR].f = &handle_del_right;
// //	g_handleinput[K_CUT].f = &cut_list;
	//g_handleinput[K_YANK].f = &paste_list;
	return (0);
}


int			get_func(char buf[3])
{
	int i;
	int k;

	i = -1;
	k = 2;
	if (is_printable(buf))
		return (-1);
	while (++i < CAP_SIZE)
	{
		if (ft_strncmp(buf, g_handleinput[i].cap, 3) == 0)
			return (i);
	}
	return (-2);
}

int			ft_read(t_sh *sh)
{
	char			buf[3];
	int				(*ptr)() = NULL;
	int 			ret = 0;
	t_dlist_wrap	wrap;

	ft_bzero(&wrap, sizeof(t_dlist_wrap));
	init_cap();
	while (1)
	{
		ft_bzero(buf, 3);
		read(STDIN_FILENO, buf,  3);
		if (is_break(buf))
		{
			refresh_line(&wrap, sh);
			break ;
		}
		ret = get_func(buf);
		dprintf(g_fd, "<%d>\n", ret);
		if (ret >= 0)
		{
			ptr = g_handleinput[ret].f;
			ret = ptr(&wrap, sh);
		}
		else if (ret == -1)
		 	handle_char(buf, &wrap);
		refresh_line(&wrap, sh);
		ft_printlist(&wrap, sh, buf);
	}
	sh->list = wrap.head;
	return (1);
}