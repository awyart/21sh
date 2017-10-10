#include "minishell.h"
#include "parser.h"

t_token	**ft_get_token(char *cmd)
{
	t_token	**token;
	int 	nbtoken;
	
	nbtoken = ft_counttoken(cmd);
	if (nbtoken != 0)
	{
		token = (t_token **)ft_memalloc(sizeof(t_token *) * (nbtoken + 1));
		ft_stringtotoken(cmd, token);
		return (token);
	}
	return (NULL);
}

void	ft_start(char *line, t_sh *sh_env, char **cur_dir)
{
	t_token **token;
	int		nbtoken;
	int 	tk;

	nbtoken = ft_counttoken(line);
	tk = 0;
	if (nbtoken == 0)
		ft_exec_cmd(line, sh_env, cur_dir);
	else
	{
		token = ft_get_token(line);
		ft_print_token(token, nbtoken);
		while (tk < nbtoken)
		{
			token[tk]->cmd(line, sh_env, cur_dir, token[tk]);
			tk++;
		}
		ft_exec_cmd(line + token[tk - 1]->pos->end + 1, sh_env, cur_dir);
	}
	//freez
}
