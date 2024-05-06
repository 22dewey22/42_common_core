/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:12:49 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/02/16 12:14:05 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	px_pipex_loop(t_prog *state)
{
	t_cmds	*current;
	int		last_exit_status;

	current = state->first_cmd;
	while (current)
	{
		if (pipex_magic(state, current) != EXIT_SUCCESS)
			return (px_kill_switch(state, EXIT_FAILURE));
		current = current->next;
	}
	while (state->ac - 3 > 0)
	{
		if (waitpid(-1, &last_exit_status, 0) == state->last_pid)
			state->error = WEXITSTATUS(last_exit_status);
		state->ac--;
	}
	return (EXIT_SUCCESS);
}

int	pipex_magic(t_prog *state, t_cmds *cmd)
{
	int	pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		return (PIPE_ERROR);
	state->last_pid = fork();
	if (state->last_pid == -1)
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		return (FORK_ERROR);
	}
	if (state->last_pid == 0)
		px_child(state, cmd, pipe_fd);
	else
		px_parent(cmd, pipe_fd);
	return (EXIT_SUCCESS);
}

void	px_parent(t_cmds *cmd, int *pipe_fd)
{
	close(pipe_fd[1]);
	if (cmd->next)
		dup2(pipe_fd[0], STDIN_FILENO);
	else
	{
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
	}
	close(pipe_fd[0]);
}

void	px_child(t_prog *state, t_cmds *cmd, int *pipe_fd)
{
	close(pipe_fd[0]);
	if (cmd->next)
		dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[1]);
	if (cmd == state->first_cmd && state->infile_fd < 0)
		exit(px_kill_switch(state, 1));
	if (cmd->next == NULL && state->outfile_fd < 0)
		exit(px_kill_switch(state, 1));
	px_execute_cmd(state, cmd);
}
