/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:11:02 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/02/16 10:16:29 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	px_execute_cmd(t_prog *state, t_cmds *cmd)
{
	if (cmd->bin[0] == '/' || ft_strncmp(cmd->bin, "./", 2) == 0
		|| cmd->bin[0] == 0 || state->paths == NULL || cmd->bin == NULL)
		px_exec_abs_cmd(state, cmd);
	else
		return (px_exec_rel_cmd(state, cmd));
	return (EXIT_FAILURE);
}

void	px_exec_abs_cmd(t_prog *state, t_cmds *cmd)
{
	execve(cmd->bin, cmd->args, state->envp);
	px_error_msg(cmd->bin);
	state->error = 127;
	if (access(cmd->bin, F_OK) == 0)
		state->error = PERMISSION_DENIED;
	px_kill_switch(state, PATH_NOT_FOUND);
	exit(state->error);
}

int	px_exec_rel_cmd(t_prog *state, t_cmds *cmd)
{
	int		i;
	char	*temp;

	i = 0;
	while (state->paths[i])
	{
		temp = ft_pathjoin(state->paths[i], cmd->bin);
		if (temp == NULL)
			return (MALLOC_ERROR);
		if (access(temp, F_OK) == 0)
			execve(temp, cmd->args, state->envp);
		free(temp);
		i++;
	}
	execve(cmd->bin, cmd->args, state->envp);
	write(2, "pipex: ", 7);
	write(2, cmd->bin, ft_strlen(cmd->bin));
	write(2, ": Command not found\n", 20);
	px_kill_switch(state, PATH_NOT_FOUND);
	exit(127);
	return (EXIT_FAILURE);
}
