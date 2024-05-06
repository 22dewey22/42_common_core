/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwayenbo <dwayenbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:58:14 by dwayenbo          #+#    #+#             */
/*   Updated: 2024/02/17 17:08:58 by dwayenbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	px_parse_path(t_prog *state)
{
	int		i;
	char	**paths;

	i = 0;
	while (state->envp[i] && ft_strncmp(state->envp[i], "PATH=", 5) != 0)
		i++;
	if (state->envp[i])
	{
		paths = ft_split(state->envp[i] + 5, ':');
		if (!paths)
			return (MALLOC_ERROR);
		state->paths = paths;
		return (EXIT_SUCCESS);
	}
	else
	{
		state->paths = NULL;
		return (EXIT_SUCCESS);
	}
}

void	px_get_outfile(t_prog *state)
{
	state->outfile = state->av[state->ac - 1];
	if (state->here_doc)
		state->outfile_fd = open(state->outfile, O_CREAT | O_WRONLY | O_APPEND,
				S_IWUSR | S_IRUSR | S_IRGRP | S_IWGRP | S_IROTH);
	else
		state->outfile_fd = open(state->outfile, O_TRUNC | O_CREAT | O_WRONLY,
				S_IWUSR | S_IRUSR | S_IRGRP | S_IWGRP | S_IROTH);
}
