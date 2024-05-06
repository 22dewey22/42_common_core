/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:16:58 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/02/16 12:25:23 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	px_init_prog(t_prog *state, int ac, char **av, char **envp)
{
	int	i;

	i = 0;
	state->ac = ac;
	state->av = av;
	state->envp = envp;
	state->paths = 0;
	state->here_doc = 0;
	while (i < 50)
		state->here_doc_name[i++] = 0;
	state->here_doc_fd = 0;
	state->infile = 0;
	state->infile_fd = 0;
	state->outfile = 0;
	state->outfile_fd = 0;
	state->limiter = 0;
	state->first_cmd = 0;
	state->error = 0;
	state->last_pid = 0;
	return (SUCCESS);
}

void	px_init_dup(t_prog *state)
{
	if (state->infile_fd > 0)
	{
		dup2(state->infile_fd, STDIN_FILENO);
		close(state->infile_fd);
	}
	if (state->outfile_fd > 0)
	{
		dup2(state->outfile_fd, STDOUT_FILENO);
		close(state->outfile_fd);
	}
}
