#include "minishell.h"
#include "parser.h"

const t_token	 g_tok[] = 
{
	{";", NEWFEED, 0, &ft_newfeed},
	{"<", RED_IN, 0, 0},
	{">", RED_OUT, 0, 0},
	{">>", RED_END_IN, 0, 0},
	{">&", RED_FD, 0, 0},
	{"|", PIPE, 0, 0},
	{"\"", Q_UOTE, 0, 0},
	{"\"", QUOTE, 0, 0},
	{"\\", SLASH, 0, 0},
	{"#", IGNORE, 0, 0},
	{"0>", RED_INOUT, 0, 0},
	{"1>", RED_OOUT, 0, 0},
	{"2>", RED_ERROUT, 0, 0},
};

int 	ft_is_token(char *str)
{
	if (*str == ';' || *str == '<' || *str == '|' || *str == '\"' || *str == '\\')
		return (1);
	if (*str == '>' && str[1] != '>' && str[1] != '&')
		return (1);
	if (*str == '>')
		return (2);
	return (0);
}

int		ft_counttoken(char *cmd)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (cmd[++i] != '\0')
	{
		if (ft_is_token(&cmd[i]))
			count++;
	}
	return (count);
}

void	ft_print_token(t_token **token, int nbtoken)
{
	int tk = 0;
	if (token)
	{
		while (tk < nbtoken)
		{
			ft_printf("<%s>:", token[tk]->str);
			ft_printf("<%i:%d>\n", token[tk]->pos->end, token[tk]->pos->begin);
			tk++;
		}
	}
}

void 	ft_fill_pos(t_token *token, int pos, int prepos)
{
	int i;

	token->pos->end = pos;
	i = -1;
	while (++i < NB_TOK)
	{
		if (ft_strcmp(token->str, g_tok[i].str) == 0)
			token->cmd = g_tok[i].cmd;
	}
	token->pos->begin = prepos;
	token->pos->rel_pos = token->pos->end - token->pos->begin;
}
void	ft_stringtotoken(char *str, t_token **token)
{
	int		nb;
	int		pos;
	int		tk;

	pos = 0;
	tk = 0;
	while (str[pos] != '\0')
	{
		
		nb = ft_is_token(&str[pos]);
		if (nb != 0)
		{
			token[tk] = (t_token *)ft_memalloc(sizeof(t_token) + 1);					
			ft_strncpy(token[tk]->str, &(str[pos]), nb);
			token[tk]->pos = ft_memalloc(sizeof(t_pos));
			ft_fill_pos(token[tk], pos, (tk == 0 ? 0 : token[tk - 1]->pos->end + 1));
			tk++;
		}
		(nb == 0 ? (pos += 1) : (pos = pos + nb));
	}
}