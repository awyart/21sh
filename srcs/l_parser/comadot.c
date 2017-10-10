#include "minishell.h"
#include "parser.h"

void 	ft_newfeed(char *line, t_sh *sh_env, char **cur_dir, t_token *token)
{
	line[token->pos->end] = '\0';
	ft_exec_cmd(line + token->pos->begin, sh_env, cur_dir);
	line[token->pos->end] = ';';
}