#ifndef STRUCT_H
# define STRUCT_H

/*a boolean type is defined in libft/libft.h*/

typedef struct		s_2link
{
	void			*content;
	int				position;
	struct s_2link	*prev;
	struct s_2link	*next;
}					t_2link;

/*list of special escape sentences*/

typedef struct		s_schar
{
	char			sequ[3];
	char			asc;
}					t_schar;

/*STD file descriptors*/

typedef enum		e_fd
{
	STDI,
	STDO,
	STDE
}					t_fd;

/*index for the pointer funct tab*/

typedef enum		e_name
{
	ECHO,
	CD,
	SET,
	USET,
	ENV,
	EXT,
	EXP,
	PRC_NB
}					t_name;

/*signal handler*/

typedef enum		e_sig
{
	MYSIG_INT,
	NB_SIG
}					t_sig;

typedef struct		s_sighand
{
	char	err_str[100];
	int		sig_id;
}					t_sighand;

/*error id*/

typedef enum		e_errno
{
	USAGE,
	ERRDIR,
	PID,
	WRONG_TYPE,
	INVALID_CMD,
	SETENV_INVAL,
	CD_INVAL,
	EX_ARG,
	LES_ARG,
	NB_ERR
}					t_errno;

/*global struct for error msg management*/

typedef struct		s_sherror
{
	char			err_str[100];
	int				errno;
}					t_sherror;

/*user input struct*/

typedef struct		s_in
{
	char			*user_in;
	char			**split_in;
	t_list			*input_lst;
	t_list			*history; //when pressing the up key
	char			cmd_name[MAX_CMD_NAME];
}					t_in;

/*command struct*/

typedef struct		s_prc
{
	char			**prc_tab;
	void			*prc_funs[PRC_NB];
	int				proc_id;
}					t_prc;

/*global command struct*/

typedef struct		s_shcmd
{
	char			name[PRC_LEN];
	int				index;
	void			*fun_ptr;
}					t_shcmd;

/*local variables struct*/

typedef struct		s_local
{
	char			*name;
	char			*val;
	t_bool			has_equ;
}					t_local;

/*environ struct*/

typedef struct		s_shenv
{
	char			*cur_dir;
	char			**bin_path;
	t_list			*env_list;
	char			**env_tab;
}					t_shenv;

/*main struct*/

typedef struct		s_sh
{
	t_in			input;
	t_prc			proc;
	t_shenv			cmd_env;
	t_local			*lst_local;
	char			cur_dir[PATH_MAX + 1];
	char			prev_dir[PATH_MAX + 1];
	char 			*gnl_leak;
}					t_sh;

#endif
