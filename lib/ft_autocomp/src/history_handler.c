#include "../inc/autocompletion.h"

void		*g_hist_manip[IR_SIZE] = {&history_down, &history_up, 0, 0};

void		history_init(t_hist *hstruct)
{
	hstruct->history_root = history_to_tree(hstruct->history_fd);
}

t_dlist		*history_handler(int event, t_dlist *input, t_hist *hstruct)
{
	t_dlist				*(*search_hist)(t_dlist *, t_dlist *, t_dlist *);

	search_hist = g_hist_manip[event];
	hstruct->cur_branch = search_hist(input, hstruct->cur_branch,
			hstruct->history_root);
	return (hstruct->cur_branch);
}

/*
int			main(void)
{
	t_dlist			*word;
	t_dlist			*history;
	t_dlist			*branch;
	t_dlist			*output;
	t_dlist			*content;
	t_dlist			*cpy;
	static t_hist	hist;
	char			*line;
	int				history_fd;

	word = NULL;
	branch = NULL;
	history = NULL;
	line = NULL;
	output = NULL;
	history_fd = 0;
	if (!(line = read_input()))
		return (-1);
	word = input_to_dlist(line);
	//history = history_to_tree(history_fd);
	history_init(&hist);
	//add_to_history(line, &history_fd);
	//branch = get_branch(word, history);
	output = history_handler(IR_UP, word, &hist);
	hl_print_next(output->content, &print_hlst_content);
	output = history_handler(IR_UP, word, &hist);
	hl_print_next(output->content, &print_hlst_content);
	//tree_to_list(NULL, branch, &output);
	//while (output)
	//{
	//	output = output->next;
	//	printf("\n");
//	}
	return (0);
}
*/
