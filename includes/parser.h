#ifndef PARSER_H
# define PARSER_H
# define TOK_MAX 2

# define NEWFEED 0
# define RED_IN 1
# define RED_OUT 2
# define RED_END_IN 3
# define RED_FD 4
# define PIPE 5
# define Q_UOTE 6
# define QUOTE 7
# define SLASH 8
# define IGNORE 9
# define RED_INOUT 10 
# define RED_OOUT 11 
# define RED_ERROUT 12 
# define NB_TOK 13 

typedef struct		s_pos
{
	int				begin;
	int 			end;
	int 			rel_pos;
}					t_pos;

typedef struct		s_token
{
	char			str[TOK_MAX + 1];
	int 			id;
	t_pos			*pos;
	void			(*cmd)();
}					t_token;


void	ft_stringtotoken(char *str, t_token **token);
void	ft_print_token(t_token **token, int nbtoken);
int		ft_counttoken(char *cmd);
int 	ft_is_token(char *str);

void 	ft_newfeed(char *line, t_sh *sh_env, char **cur_dir, t_token *token);

#endif
