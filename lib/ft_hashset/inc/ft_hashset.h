#ifndef FT_HASHSET_H
# define FT_HASHSET_H

# include "ft_string.h"
# include "ft_mem.h"

typedef struct s_hash_entry t_hash_entry;
typedef struct s_hash_dict	t_hash_dict;

struct						s_hash_entry
{
	char					*key;
	void					*content;
	t_hash_entry			*next;
};

struct						s_hash_dict
{
	size_t					size;
	int						prime;
	t_hash_entry			**entries;
};

t_hash_dict					*ft_hashset_create(size_t size, int prime);
t_hash_entry				*ft_hashset_add(t_hash_dict *dict, char *key,
											void *value);
t_hash_entry				*ft_hashset_lookup(t_hash_dict *dict, char *str);
u_int						ft_hashset_hash(t_hash_dict *dict, char *str);
void						ft_hashset_delete(t_hash_dict **dict);

#endif
