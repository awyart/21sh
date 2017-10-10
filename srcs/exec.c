#include "minishell.h"

void			ft_exec_cmd(char *comd, t_sh *sh_env, char **cur_dir)
{
	int			(*cmd)();

	sh_env->input.user_in = ft_strdup(comd);
	get_cmd_name(sh_env->input.cmd_name, sh_env->input.user_in);
	sh_env->proc.proc_id = get_proc_index(sh_env->input.cmd_name, g_sh_struct);
	cmd = g_sh_struct[sh_env->proc.proc_id].fun_ptr;
	fork_process(sh_env->proc.proc_id, cmd, sh_env, sh_env->cmd_env.bin_path);
	*cur_dir = get_cur_dir(sh_env->cur_dir);
	free_tab_str(&sh_env->input.split_in);
	free_str(&sh_env->input.user_in);
	ft_lstdel(&sh_env->input.input_lst, &del_list);
	g_errno = 0;
	g_cmd_ret = 0;
}
