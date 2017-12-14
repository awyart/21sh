#ifndef LEVENSHTEIN_H
# define LEVENSHTEIN_H

# include	"../../ft_printf/inc/ft_printf.h"
# include	"../../libft/inc/libft.h"
# include	"../../ft_dlist/inc/ft_dlist.h"
# include	"macros.h"
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <termcap.h>
# include <termios.h>

# define	CMD_SIZE 10

typedef enum			e_ir
{
	IR_DOWN,
	IR_UP,
	IR_RESET,
	IR_CLEAR,
	IR_SIZE
}						t_ir;

typedef struct			s_hist
{
	t_dlist				*cur_branch;
	t_dlist				*history_root;
	int					history_fd;
}						t_hist;

typedef struct			s_lev
{
	char				content;
	t_dlist				*child;
}						t_lev;

void					*g_hist_manip[IR_SIZE];

void					free_str(char **str);
t_dlist					*history_up(t_dlist *word, t_dlist *cur_branch,
		t_dlist *history);
t_dlist					*history_down(t_dlist *word, t_dlist *cur_branch,
		t_dlist *history);
t_dlist					*get_branch(t_dlist *input, t_dlist *data_base);
t_dlist					*get_next_child(t_dlist *input, t_dlist *data_base);

t_lev					*new_lev_node(t_dlist *c);
t_lev					*new_lev_node_c(char *c);
t_dlist					*ft_hlstnew(t_lev *nu);
t_dlist					*ft_hlstnew_void(void *nu);
t_dlist					*new_hlist_dlist(t_dlist *list);

t_dlist					*add_to_tree_end(t_dlist **tree, t_lev *nu);
void					add_to_child(t_dlist **child, t_dlist *word);
void					add_dlist_to_child(t_dlist **parent, t_dlist *child);
void					add_branch_to_input(t_dlist **input, t_dlist *branch);
void					check_child_list(t_dlist **child, t_dlist *word);
void					list_to_lev_tree(t_dlist **tree_nodes,
		t_dlist *data_base);

void					print_child(t_dlist *child);
void					print_history(t_dlist *input, t_dlist *branch);
void					print_hlst_content(t_dlist *list);
void					print_branch(t_dlist *branch);

void					hlst_free(t_dlist **list);

t_dlist					*hlget_last(t_dlist *list);
t_dlist					*hl_node_dup(t_dlist *node, size_t size);
t_dlist					*hlist_cpy_minus(t_dlist *tree);
void					ft_hlstadd(t_dlist **alst, t_dlist *nu);
void					ft_hlstadd_void(t_dlist **alst, void *nu);
void					ft_hlstadd_back(t_dlist **alst, t_dlist *nu);
void					ft_hlstadd_back_void(t_dlist **alst, void *nu);
void					hl_print_next(t_dlist *list, void (*print)());

char					*read_input(void);
void					add_to_history(char *str, int *fd);
t_dlist					*history_to_tree(int fd);
t_dlist					*str_to_dlist(char *input);
void					tree_to_list(t_dlist *prev, t_dlist *cur,
		t_dlist **list);
t_dlist					*input_to_dlist(char *input);
#endif
