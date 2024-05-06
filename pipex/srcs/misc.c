/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:12:55 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/02/17 15:20:58 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	px_splittable_arg(t_cmds *new, char *av)
{
	new->args = ft_split(av, ' ');
	if (new->args == 0)
	{
		free(new);
		return (MALLOC_ERROR);
	}
	new->bin = new->args[0];
	return (EXIT_SUCCESS);
}

int	px_weird_arg(t_cmds *new, char *av)
{
	new->args = malloc(sizeof(char *) * 2);
	if (new->args == NULL)
	{
		free(new);
		return (MALLOC_ERROR);
	}
	new->bin = ft_strdup(av);
	if (new->bin == NULL)
	{
		free(new->args);
		free(new);
		return (MALLOC_ERROR);
	}
	new->args[0] = new->bin;
	new->args[1] = 0;
	return (EXIT_SUCCESS);
}

int	px_only_spaces(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] != 32)
			return (0);
		i++;
	}
	return (1);
}

void	px_error_msg(char *file)
{
	write(2, "pipex: ", 7);
	perror(file);
}

int	px_kill_switch(t_prog *state, int error)
{
	px_free_cmd_list(state, error);
	if (state->paths)
		ft_free_split(state->paths, error);
	if (state->limiter)
		free(state->limiter);
	if (state->here_doc_fd > 0)
		close(state->here_doc_fd);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	return (error);
}
