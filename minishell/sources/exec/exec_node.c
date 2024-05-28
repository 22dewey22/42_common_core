/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:44:21 by cdutel            #+#    #+#             */
/*   Updated: 2024/05/28 12:15:48 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	waiting_loop(t_mini *mini)
{
	int	pid;
	int	status;

	status = 0;
	while (mini->pid_num)
	{
		pid = waitpid(-1, &status, 0);
		if (pid == mini->last_pid)
		{
			if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
				mini->exit_status = 130;
			else if (WIFSIGNALED(status) && WTERMSIG(status) == SIGQUIT)
			{
				err_printf("%s", "Quit (core dumped)\n", NULL, NULL);
				mini->exit_status = 131;
			}
			else if (WIFEXITED(status))
				mini->exit_status = WEXITSTATUS(status);
		}
		remove_proc_from_list(&mini->processes, pid);
		mini->pid_num--;
	}
	signal_ms();
}

int	exec_node(t_node *cur, t_mini *mini)
{
	int		loop_result;

	if (get_files(&mini->dir_list) != EXIT_SUCCESS)
		return (ft_printf_fd(2, "%s", ERR_MSG_GET_FILES), EXIT_FAILURE);
	if (expand_node(cur, mini, mini->dir_list, &mini->heredocs) != EXIT_SUCCESS)
		return (destroy_tab(&mini->dir_list), ft_printf_fd(2, "%s",
				ERR_MSG_EXPAND_NODES));
	if (is_builtin(cur->cmds->args) == 1 && cur->cmds->next == NULL)
		return (exec_builtin_parent(cur->cmds, mini, &mini->dir_list));
	mini->pid_num = 0;
	loop_result = exec_loop(cur, mini, mini->dir_list);
	waiting_loop(mini);
	if (loop_result == EXIT_FAILURE)
		return (destroy_tab(&mini->dir_list), EXIT_FAILURE);
	return (destroy_tab(&mini->dir_list), EXIT_SUCCESS);
}
