#include "minishell.h"

static t_bool	ft_check(int i, char *s)
{
	int count;
	int k;

	count = 0;
	k = -1;
	while (++k < i)
	{
		if (s[k] == '\"')
			count++;
	}
	if (count % 2 == 0)
		return (TRUE);
	return (FALSE);
}

static size_t	ft_words(char *s)
{
	int	i;
	int	pos;
	int	count;

	i = -1;
	pos = 0;
	count = 0;
	while (s[++i] != '\0')
	{
		if (s[i] == ';' && ft_check(i, s) == TRUE)
		{
			if (i - pos > 0)
				count++;
			pos = i + 1;
		}
	}
	if (i - pos > 0)
		count++;
	return (count);
}

static char		*ft_create_word(char *s, int end, int pos)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * (end - pos + 1))))
		return (NULL);
	while (i < end - pos)
	{
		str[i] = s[pos + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char  	**ft_trim(char **str)
{
	char 	**tmp;
	int		i;

	i = -1;
	if (!(tmp = (char **)malloc(sizeof(char *) * (ft_tab_size(str) + 1))))
	{
		ft_printf("erreur de malloc\n");
		exit(0);
	}
	while (str[++i])
		tmp[i] = ft_strtrim(str[i]);
	tmp[i] = NULL;
	free_tab_str(&str);
	return (tmp);
}

char			**ft_split_cmd(char *s)
{
	char	**str;
	char 	**tmp;
	int		words;
	int		i;
	int		pos;
	int		j;

	words = ft_words(s);
	i = -1;
	pos = 0;
	j = 0;
	if (!(str = (char**)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	while (s[++i] != '\0')
		if (s[i] == ';' && ft_check(i, s) == TRUE)
		{
			if (i - pos > 0)
				str[j++] = ft_create_word(s, i, pos);
			pos = i + 1;
		}
	if (i - pos > 0)
		str[j++] = ft_create_word(s, i, pos);
	str[j] = NULL;
	tmp = ft_trim(str);
	return (tmp);
}
